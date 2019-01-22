//
// Created by TY on 2018/7/19.
//

#include "camera_preview_render.h"
#include "../libeditcore/beauty/stick_filter.h"

void CameraPreviewRender::render() {
    videoEffectCore->process();
    showProgram->setTextureId(videoEffectCore->getAfterTextureId());
    showProgram->render();
}


void CameraPreviewRender::init(jint degress, bool isVFlip, int textureWidth, int textureHeight,
                               int cameraWidth,
                               int cameraHeight, int screenWidth, int screenHeight) {
    showProgram->init(degress, isVFlip, screenWidth, screenHeight);
    videoEffectCore->init(degress, isVFlip, screenWidth, screenHeight);
    //美颜
//    videoEffectCore->addFilter(new BeautyFilter(), EFFECT_BEAUTY);

    //贴纸
    StickFilter *f = new StickFilter();
    f->overlay = true;
    videoEffectCore->addFilter(f, EFFECT_STICKER);
}

CameraPreviewRender::CameraPreviewRender() {
//    previewProgram=new CoolFilter();
    showProgram = new ShowProgram();
    videoEffectCore = new VideoEffectCore();

}

GLuint CameraPreviewRender::getCameraTexId() {
    return videoEffectCore->getESTextureId();
}

void CameraPreviewRender::destroy() {
    BaseRender::destroy();
    delete videoEffectCore;
}

void CameraPreviewRender::switchFilter(uint index) {
    switch (index) {
        case 0:
            videoEffectCore->clearFilter();
            break;
        case 22:
            videoEffectCore->addFilter(new CoolFilter(), EFFECT_FILTER);
            break;
        case 1:
            videoEffectCore->addFilter(new WhiteCatFilter(), EFFECT_FILTER);
            break;
        case 4:
            break;
    }

}

void CameraPreviewRender::setBeautyPara(BeautyPara &i) {
    videoEffectCore->setBeautyPara(i);
}


void CameraPreviewRender::setFaceInfo(Face *pFace) {
    videoEffectCore->setFaceInfo(pFace);
}



