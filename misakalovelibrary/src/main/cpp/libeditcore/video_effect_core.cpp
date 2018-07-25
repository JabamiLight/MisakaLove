//
// Created by TY on 2018/7/25.
//

#include "video_effect_core.h"


void VideoEffectCore::initTexture() {

    glGenTextures(1, &afterEditTextureId);
    checkGlError("glGenTextures inputTexId");
    glBindTexture(GL_TEXTURE_2D, afterEditTextureId);
    checkGlError("glBindTexture inputTexId");
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei) textureWidth, (GLsizei) textureHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
    glBindTexture(GL_TEXTURE_2D,0);

    glGenTextures(1, &cameraTextureId);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, cameraTextureId);
    if (checkGlError("glBindTexture")) {
        return;
    }
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (checkGlError("glTexParameteri")) {
        return;
    }
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    if (checkGlError("glTexParameteri")) {
        return;
    }
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    if (checkGlError("glTexParameteri")) {
        return;
    }
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if (checkGlError("glTexParameteri")) {
        return;
    }


}

void VideoEffectCore::initPbo() {
    glGenFramebuffers(1, &FBO);
    checkGlError("glGenFramebuffers");
    glBindFramebuffer(GL_FRAMEBUFFER,FBO);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                           afterEditTextureId, 0);

}

void VideoEffectCore::init(int textureWidth, int textureHeight) {
    this->textureWidth=textureWidth;
    this->textureHeight=textureHeight;
    initTexture();
    initPbo();
}

void VideoEffectCore::process() {



}

void VideoEffectCore::addFilter(Program *program) {
    filterPrograms.push_back(program);
}

