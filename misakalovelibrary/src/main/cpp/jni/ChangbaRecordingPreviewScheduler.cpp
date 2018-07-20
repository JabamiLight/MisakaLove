
#include "com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler.h"

#define LOG_TAG "ChangbaRecordingPreviewScheduler"

CameraPreviewControler *previewController;

jobject g_obj;

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_startEncoding(JNIEnv *,
                                                                                         jobject,
                                                                                         jint, jint,
                                                                                         jint, jint,
                                                                                         jboolean,
                                                                                         jint) {

}

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_stopEncoding(JNIEnv *,
                                                                                        jobject) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchPreviewFilter(JNIEnv *,
                                                                                          jobject,
                                                                                          jint,
                                                                                          jobject,
                                                                                          jstring) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchPauseRecordingPreviewState(
        JNIEnv *, jobject) {

}

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchCommonPreviewState(
        JNIEnv *, jobject) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchCameraFacing(JNIEnv *,
                                                                                         jobject) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_prepareEGLContext(JNIEnv *env,
                                                                                        jobject obj,
                                                                                        jobject assetManager,
                                                                                        jint screenWidth,
                                                                                        jint screenHeight,
                                                                                        jint cameraFacingId) {
    previewController = new CameraPreviewControler();
    JavaVM *g_jvm = NULL;
    env->GetJavaVM(&g_jvm);
    g_obj = env->NewGlobalRef(obj);
    AssetReader::init(g_jvm, env->NewGlobalRef(assetManager));
    previewController->prepareEGLContext(g_jvm, g_obj, screenWidth, screenHeight,
                                         cameraFacingId);
}



void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_resetRenderSize(JNIEnv *env,
                                                                                      jobject instance,
                                                                                      jobject surface,
                                                                                      jint width,
                                                                                      jint height) {
    if (NULL != previewController) {
        ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
        previewController->resetRenderSize(window,width, height);
    }

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_notifyFrameAvailable(JNIEnv *,
                                                                                           jobject) {

    if (NULL != previewController) {
        previewController->notifyFrameAvailable();
    }
}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_createWindowObject(JNIEnv *,
                                                                                         jobject,
                                                                                         jobject) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_adaptiveVideoQuality(JNIEnv *,
                                                                                           jobject,
                                                                                           jint,
                                                                                           jint,
                                                                                           jint) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_hotConfigQuality(JNIEnv *,
                                                                                       jobject,
                                                                                       jint, jint,
                                                                                       jint) {

}

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_resetRenderSize(JNIEnv *,
                                                                                           jobject,
                                                                                           jint,
                                                                                           jint) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_destroyWindowObject(JNIEnv *,
                                                                                          jobject) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_destroyEGLContext(JNIEnv *,
                                                                                        jobject) {

}



void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_updateTexMatrix(JNIEnv *,
                                                                                           jobject,
                                                                                           jfloatArray) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_hotConfig(JNIEnv *, jobject,
                                                                                jint, jint, jint) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_setBeautifyParam(JNIEnv *,
                                                                                       jobject,
                                                                                       jint,
                                                                                       jfloat) {

}

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_destroyWindowSurface(
        JNIEnv *env, jobject instance) {

}

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_createWindowSurface(
        JNIEnv *env, jobject instance, jobject surface) {

}

