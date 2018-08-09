//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_CAMERA_PREVIEW_RENDER_H
#define MISAKALOVE_CAMERA_PREVIEW_RENDER_H


#include "../opengl/base_render.h"
#include "../libeditcore/filter/white_cat_filter.h"
#include "camera_preview_program.h"
#include "../libeditcore/filter/cool_filter.h"
#include "../libeditcore/filter/amaro_filter.h"

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
