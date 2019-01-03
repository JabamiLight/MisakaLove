//
// Created by TY on 2018/7/19.
//

#include "camera_preview_controler.h"

#define LOG_TAG "CameraPreviewControler"


CameraPreviewControler::CameraPreviewControler() {

    LOGI("MVRecordingPreviewController instance created");
    facingId = CAMERA_FACING_FRONT;
//    filterType = 0;
//    startTime = -1;
    eglCore = NULL;
    _window = NULL;
//    encoder = NULL;
    previewSurface = EGL_NO_SURFACE;
//    isEncoding = false;
    queue = new MessageQueue("MVRecordingPreviewController message queue");
    handler = new CameraPreviewHandler(this, queue);
}


void
CameraPreviewControler::prepareEGLContext(ANativeWindow *_window, JavaVM *g_jvm, jobject obj,
                                          jint screenWidth, jint screenHeight,
                                          jint cameraFacingId) {
    LOGI("Creating MVRecordingPreviewController thread");
    this->g_jvm = g_jvm;
    this->obj = obj;
    this->_window = _window;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->facingId = cameraFacingId;
    handler->postMessage(new Message(MSG_EGL_THREAD_CREATE));
    pthread_create(&_threadId, 0, threadStartCallback, this);

}


void CameraPreviewControler::initialize() {
    const EGLint attribs[] = {EGL_BUFFER_SIZE, 32, EGL_ALPHA_SIZE, 8, EGL_BLUE_SIZE, 8,
                              EGL_GREEN_SIZE, 8, EGL_RED_SIZE, 8, EGL_RENDERABLE_TYPE,
                              EGL_OPENGL_ES2_BIT,
                              EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_NONE};
    LOGI("Initializing context");
    eglCore = new EGLCore();
    eglCore->init();
    this->createPreviewSurface();
    this->buildRenderInstance();
    this->configCamera();
    renderer->init(degress, facingId == CAMERA_FACING_FRONT, textureWidth, textureHeight,
                   cameraWidth, cameraHeight, screenWidth, screenHeight);
    this->startCameraPreview();
    isInSwitchingCamera = false;
    pauseFlag = false;
    continueFlag = false;
    LOGI("leave Initializing context");
}

void CameraPreviewControler::createPreviewSurface() {
    previewSurface = eglCore->createWindowSurface(_window);
    if (previewSurface != nullptr) {
        eglCore->makeCurrent(previewSurface);
    }
}

void CameraPreviewControler::buildRenderInstance() {
    renderer = new CameraPreviewRender();
}

void CameraPreviewControler::configCamera() {
    LOGI("MVRecordingPreviewController::configCamera");
    JNIEnv *env;
    if (g_jvm->AttachCurrentThread(&env, NULL) != JNI_OK) {
        LOGE("%s: AttachCurrentThread() failed", __FUNCTION__);
        return;
    }
    if (env == NULL) {
        LOGI("getJNIEnv failed");
        return;
    }
    jclass jcls = env->GetObjectClass(obj);
    if (NULL != jcls) {
        jmethodID configCameraCallback = env->GetMethodID(jcls, "configCameraFromNative",
                                                          "(I)Lcom/ty/misakalovelibrary/camera/CameraConfigInfo;");
        if (NULL != configCameraCallback) {
            jobject cameraConfigInfo = env->CallObjectMethod(obj, configCameraCallback, facingId);
            jclass cls_CameraConfigInfo = env->GetObjectClass(cameraConfigInfo);
            jmethodID cameraConfigInfo_getDegress = env->GetMethodID(cls_CameraConfigInfo,
                                                                     "getDegress", "()I");
            degress = env->CallIntMethod(cameraConfigInfo, cameraConfigInfo_getDegress);

            jmethodID cameraConfigInfo_getCameraFacingId = env->GetMethodID(cls_CameraConfigInfo,
                                                                            "getCameraFacingId",
                                                                            "()I");
            facingId = env->CallIntMethod(cameraConfigInfo, cameraConfigInfo_getCameraFacingId);

            jmethodID cameraConfigInfo_getTextureWidth = env->GetMethodID(cls_CameraConfigInfo,
                                                                          "getTextureWidth", "()I");
            int previewWidth = env->CallIntMethod(cameraConfigInfo,
                                                  cameraConfigInfo_getTextureWidth);
            jmethodID cameraConfigInfo_getTextureHeight = env->GetMethodID(cls_CameraConfigInfo,
                                                                           "getTextureHeight",
                                                                           "()I");
            int previewHeight = env->CallIntMethod(cameraConfigInfo,
                                                   cameraConfigInfo_getTextureHeight);

            this->cameraWidth = previewWidth;
            this->cameraHeight = previewHeight;

//			int previewMin = MIN(previewWidth, previewHeight);
//			textureWidth = previewMin >= 480 ? 480 : previewMin;
//			textureHeight = textureWidth;

            textureWidth = cameraWidth;
            textureHeight = cameraHeight;
//			textureWidth = 720;
//			textureHeight = 1280;
            LOGI("camera : {%d, %d}", previewWidth, previewHeight);
            LOGI("Texture : {%d, %d}", textureWidth, textureHeight);
        }
    }
    if (g_jvm->DetachCurrentThread() != JNI_OK) {
        LOGE("%s: DetachCurrentThread() failed", __FUNCTION__);
        return;
    }

}

