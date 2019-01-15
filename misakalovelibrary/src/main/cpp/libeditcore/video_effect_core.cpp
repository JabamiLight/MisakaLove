//
// Created by TY on 2018/7/25.
//

#include "video_effect_core.h"
#include "filter/cool_filter.h"
#include "../camera/camera_preview_render.h"


VideoEffectCore::~VideoEffectCore() {
    if (processTextureIds) {
        glDeleteTextures(2, processTextureIds);
        glDeleteFramebuffers(1, &FBO);
    }
}

void VideoEffectCore::initTexture() {
    processTextureIds = new GLuint[2];
    glGenTextures(2, processTextureIds);
    checkGlError("glGenTextures inputTexId");
    for (int i = 0; i < 2; i++) {
        glBindTexture(GL_TEXTURE_2D, processTextureIds[i]);
        checkGlError("glBindTexture inputTexId");
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei) textureWidth, (GLsizei) textureHeight, 0,
                     GL_RGBA, GL_UNSIGNED_BYTE, 0);
        glBindTexture(GL_TEXTURE_2D, 0);
    }
}

void VideoEffectCore::initPbo() {
    glGenFramebuffers(1, &FBO);
    checkGlError("glGenFramebuffers");
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                           processTextureIds[processTextureIndex], 0);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void VideoEffectCore::init(jint degress, bool isVFlip, int textureWidth, int textureHeight) {
    this->textureWidth = textureWidth;
    this->textureHeight = textureHeight;
    this->degress = degress;
    this->isVFilp = isVFlip;
    copyCommonProgram = new CameraPreviewProgram();
    copyCommonProgram->init(degress, isVFlip, textureWidth, textureHeight);
    initTexture();
    initPbo();
}

void VideoEffectCore::process() {
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    copyCommonProgram->render();
    map<int, Program *>::iterator iter;
    for (iter = filterPrograms.begin(); iter != filterPrograms.end(); iter++) {
        iter->second->setTextureId(processTextureIds[processTextureIndex]);
        processTextureIndex = static_cast<uint8_t>((processTextureIndex + 1) % 2);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                               processTextureIds[processTextureIndex], 0);
        iter->second->render();
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void VideoEffectCore::addFilter(Program *program, int i) {
    filterPrograms.clear();
    program->init(0, true, textureWidth, textureHeight);
    filterPrograms.insert(pair<int, Program *>(i, program));
}

GLuint VideoEffectCore::getAfterTextureId() {
    return processTextureIds[processTextureIndex];
}

GLuint VideoEffectCore::getESTextureId() {
    return copyCommonProgram->getTextureId();
}

void VideoEffectCore::clearFilter() {
    filterPrograms.clear();

}

void VideoEffectCore::setFaceInfo(Face *face) {
    map<int, Program *>::iterator iter = filterPrograms.find(EFFECT_BEAUTY);
    if (iter->second){
        static_cast<BeautyFilter *>(iter->second)->setFaceInfo(face);
    }

}

void VideoEffectCore::setBeautyPara(BeautyPara para) {
    map<int, Program *>::iterator iter = filterPrograms.find(EFFECT_BEAUTY);
    if (iter->second){
        static_cast<BeautyFilter *>(iter->second)->eyeScale=para.eyeScale ;
        static_cast<BeautyFilter *>(iter->second)->delta= para.faceDelta;
    }
}

