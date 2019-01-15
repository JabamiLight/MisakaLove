/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "../camera/camera_preview_controler.h"

/* Header for class com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler */

#ifndef _Included_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
#define _Included_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
#ifdef __cplusplus
extern "C" {
#endif

#define JNI_METHOD(METHOD_NAME) \
JNICALL  Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_##METHOD_NAME

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    startEncoding
 * Signature: (IIIIZI)V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_startEncoding
        (JNIEnv *, jobject, jint, jint, jint, jint, jboolean, jint);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    stopEncoding
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_stopEncoding
        (JNIEnv *, jobject);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    switchPreviewFilter
 * Signature: (ILjava/lang/Object;Ljava/lang/String;)V
 */

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    switchPauseRecordingPreviewState
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchPauseRecordingPreviewState
        (JNIEnv *, jobject);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    switchCommonPreviewState
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchCommonPreviewState
        (JNIEnv *, jobject);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    switchCameraFacing
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchCameraFacing
        (JNIEnv *, jobject);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    prepareEGLContext
 * Signature: (Ljava/lang/Object;III)V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_prepareEGLContext
        (JNIEnv *, jobject, jobject, jobject, jint, jint, jint);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    createWindowObject
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_createWindowObject
        (JNIEnv *, jobject, jobject);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    adaptiveVideoQuality
 * Signature: (III)V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_adaptiveVideoQuality
        (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    hotConfigQuality
 * Signature: (III)V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_hotConfigQuality
        (JNIEnv *, jobject, jint, jint, jint);


/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    destroyWindowObject
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_destroyWindowObject
        (JNIEnv *, jobject);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    destroyEGLContext
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_destroyEGLContext
        (JNIEnv *, jobject);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    notifyFrameAvailable
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_notifyFrameAvailable
        (JNIEnv *, jobject);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    updateTexMatrix
 * Signature: ([F)V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_updateTexMatrix
        (JNIEnv *, jobject, jfloatArray);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    hotConfig
 * Signature: (III)V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_hotConfig
        (JNIEnv *, jobject, jint, jint, jint);

/*
 * Class:     com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler
 * Method:    setBeautifyParam
 * Signature: (IF)V
 */
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_setBeautifyParam
        (JNIEnv *, jobject, jint, jfloat);

JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_destroyWindowSurface(
        JNIEnv *env, jobject instance);


JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_createWindowSurface(
        JNIEnv *env, jobject instance, jobject surface);

JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_resetRenderSize(JNIEnv *env,
                                                                                      jobject instance,
                                                                                      jobject surface,
                                                                                      jint width,
                                                                                      jint height);
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_switchPreviewFilter(
        JNIEnv *env,
        jobject instance,
        jint height);
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_setFaceInfo(
        JNIEnv *env,
        jobject instance,
        jint ID,
        jint left,
        jint top,
        jint right,
        jint bottom,
        jint height,
        jint width,
        jintArray landmarks,
        jboolean invalidate
) ;
JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_setEyePara(
        JNIEnv *env,
        jobject instance,
        jint eyeProgress
) ;

JNIEXPORT void JNICALL
Java_com_ty_misakalovelibrary_camera_ChangbaRecordingPreviewScheduler_setFacePara(
        JNIEnv *env,
        jobject instance,
        jint faceProgress
) ;


//JNIEXPORT void JNI_METHOD(switchPreviewFilte23r)(JNIEnv *env, jobject instance, jint filterType) ;





#ifdef __cplusplus
}
#endif
#endif
