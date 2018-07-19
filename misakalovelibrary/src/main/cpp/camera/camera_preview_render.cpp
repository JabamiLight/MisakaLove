//
// Created by TY on 2018/7/19.
//

#include "camera_preview_render.h"

void CameraPreviewRender::render() {

}


CameraPreviewRender::CameraPreviewRender(const char *vertexPath, const char *fragmentPath) {
    program= new CameraPreviewProgram(vertexPath, fragmentPath);

}

void CameraPreviewRender::init(int degress, bool isVFlip, int textureWidth, int textureHeight,
                               int cameraWidth, int cameraHeight) {
    program->init(textureWidth,textureHeight);
}

