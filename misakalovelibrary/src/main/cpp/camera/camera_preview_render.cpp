//
// Created by TY on 2018/7/19.
//

#include "camera_preview_render.h"

void CameraPreviewRender::render() {
    videoEffectCore->process();
    showProgram->setTextureId(videoEffectCore->getAfterTextureId());
    showProgram->render();
}


void CameraPreviewRender::init(jint degress, bool isVFlip, int textureWidth, int textureHeight, int cameraWidth,
                               int cameraHeight, int screenWidth, int screenHeight) {
    showProgram->init(degress, isVFlip, screenWidth, screenHeight);
//    Program* p=new FilterProgram("common/vertexshader.glsl","filter/gray.glsl");
//    p->init(degress,isVFlip,screenWidth,screenHeight);
    previewProgram->init(degress,isVFlip,screenWidth,screenHeight);
    videoEffectCore->init(screenWidth,screenHeight);
    videoEffectCore->addFilter(previewProgram);
}

CameraPreviewRender::CameraPreviewRender() {
    previewProgram=new CameraPreviewProgram("common/vertexshader.glsl","common/fragmentshader.glsl");
    showProgram=new FilterProgram("common/vertexshader.glsl","filter/gray.glsl");
    videoEffectCore=new VideoEffectCore();
}

GLuint CameraPreviewRender::getCameraTexId() {
    return previewProgram->getTextureId();
}


