//
// Created by TY on 2018/7/19.
//

#include "assets_reader.h"


JavaVM* AssetReader::g_jvm = nullptr;
jobject AssetReader::assetManager = nullptr;
#define LOG_TAG "AssetReader"
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

int AssetReader::readPngSource(const char *pngPaht, byte *&data) {
    int status;
    JNIEnv *env;
    bool isAttached = false;
    status = AssetReader::g_jvm->GetEnv((void **) &env, JNI_VERSION_1_6);
    if (status < 0) {
        AssetReader::g_jvm->AttachCurrentThread(&env, NULL);//将当前线程注册到虚拟机中．
        isAttached = true;
    }
    LOGI("ReadAssets png");
    AAssetManager *mgr = AAssetManager_fromJava(env, AssetReader::assetManager);
    if (mgr == NULL) {
        LOGI(" %s", "AAssetManager==NULL");
        return -1;
    }
    AAsset *assets = AAssetManager_open(mgr, pngPaht, AASSET_MODE_BUFFER);
    if (assets == NULL) {
        LOGI(" %s", "asset==NULL");
        return -1;
    }
    off_t  bufferSize=AAsset_getLength(assets);
    LOGI("png file size: %ld\n",bufferSize);
    data=new byte[bufferSize];
    int numBytesRead=AAsset_read(assets, data, static_cast<size_t>(bufferSize));
    AAsset_close(assets);
    if (isAttached)
        AssetReader::g_jvm->DetachCurrentThread();
    return bufferSize;

}

 void AssetReader::mallocContent(AAsset *pAsset, char* &content) {
    off_t  bufferSize=AAsset_getLength(pAsset);
    LOGI("file size: %ld\n",bufferSize);
    content=new char[bufferSize+1];
    content[bufferSize]=0;
    int numBytesRead=AAsset_read(pAsset,content,bufferSize);
    AAsset_close(pAsset);
}
