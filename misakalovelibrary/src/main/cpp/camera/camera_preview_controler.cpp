//
// Created by TY on 2018/7/19.
//

#include "camera_preview_controler.h"


CameraPreviewControler::CameraPreviewControler() {}

void CameraPreviewControler::prepareEGLContext(JavaVM *g_jvm, jobject obj, int screenWidth,
                                               int screenHeight, int cameraFacingId) {


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
                   cameraWidth, cameraHeight);
    this->startCameraPreview();

    isInSwitchingCamera = false;
    pauseFlag = false;
    continueFlag = false;
    LOGI("leave Initializing context");
}

void CameraPreviewControler::createPreviewSurface() {
    previewSurface= eglCore->createWindowSurface(window);
    if(previewSurface!= nullptr){
        eglCore->makeCurrent(previewSurface);
    }
}

void CameraPreviewControler::buildRenderInstance() {
    renderer=new CameraPreviewRender();
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
                                                          "(I)Lcom/changba/songstudio/recording/camera/preview/CameraConfigInfo;");
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

            textureWidth = 360;
            textureHeight = 640;
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

}