void CameraPreviewControler::startCameraPreview() {
    LOGI("MVRecordingPreviewController::setCameraPreviewTexture");
    JNIEnv *env;
    if (g_jvm->AttachCurrentThread(&env, NULL) != JNI_OK) {
        LOGE("%s: AttachCurrentThread() failed", __FUNCTION__);
        return;
    }
    if (env == NULL) {
        LOGI("getJNIEnv failed");
        return;
    }
    jclass jcls = env->GetObjectClass(obj);
    if (NULL != jcls) {
        jmethodID startPreviewCallback = env->GetMethodID(jcls, "startPreviewFromNative", "(I)V");
        if (NULL != startPreviewCallback) {
            env->CallVoidMethod(obj, startPreviewCallback, renderer->getCameraTexId());
        }
    }
    if (g_jvm->DetachCurrentThread() != JNI_OK) {
        LOGE("%s: DetachCurrentThread() failed", __FUNCTION__);
        return;
    }
}

inline int fps() {
    static int fps = 0;
    static int lastTime = getCurrentTime(); // ms
    static int frameCount = 0;

    ++frameCount;

    int curTime = getCurrentTime();
    if (curTime - lastTime > 1000) // 取固定时间间隔为1秒
    {
        fps = frameCount;
        frameCount = 0;
        lastTime = curTime;
    }
    return fps;
}

void CameraPreviewControler::renderFrame() {
    updateTexImage();
    if (previewSurface != EGL_NO_SURFACE) {
        draw();
    }
}


void CameraPreviewControler::draw() {
    eglCore->makeCurrent(previewSurface);
    renderer->render();
    if (!eglCore->swapBuffers(previewSurface)) {
        LOGE("eglSwapBuffers(previewSurface) returned error %d", eglGetError());
    }

}

void CameraPreviewControler::resetRenderSize(ANativeWindow *window, jint screenWidth,
                                             jint screenHeight) {
    this->_window = window;
    LOGI("MVRecordingPreviewController::resetSize screenWidth:%d; screenHeight:%d", screenWidth,
         screenHeight);
    if (this->screenHeight != screenHeight || this->screenWidth != screenWidth) {
        this->screenWidth = screenWidth;
        this->screenHeight = screenHeight;
        renderer->resetSize(screenWidth, screenHeight);
        handler->postMessage(new Message(MSG_EGL_CREATE_PREVIEW_SURFACE));
    }

}

void *CameraPreviewControler::threadStartCallback(void *myself) {
    CameraPreviewControler *previewController = (CameraPreviewControler *) myself;
    previewController->processMessage();
    pthread_exit(0);
}

