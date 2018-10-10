//
// Created by TY on 2018/7/25.
//

#include "video_effect_core.h"


VideoEffectCore::~VideoEffectCore() {
    if(processTextureIds){
        glDeleteTextures(2,processTextureIds);
        glDeleteFramebuffers(1,&FBO);
    }
}

void VideoEffectCore::initTexture() {
    processTextureIds=new GLuint[2];
    glGenTextures(2, processTextureIds);
    checkGlError("glGenTextures inputTexId");
    for(int i =0;i<2;i++){
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
    this->degress=degress;
    this->isVFilp=isVFlip;
    copyCommonProgram=new CameraPreviewProgram();
    copyCommonProgram->init(degress,isVFlip,textureWidth,textureHeight);
    initTexture();
    initPbo();
}

void VideoEffectCore::process() {
    glBindFramebuffer(GL_FRAMEBUFFER, FBO);
    copyCommonProgram->render();
    list<Program *>::iterator iter;
    for (iter = filterPrograms.begin(); iter != filterPrograms.end(); iter++) {
        (*iter)->setTextureId(processTextureIds[processTextureIndex]);
        processTextureIndex= static_cast<uint8_t>((processTextureIndex + 1) % 2);
        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                               processTextureIds[processTextureIndex], 0);
        (*iter)->render();
    }
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void VideoEffectCore::addFilter(Program *program) {
    filterPrograms.clear();
    program->init(0, true,textureWidth,textureHeight);
    filterPrograms.push_back(program);
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

