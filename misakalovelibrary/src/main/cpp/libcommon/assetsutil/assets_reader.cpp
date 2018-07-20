//
// Created by TY on 2018/7/19.
//

#include "assets_reader.h"


JavaVM* AssetReader::g_jvm = nullptr;
jobject AssetReader::assetManager = nullptr;
void
AssetReader::readSource(const char *vertexFilePath, const char *fragFilePath, char *&vertexContent,
                        char *&fragContent) {
    int status;
    JNIEnv *env;
    bool isAttached = false;
    status = AssetReader::g_jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (status < 0) {
        AssetReader::g_jvm->AttachCurrentThread(&env, NULL);//将当前线程注册到虚拟机中．
        isAttached = true;
    }
    LOGI("ReadAssets");
    AAssetManager *mgr = AAssetManager_fromJava(env, AssetReader::assetManager);
    if (mgr == NULL) {
        LOGI(" %s", "AAssetManager==NULL");
        return;
    }
    AAsset *assetVertex = AAssetManager_open(mgr, vertexFilePath, AASSET_MODE_BUFFER);
    if (assetVertex == NULL) {
        LOGI(" %s", "asset==NULL");
        return;
    }
    mallocContent(assetVertex, vertexContent);
    AAsset *assetFrag = AAssetManager_open(mgr, fragFilePath, AASSET_MODE_BUFFER);
    if (assetFrag == NULL) {
        LOGI(" %s", "asset==NULL");
        return;
    }
    mallocContent(assetFrag, fragContent);
    if (isAttached)
        AssetReader::g_jvm->DetachCurrentThread();
}


void AssetReader::init(JavaVM *g_jvm, jobject assetManager) {
    AssetReader::g_jvm=g_jvm;
    AssetReader::assetManager=assetManager;
}

void AssetReader::destory() {
    if (AssetReader::assetManager) {
        int status;
        JNIEnv *env;
        bool isAttached = false;
        status = AssetReader::g_jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
        if (status < 0) {
            AssetReader::g_jvm->AttachCurrentThread(&env, NULL);//将当前线程注册到虚拟机中．
            isAttached = true;
        }
        env->DeleteGlobalRef(AssetReader::assetManager);
        if (isAttached)
            AssetReader::g_jvm->DetachCurrentThread();
        AssetReader::g_jvm=NULL;
        AssetReader::assetManager= nullptr;
    }
}
