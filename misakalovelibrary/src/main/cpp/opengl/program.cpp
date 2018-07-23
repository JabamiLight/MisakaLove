//
// Created by TY on 2018/7/19.
//

#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>

#include "program.h"

Program::Program(const char *vertexPath, const char *fragPath) {
    char* vertex;
    char* fragment;
    AssetReader::readSource(vertexPath,fragPath,vertex,fragment);
    mGLProgId=loadProgram(vertex,fragment);
}

Program::~Program() {

}

void Program::destory() {
    mIsInitialized = false;
    if (mGLProgId) {
        glDeleteProgram(mGLProgId);
        mGLProgId = 0;
    }
}


void Program::render() {
//    glViewport(0,0,width,height);
    glViewport(0,0,1000,1000);
    glClearColor(0.0f,1.0f,1.0f,0.0f);
     glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(mGLProgId);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_EXTERNAL_OES, textureId);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

}

void Program::init(int width, int height) {
    this->width=width;
    this->height=height;
    initCoord();
    initTexture();
}

void Program::initCoord() {
    float vertices[] = {
            -1.0f, -1.0f, -0.0f, 0.0f, 0.0f,
            1.0f,-1.0f, -0.0f, 1.0f, 0.0f,
            -1.0f, 1.0f, -0.0f, 0.0f, 1.0f,
            1.0f, 1.0f, -0.0f, 1.0f, 1.0f,
    };
    if (VAO && VBO) {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }
    glUseProgram(mGLProgId);
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), NULL);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float),
                          reinterpret_cast<const void *>(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    mIsInitialized= true;

}

int Program::initTexture() {
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

GLuint Program::getTextureId() {
    return textureId;
}

