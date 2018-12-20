package com.ty.misakalovelibrary.camera;

import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.ImageFormat;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.PointF;
import android.graphics.PorterDuff;
import android.graphics.Rect;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.hardware.Camera.CameraInfo;
import android.hardware.Camera.Parameters;
import android.hardware.Camera.Size;
import android.os.Build;
import android.os.Handler;
import android.os.HandlerThread;
import android.os.Message;
import android.util.Log;
import android.view.Surface;

import com.ty.misakalovelibrary.camera.exception.CameraParamSettingException;
import com.ty.misakalovelibrary.widget.FloatingCameraWindow;
import com.zeusee.zmobileapi.STUtils;

import java.lang.reflect.Field;
import java.util.List;

import zeusees.tracking.Face;
import zeusees.tracking.FaceTracking;


public class ChangbaVideoCamera {
    private static final String TAG = "ChangbaVideoCamera";
    private static final int MESSAGE_DRAW_POINTS = 100;
    public static int VIDEO_WIDTH = 720;
    public static int DEFAULT_VIDEO_WIDTH = 720;
    public static int VIDEO_HEIGHT = 1280;
    public static int DEFAULT_VIDEO_HEIGHT = 1280;
    public static int videoFrameRate = 24;
    //几个赋值的buffer
    private byte[] mPreBuffer;//首先分配一块内存作为缓冲区，size的计算方式见第四点中
    private byte[] mNv21Data;
    private byte[] mTmpBuffer;
    private Bitmap mCroppedBitmap;
    private FloatingCameraWindow mWindow;
    Matrix matrix = new Matrix();
    private HandlerThread mHandlerThread;
    private Object lockObj = new Object();
    private Handler mHandler;
    private FaceTracking mMultiTrack106 = null;
    private int frameIndex;
    private Paint mPaint=new Paint();

    private Camera mCamera;
    private SurfaceTexture mCameraSurfaceTexture;
    private Context mContext;


    public static void forcePreviewSize_640_480() {
        VIDEO_WIDTH = 640;
        VIDEO_HEIGHT = 480;
        videoFrameRate = 15;
    }

    public static void forcePreviewSize_1280_720() {
        VIDEO_WIDTH = 1280;
        VIDEO_HEIGHT = 720;
        videoFrameRate = 24;
    }


    public ChangbaVideoCamera(Context context) {
        this.mContext = context;
    }

    public Camera getCamera() {
        return mCamera;
    }