void CameraPreviewControler::processMessage() {
    bool renderingEnabled = true;
    while (renderingEnabled) {
        Message *msg = NULL;
        if (queue->dequeueMessage(&msg, true) > 0) {
            if (MESSAGE_QUEUE_LOOP_QUIT_FLAG == msg->execute()) {
                renderingEnabled = false;
            }
            delete msg;
        }
    }
}

void CameraPreviewControler::notifyFrameAvailable() {
    if (handler && !isInSwitchingCamera)
        handler->postMessage(new Message(MSG_RENDER_FRAME));
}

void CameraPreviewControler::updateTexImage() {
    JNIEnv *env;
    if (g_jvm->AttachCurrentThread(&env, NULL) != JNI_OK) {
        LOGE("%s: AttachCurrentThread() failed", __FUNCTION__);
        return;
    }
    if (env == NULL) {
        LOGI("getJNIEnv failed");
        return;
    }
    jclass jcls = env->GetObjectClass(obj);
    if (NULL != jcls) {
        jmethodID updateTexImageCallback = env->GetMethodID(jcls, "updateTexImageFromNative",
                                                            "()V");
        if (NULL != updateTexImageCallback) {
            env->CallVoidMethod(obj, updateTexImageCallback);
        }
    }
    if (g_jvm->DetachCurrentThread() != JNI_OK) {
        LOGE("%s: DetachCurrentThread() failed", __FUNCTION__);
    }
}

void CameraPreviewControler::destroyWindowSurface() {
    LOGI("enter MVRecordingPreviewController::destroyWindowSurface");
    if (handler)
        handler->postMessage(new Message(MSG_EGL_DESTROY_PREVIEW_SURFACE));
}

void CameraPreviewControler::destroy() {
    LOGI("enter MVRecordingPreviewController::destroy...");
    this->destroyPreviewSurface();
    if (renderer) {
        renderer->destory();
        delete renderer;
        renderer = NULL;
    }
    this->releaseCamera();
    eglCore->release();
    delete eglCore;
    eglCore = NULL;
    if(face){
        delete face;
        face= nullptr;
    }
    LOGI("leave MVRecordingPreviewController::destroy...");
}

void CameraPreviewControler::destroyPreviewSurface() {
    if (EGL_NO_SURFACE != previewSurface) {
        eglCore->releaseSurface(previewSurface);
        previewSurface = EGL_NO_SURFACE;
        if (_window) {
            LOGI("VideoOutput Releasing surfaceWindow");
            ANativeWindow_release(_window);
            _window = NULL;
        }
    }
}

void CameraPreviewControler::releaseCamera() {
    LOGI("MVRecordingPreviewController::releaseCamera");
    JNIEnv *env;
    if (g_jvm->AttachCurrentThread(&env, NULL) != JNI_OK) {
        LOGE("%s: AttachCurrentThread() failed", __FUNCTION__);
        return;
    }
    if (env == NULL) {
        LOGI("getJNIEnv failed");
        return;
    }
    jclass jcls = env->GetObjectClass(obj);
    if (NULL != jcls) {
        jmethodID releaseCameraCallback = env->GetMethodID(jcls, "releaseCameraFromNative",
                                                           "()V");
        if (NULL != releaseCameraCallback) {
            env->CallVoidMethod(obj, releaseCameraCallback);
        }
    }
    if (g_jvm->DetachCurrentThread() != JNI_OK) {
        LOGE("%s: DetachCurrentThread() failed", __FUNCTION__);
        return;
    }

}

void CameraPreviewControler::destroyEGLContext() {
    LOGI("Stopping MVRecordingPreviewController thread");
    if (handler) {
        handler->postMessage(new Message(MSG_EGL_THREAD_EXIT));
        handler->postMessage(new Message(MESSAGE_QUEUE_LOOP_QUIT_FLAG));
    }
    pthread_join(_threadId, 0);
    if (queue) {
        queue->abort();
        delete queue;
        queue = NULL;
    }
    delete handler;
    handler = NULL;
    LOGI("MVRecordingPreviewController thread stopped");

}

