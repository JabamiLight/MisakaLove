//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_CAMERA_PREVIEW_RENDER_H
#define MISAKALOVE_CAMERA_PREVIEW_RENDER_H

#include "../opengl/base_render.h"
#include "../libeditcore/filter/white_cat_filter.h"
#include "../libeditcore/common/camera_preview_program.h"
#include "../libeditcore/filter/cool_filter.h"
#include "../libeditcore/filter/amaro_filter.h"
#include "../libeditcore/common/show_program.h"
#include "../libeditcore/beauty/beauty_filter.h"
#include "../3rdparty/facedet/face.h"


class CameraPreviewRender : public BaseRender {


public:
    Face* face;

    void render() override;
    CameraPreviewRender();
    void init(jint degress, bool isVFlip, int textureWidth, int textureHeight, int cameraWidth,
                  int cameraHeight, int i, int i1) override;
    GLuint getCameraTexId();

    void destroy() override;

    void switchFilter(uint index);

    void setFaceInfo(Face *pFace);

    void setBeautyPara(BeautyPara i);

};

#endif //MISAKALOVE_CAMERA_PREVIEW_RENDER_H
