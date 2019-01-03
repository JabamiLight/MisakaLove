
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
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchPauseRecordingPreviewState(
        JNIEnv *, jobject) {

}

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchCommonPreviewState(
        JNIEnv *, jobject) {

}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchCameraFacing(JNIEnv *,
                                                                                         jobject) {
    if (NULL != previewController) {
        previewController->switchCameraFacing();
    }
}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_prepareEGLContext(JNIEnv *env,
                                                                                        jobject obj,
                                                                                        jobject surface,
                                                                                        jobject assetManager,
                                                                                        jint screenWidth,
                                                                                        jint screenHeight,
                                                                                        jint cameraFacingId) {
    previewController = new CameraPreviewControler();
    JavaVM *g_jvm = NULL;
    env->GetJavaVM(&g_jvm);
    g_obj = env->NewGlobalRef(obj);
    AssetReader::init(g_jvm, env->NewGlobalRef(assetManager));
    ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
    previewController->prepareEGLContext(window, g_jvm, g_obj, screenWidth, screenHeight,
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
        previewController->resetRenderSize(window, width, height);
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
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_destroyEGLContext(JNIEnv *env,
                                                                                        jobject) {


    if (NULL != previewController) {
        previewController->destroyEGLContext();
        delete previewController;
        previewController = NULL;
        if (g_obj != 0) {
            env->DeleteGlobalRef(g_obj);
            g_obj = 0;
        }
        AssetReader::destory();
    }
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
    if (NULL != previewController) {
        previewController->destroyWindowSurface();
    }

}

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_createWindowSurface(
        JNIEnv *env, jobject instance, jobject surface) {
    if (surface != NULL && NULL != previewController) {
        ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
        if (window != NULL) {
            previewController->createWindowSurface(window);
        }
    }
}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchPreviewFilter(
        JNIEnv *env,
        jobject instance,
        jint filterType) {
    if (previewController != nullptr) {
        previewController->switchPreviewFilter(filterType);
    }


}

void Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_setFaceInfo(JNIEnv *env,
                                                                                       jobject instance,
                                                                                       jint ID,
                                                                                       jint left,
                                                                                       jint top,
                                                                                       jint right,
                                                                                       jint bottom,
                                                                                       jint height,
                                                                                       jint width,
                                                                                       jintArray landmarks,
                                                                                       jboolean isValidate

) {

    if (!previewController) return;
    if (isValidate) {
        jint *points = env->GetIntArrayElements(landmarks, JNI_FALSE);
        previewController->setFaceInfo(ID, left, top, right, bottom, height, width, points);
        env->ReleaseIntArrayElements(landmarks, points, 0);
    } else {
        previewController->notFoundFaceInfo();
    }
}

void
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_setBeautyParams(JNIEnv *env,
                                                                                      jobject instance,
                                                                                      jint eyeProgress) {
    if (!previewController) return;
    previewController->setBeautyPara(eyeProgress);


}

