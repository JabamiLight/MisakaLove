//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_CAMERA_PREVIEW_RENDER_H
#define MISAKALOVE_CAMERA_PREVIEW_RENDER_H


#include "../opengl/base_render.h"
#include "camera_preview_program.h"
class CameraPreviewRender: public BaseRender {


protected:
    void render() override;

public:
    CameraPreviewRender(const char *vertexPath, const char *fragmentPath);

protected:
    void init(int degress, bool isVFlip, int textureWidth, int textureHeight, int cameraWidth,
              int cameraHeight) override;

};


#endif //MISAKALOVE_CAMERA_PREVIEW_RENDER_H
