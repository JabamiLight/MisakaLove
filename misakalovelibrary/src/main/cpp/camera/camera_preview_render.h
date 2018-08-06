//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_CAMERA_PREVIEW_RENDER_H
#define MISAKALOVE_CAMERA_PREVIEW_RENDER_H


#include "../opengl/base_render.h"
#include "camera_preview_program.h"
#include "../libeditcore/filter_program.h"

class CameraPreviewRender: public BaseRender {



public:
    void render() override;
    CameraPreviewRender();
    void init(jint degress, bool isVFlip, int textureWidth, int textureHeight, int cameraWidth,
                  int cameraHeight, int i, int i1) override;
    GLuint getCameraTexId();

    void destory() override;

};


#endif //MISAKALOVE_CAMERA_PREVIEW_RENDER_H
