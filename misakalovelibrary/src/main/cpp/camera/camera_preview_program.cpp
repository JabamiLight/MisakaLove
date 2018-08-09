//
// Created by TY on 2018/7/19.
//

#include "camera_preview_program.h"


CameraPreviewProgram::CameraPreviewProgram(const char *vertexPath, const char *fragPath)
        : Program(vertexPath, fragPath) {

}

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


void CameraPreviewProgram::preRender() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, textureId);
}




void CameraPreviewProgram::chooseVertex(int degress, bool flip) {
    switch (degress) {
        case 90:
            vaoIndex = 2;
            break;
        case 180:
            vaoIndex = 3;
            break;
        case 270:
            vaoIndex = 0;
            break;
        case 0:
        default:
            vaoIndex = 1;
            break;
    }
    if (flip) {
        vaoIndex += 4;
    }
}
