//
// Created by TY on 2018/5/25.
//

#ifndef OPENGLNDK_ASSETREADER_H
#define OPENGLNDK_ASSETREADER_H

#include <jni.h>
#include <android/asset_manager_jni.h>
#include "../CommonTools.h"
class AssetReader {

public:
    static JavaVM* g_jvm;
    static jobject  assetManager;
    static void init(JavaVM *g_jvm, jobject assetManager);
    static void readSource( const char* vertexFilePath,
                     const char* fragFilePath,
                     char*& vertexContent,
                     char*& fragContent);
    static int readPngSource(const char* pngPaht,byte*& data);

    static void destory();
    static void mallocContent(AAsset *pAsset, char* &content);

};


#endif //OPENGLNDK_ASSETREADER_H