void CameraPreviewControler::switchCameraFacing() {
    LOGI("MVRecordingPreviewController::refereshCameraFacing");
    isInSwitchingCamera = true;
    /*notify render thread that camera has changed*/
    if (facingId == CAMERA_FACING_BACK) {
        facingId = CAMERA_FACING_FRONT;
    } else {
        facingId = CAMERA_FACING_BACK;
    }
    if (handler)
        handler->postMessage(new Message(MSG_SWITCH_CAMERA_FACING));
    LOGI("leave MVRecordingPreviewController::refereshCameraFacing");
}

void CameraPreviewControler::switchCamera() {
    this->releaseCamera();
    this->configCamera();
    renderer->setDegree(degress, facingId == CAMERA_FACING_FRONT);
    this->startCameraPreview();
    isInSwitchingCamera = false;
}

void CameraPreviewControler::createWindowSurface(ANativeWindow *window) {
    LOGI("enter MVRecordingPreviewController::createWindowSurface");
    if (this->_window == NULL) {
        this->_window = window;
        if (handler)
            handler->postMessage(new Message(MSG_EGL_CREATE_PREVIEW_SURFACE));
    }

}

void CameraPreviewControler::switchFilter() {
    renderer->switchFilter(filterType);
}

void CameraPreviewControler::switchPreviewFilter(uint filterType) {
    this->filterType = filterType;
    if (handler)
        handler->postMessage(new Message(MSG_SWITCH_FILTER));

}

void
CameraPreviewControler::setFaceInfo(int ID, int left, int top, int right, int bottom,
                                    int height,
                                    int width, int *landmarks) {

    if (face == nullptr) {
        face = new Face();
    }
    face->ID = ID;
    face->left = left;
    face->top = top;
    face->right = right;
    face->bottom = bottom;
    face->height = height;
    face->width = width;
    face->cameraWidth = cameraWidth;
    face->cameraHeight = cameraHeight;
    face->points = new Pointf[106];
    face->isInvalid = true;
    for (int i = 0; i < 106; i++) {
        face->points[i].x = landmarks[i * 2];
        face->points[i].y = landmarks[i * 2 + 1];
    }
    if (degress == 270) {
        for (int i = 0; i < 106; i++) {
            face->points[i].x = face->points[i].x;
        }
    } else {

    }
    renderer->setFaceInfo(face);

}

void CameraPreviewControler::setFaceInfo() {
    renderer->setFaceInfo(face);
}


void CameraPreviewControler::readCurFaceInfo() {
    JNIEnv *env;
    if (g_jvm->AttachCurrentThread(&env, NULL) != JNI_OK) {
        LOGE("%s: AttachCurrentThread() failed", __FUNCTION__);
        return;
    }
    if (env == NULL) {
        LOGI("getJNIEnv failed");
        return;
    }
    jclass jcls = env->GetObjectClass(obj);
    if (NULL != jcls) {
        jmethodID updateTexImageCallback = env->GetMethodID(jcls, "readCurFaceInfo",
                                                            "()V");
        if (NULL != updateTexImageCallback) {
            env->CallVoidMethod(obj, updateTexImageCallback);
        }
    }
    if (g_jvm->DetachCurrentThread() != JNI_OK) {
        LOGE("%s: DetachCurrentThread() failed", __FUNCTION__);
    }
}

void CameraPreviewControler::notFoundFaceInfo() {
    if (face == nullptr) {
        face = new Face();
    }
    face->isInvalid = false;
    renderer->setFaceInfo(face);
}

void CameraPreviewControler::setBeautyPara(int i) {
    para.eyeScale=0.2f*i/100;
    if (handler)
        handler->postMessage(new Message(MSG_SET_BEAUTY_PARA));
}

void CameraPreviewControler::setBeautyPara() {
    renderer->setBeautyPara(para.eyeScale);
}

