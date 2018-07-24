//
// Created by TY on 2018/7/19.
//

#include "camera_preview_render.h"

void CameraPreviewRender::render() {
    showProgram->render();
}


void CameraPreviewRender::init(jint degress, bool isVFlip, int textureWidth, int textureHeight, int cameraWidth,
                               int cameraHeight, int screenWidth, int screenHeight) {
    showProgram->init(degress, isVFlip, screenWidth, screenHeight);
}

CameraPreviewRender::CameraPreviewRender() {
    showProgram= new CameraPreviewProgram("common/vertexshader.glsl", "common/fragmentshader.glsl");

}

GLuint CameraPreviewRender::getCameraTexId() {
    return showProgram->getTextureId();
}


