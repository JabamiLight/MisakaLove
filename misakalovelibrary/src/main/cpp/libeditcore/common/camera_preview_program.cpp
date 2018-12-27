//
// Created by TY on 2018/7/19.
//

#include "camera_preview_program.h"



int CameraPreviewProgram::initTexture() {
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, textureId);
    if (checkGlError("glBindTexture")) {
        return -1;
    }
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (checkGlError("glTexParameteri")) {
        return -1;
    }
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    if (checkGlError("glTexParameteri")) {
        return -1;
    }
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    if (checkGlError("glTexParameteri")) {
        return -1;
    }
    glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if (checkGlError("glTexParameteri")) {
        return -1;
    }
    return 1;
}


void CameraPreviewProgram::preInit() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, textureId);
}




CameraPreviewProgram::CameraPreviewProgram() : Program("common/vertexshader.glsl","common/camerafragmentshader.glsl") {

}


