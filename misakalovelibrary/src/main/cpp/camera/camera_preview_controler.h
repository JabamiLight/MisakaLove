//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_CAMERAPREVIEWCONTROLER_H
#define MISAKALOVE_CAMERAPREVIEWCONTROLER_H

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "../message_queue/handler.h"
#include <EGL/eglplatform.h>
#include <EGL/egl.h>
#include "../libcommon/CommonTools.h"
#include "../libcommon/egl_core/egl_core.h"
#include "camera_preview_render.h"

#define LOG_TAG "CameraPreviewControler"
enum RenderThreadMessage {
    MSG_RENDER_FRAME = 0,
    MSG_EGL_THREAD_CREATE,
    MSG_EGL_CREATE_PREVIEW_SURFACE,
    MSG_SWITCH_CAMERA_FACING,
    MSG_SWITCH_FILTER,
    MSG_START_RECORDING,
    MSG_STOP_RECORDING,
    MSG_EGL_DESTROY_PREVIEW_SURFACE,
    MSG_EGL_THREAD_EXIT
};


class CameraPreviewControler {
public:
    CameraPreviewControler();
    void prepareEGLContext( JavaVM *g_jvm,
                           jobject obj, int screenWidth, int screenHeight,
                           int cameraFacingId);

    void initialize();

private:
    int screenWidth,screenHeight;
    ANativeWindow* window;
    JavaVM* g_jvm;
    //用于回调
    jobject obj;
    EGLCore *eglCore;
    CameraPreviewRender* renderer;

    void createPreviewSurface();

    void buildRenderInstance();

    void configCamera();

    void startCameraPreview();

    bool isInSwitchingCamera;
    bool pauseFlag;
    bool continueFlag;
    EGLSurface previewSurface;
    jint degress;
    jint facingId;
    int cameraWidth;
    int cameraHeight;
    int textureWidth;
    int textureHeight;
};


class CameraPreviewHandler : public Handler {
private:
    CameraPreviewControler *previewController;

public:
    CameraPreviewHandler(CameraPreviewControler *previewController, MessageQueue *queue)
            :
            Handler(queue) {
        this->previewController = previewController;
    }

    void handleMessage(Message *msg) {
        int what = msg->getWhat();
        switch (what) {
            case MSG_EGL_THREAD_CREATE:
                previewController->initialize();
                break;
            case MSG_EGL_CREATE_PREVIEW_SURFACE:
                previewController->createPreviewSurface();
                break;
//            case MSG_SWITCH_CAMERA_FACING:
//                previewController->switchCamera();
//                break;
//            case MSG_SWITCH_FILTER:
//                previewController->switchFilter();
//                break;
//            case MSG_START_RECORDING:
//                previewController->startRecording();
//                break;
//            case MSG_STOP_RECORDING:
//                previewController->stopRecording();
//                break;
//            case MSG_EGL_DESTROY_PREVIEW_SURFACE:
//                previewController->destroyPreviewSurface();
//                break;
//            case MSG_EGL_THREAD_EXIT:
//                previewController->destroy();
//                break;
            case MSG_RENDER_FRAME:
                previewController->renderFrame();
                break;
        }
    }
};

#endif //MISAKALOVE_CAMERAPREVIEWCONTROLER_H