    public CameraConfigInfo configCameraFromNative(int cameraFacingId) {
        if (null != mCamera) {
            releaseCamera();
        }
        if (cameraFacingId >= getNumberOfCameras()) {
            cameraFacingId = 0;
        }
        try {
            return setUpCamera(cameraFacingId);
        } catch (CameraParamSettingException e) {
            mCallback.onPermissionDismiss(e.getMessage());
        }
        int degress = 270;
        int previewWidth = VIDEO_WIDTH;
        int previewHeight = VIDEO_HEIGHT;
        if (null != mCamera) {
            try {
                Size previewSize = mCamera.getParameters().getPreviewSize();
                previewWidth = previewSize.width;
                previewHeight = previewSize.height;
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        return new CameraConfigInfo(degress, previewWidth, previewHeight, cameraFacingId);
    }

    @TargetApi(Build.VERSION_CODES.JELLY_BEAN)
    public void setCameraPreviewTexture(int textureId) {
        Log.i(TAG, "setCameraPreviewTexture..." + textureId);
        mCameraSurfaceTexture = new SurfaceTexture(textureId);
        try {
            mCamera.setPreviewTexture(mCameraSurfaceTexture);
            mCameraSurfaceTexture.setOnFrameAvailableListener(new SurfaceTexture.OnFrameAvailableListener() {
                @Override
                public void onFrameAvailable(SurfaceTexture surfaceTexture) {
                    if (null != mCallback) {
//						Log.d("RecordingPublisher", "surfaceTexture time stamp is "+surfaceTexture
// .getTimestamp()/1000000000.0f);
                        mCallback.notifyFrameAvailable();
                    }
                }
            });
            mCamera.addCallbackBuffer(mPreBuffer);
            mCamera.setPreviewCallbackWithBuffer(new Camera.PreviewCallback() {
                @Override
                public void onPreviewFrame(byte[] data, Camera camera) {
                    synchronized (mNv21Data) {
                        System.arraycopy(data, 0, mNv21Data, 0, data.length);
                    }

                    mHandler.removeMessages(MESSAGE_DRAW_POINTS);
                    mHandler.sendEmptyMessage(MESSAGE_DRAW_POINTS);
                    mCamera.addCallbackBuffer(mPreBuffer);
                }
            });
            mCamera.startPreview();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @TargetApi(Build.VERSION_CODES.HONEYCOMB)
    public void updateTexImage() {
        // Log.i(TAG, "updateTexImage...");
        try {
            if (null != mCameraSurfaceTexture) {
                mCameraSurfaceTexture.updateTexImage();

                //去掉这个没用的调用
//				float[] mTmpMatrix = new float[16];
//				mCameraSurfaceTexture.getTransformMatrix(mTmpMatrix);
//				
//				if (null != mCallback) {
//					mCallback.updateTexMatrix(mTmpMatrix);
//				}
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public int getNumberOfCameras() {
        return Camera.getNumberOfCameras();
    }

    @TargetApi(Build.VERSION_CODES.ICE_CREAM_SANDWICH)
    public void releaseCamera() {
        try {
            if (mCameraSurfaceTexture != null) {
                // this causes a bunch of warnings that appear harmless but might
                // confuse someone:
                // W BufferQueue: [unnamed-3997-2] cancelBuffer: BufferQueue has
                // been abandoned!
                mCameraSurfaceTexture.release();
                mCameraSurfaceTexture = null;
            }
            if (null != mCamera) {
                mCamera.setPreviewCallback(null);
                mCamera.setFaceDetectionListener(null);
                mCamera.stopPreview();
                mCamera.release();
                mCamera = null;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @TargetApi(Build.VERSION_CODES.ICE_CREAM_SANDWICH)
    private CameraConfigInfo setUpCamera(final int id) throws CameraParamSettingException {
//		 forcePreviewSize_640_480();
        forcePreviewSize_1280_720();
        // printStackTrace(CameraLoader.class);
        try {
            // 1、开启Camera
            try {
                mCamera = getCameraInstance(id);
            } catch (CameraParamSettingException e) {
                throw e;
            }
            boolean mHasPermission = hasPermission();
            if (!mHasPermission) {
                throw new CameraParamSettingException("拍摄权限被禁用或被其他程序占用, 请确认后再录制");
            }
            Parameters parameters = mCamera.getParameters();

            // 2、设置预览照片的图像格式
            List<Integer> supportedPreviewFormats = parameters.getSupportedPreviewFormats();
            if (supportedPreviewFormats.contains(ImageFormat.NV21)) {
                parameters.setPreviewFormat(ImageFormat.NV21);
            } else {
                throw new CameraParamSettingException("视频参数设置错误:设置预览图像格式异常");
            }
            initBufferAndDetect(parameters);

            // 3、设置预览照片的尺寸
            List<Size> supportedPreviewSizes = parameters.getSupportedPreviewSizes();
            int previewWidth = VIDEO_WIDTH;
            int previewHeight = VIDEO_HEIGHT;
            boolean isSupportPreviewSize = isSupportPreviewSize(supportedPreviewSizes, previewWidth,
                    previewHeight);

            if (isSupportPreviewSize) {
                parameters.setPreviewSize(previewWidth, previewHeight);
            } else {
                previewWidth = DEFAULT_VIDEO_WIDTH;
                previewHeight = DEFAULT_VIDEO_HEIGHT;
                isSupportPreviewSize = isSupportPreviewSize(
                        supportedPreviewSizes, previewWidth, previewHeight);
                if (isSupportPreviewSize) {
                    VIDEO_WIDTH = DEFAULT_VIDEO_WIDTH;
                    VIDEO_HEIGHT = DEFAULT_VIDEO_HEIGHT;
                    parameters.setPreviewSize(previewWidth, previewHeight);
                } else {
                    throw new CameraParamSettingException("视频参数设置错误:设置预览的尺寸异常");
                }
            }
            //下面这行设置 有可能导致 返回的图像尺寸和预期不一致
//			parameters.setRecordingHint(true);

            // 4、设置视频记录的连续自动对焦模式
            if (parameters.getSupportedFocusModes().contains(Camera.Parameters.FOCUS_MODE_CONTINUOUS_VIDEO)) {
                parameters.setFocusMode(Camera.Parameters.FOCUS_MODE_CONTINUOUS_VIDEO);
            }
            int degress = getCameraDisplayOrientation((Activity) mContext, id);
            try {
                mCamera.setParameters(parameters);
            } catch (Exception e) {
                throw new CameraParamSettingException("视频参数设置错误");
            }

            int cameraFacing = getCameraFacing(id);
            return new CameraConfigInfo(degress, previewWidth, previewHeight, cameraFacing);
        } catch (Exception e) {
            throw new CameraParamSettingException(e.getMessage());
        }

    }

    private void initBufferAndDetect(Parameters parameters) {
        mPreBuffer = new byte[DEFAULT_VIDEO_WIDTH * DEFAULT_VIDEO_HEIGHT * ImageFormat.getBitsPerPixel
                (parameters.getPreviewFormat()) / 8];
        mNv21Data = new byte[DEFAULT_VIDEO_WIDTH * DEFAULT_VIDEO_HEIGHT * ImageFormat.getBitsPerPixel
                (parameters.getPreviewFormat()) / 8];
        mTmpBuffer=new byte[DEFAULT_VIDEO_WIDTH * DEFAULT_VIDEO_HEIGHT * ImageFormat.getBitsPerPixel
                (parameters.getPreviewFormat()) / 8];
        mCroppedBitmap=Bitmap.createBitmap(DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT, Bitmap.Config.ARGB_8888);
        mMultiTrack106 = new FaceTracking(mContext, "/sdcard/ZeuseesFaceTracking/models");
        mHandlerThread = new HandlerThread("DrawFacePointsThread");
        mHandlerThread.start();
        mHandler = new Handler(mHandlerThread.getLooper()) {
            @Override
            public void handleMessage(Message msg) {
                if (msg.what == MESSAGE_DRAW_POINTS) {
                    synchronized (lockObj) {
//                        handleDrawPoints();
                    }
                }
            }
        };
    }

    private void handleDrawPoints() {

        synchronized (mNv21Data) {
//            System.arraycopy(NV21_mirror(mNv21Data, PREVIEW_WIDTH, PREVIEW_HEIGHT), 0, mTmpBuffer, 0, mNv21Data.length);
            System.arraycopy(mNv21Data, 0, mTmpBuffer, 0, mNv21Data.length);
        }

        if (frameIndex == 0) {
            mMultiTrack106.FaceTrackingInit(mTmpBuffer, DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT);
        } else {
            mMultiTrack106.Update(mTmpBuffer, DEFAULT_VIDEO_WIDTH, DEFAULT_VIDEO_HEIGHT);
        }
        frameIndex++;
        List<Face> faceActions = mMultiTrack106.getTrackingInfo();

        if (faceActions != null) {

            Canvas canvas = new Canvas(mCroppedBitmap);

            canvas.drawColor(0, PorterDuff.Mode.CLEAR);
            canvas.setMatrix(matrix);
            boolean rotate270 = true;
//            boolean rotate270 = mCameraInfo.orientation == 270;
            for (Face r : faceActions) {

                Rect rect = new Rect(DEFAULT_VIDEO_HEIGHT - r.left, r.top, DEFAULT_VIDEO_HEIGHT - r.right, r.bottom);

                PointF[] points = new PointF[106];
                for (int i = 0; i < 106; i++) {
                    points[i] = new PointF(r.landmarks[i * 2], r.landmarks[i * 2 + 1]);


                }

                float[] visibles = new float[106];


                for (int i = 0; i < points.length; i++) {
                    visibles[i] = 1.0f;


                    if (rotate270) {
                        points[i].x = DEFAULT_VIDEO_HEIGHT - points[i].x;

                    }

                }

                STUtils.drawFaceRect(canvas, rect, DEFAULT_VIDEO_HEIGHT,
                        DEFAULT_VIDEO_WIDTH, true);
                STUtils.drawPoints(canvas, mPaint, points, visibles, DEFAULT_VIDEO_HEIGHT,
                        DEFAULT_VIDEO_WIDTH, true);

                if(mWindow==null){
                    mWindow=new FloatingCameraWindow(mContext);
                }
                mWindow.setRGBBitmap(mCroppedBitmap);
            }
        }
    }

    private boolean hasPermission() {
        boolean mHasPermission = true;
        if (null == mCamera) {
            mHasPermission = false;
        } else {
            try {
                Class<? extends Camera> class1 = mCamera.getClass();
                Field filed = class1.getDeclaredField("mHasPermission");
                if (null != filed) {
                    filed.setAccessible(true);
                    mHasPermission = (Boolean) filed.get(mCamera);
                }
            } catch (Exception e1) {
            }

        }
        return mHasPermission;
    }

    private boolean isSupportPreviewSize(List<Size> supportedPreviewSizes, int previewWidth, int
            previewHeight) {
        boolean isSupportPreviewSize = false;
        for (Size size : supportedPreviewSizes) {
            if (previewWidth == size.width && previewHeight == size.height) {
                isSupportPreviewSize = true;
                break;
            }
        }
        return isSupportPreviewSize;
    }

    /**
     * A safe way to get an instance of the Camera object.
     */
    private Camera getCameraInstance(final int id) throws CameraParamSettingException {
        Log.i("problem", "getCameraInstance id is" + id);
        Camera c = null;
        try {
            c = Camera.open(id);
        } catch (Exception e) {
            throw new CameraParamSettingException("拍摄权限被禁用或被其他程序占用, 请确认后再录制");
        }
        return c;
    }

    public static int getCameraFacing(final int cameraId) {
        int result;
        CameraInfo info = new CameraInfo();
        Camera.getCameraInfo(cameraId, info);
        if (info.facing == Camera.CameraInfo.CAMERA_FACING_FRONT) {
            result = 1;
        } else { // back-facing
            result = 0;
        }
        return result;
    }

    public static int getCameraDisplayOrientation(final Activity activity, final int cameraId) {
        int rotation = activity.getWindowManager().getDefaultDisplay().getRotation();
        int degrees = 0;
        switch (rotation) {
            case Surface.ROTATION_0:
                degrees = 0;
                break;
            case Surface.ROTATION_90:
                degrees = 90;
                break;
            case Surface.ROTATION_180:
                degrees = 180;
                break;
            case Surface.ROTATION_270:
                degrees = 270;
                break;
        }
        int result;
        CameraInfo info = new CameraInfo();
        Camera.getCameraInfo(cameraId, info);
        if (info.facing == Camera.CameraInfo.CAMERA_FACING_FRONT) {
            result = (info.orientation + degrees) % 360;
        } else { // back-facing
            result = (info.orientation - degrees + 360) % 360;
        }

        return result;
    }

    private ChangbaVideoCameraCallback mCallback;

    public interface ChangbaVideoCameraCallback {
        public void onPermissionDismiss(String tip);

        public void notifyFrameAvailable();

        public void updateTexMatrix(float texMatrix[]);
    }

    public void setCallback(ChangbaVideoCameraCallback callback) {
        this.mCallback = callback;
    }
}
