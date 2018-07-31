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

void CameraPreviewProgram::render() {
        glViewport(0, 0, width, height);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(mGLProgId);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_EXTERNAL_OES, textureId);
        glBindVertexArray(Program::VAO[vaoIndex]);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}
