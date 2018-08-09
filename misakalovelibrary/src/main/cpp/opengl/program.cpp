//
// Created by TY on 2018/7/19.
//

#include <GLES3/gl3.h>
#include <GLES2/gl2ext.h>

#include "program.h"
GLuint* Program::VAO= nullptr;
GLuint* Program::VBO= nullptr;
Program::Program(const char *vertexPath, const char *fragPath) {
    char *vertex;
    char *fragment;
    AssetReader::readSource(vertexPath, fragPath, vertex, fragment);
    mGLProgId = loadProgram(vertex, fragment);
}

Program::~Program() {

}

void Program::destory() {
    mIsInitialized = false;
    if (mGLProgId) {
        glDeleteProgram(mGLProgId);
        mGLProgId = 0;
    }
    if (textureId) {
        glDeleteTextures(1, &textureId);
    }
}


void Program::render() {
    glViewport(0, 0, width, height);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(mGLProgId);
    glBindVertexArray(Program::VAO[vaoIndex]);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Program::init(int degress, bool isVFlip, int width, int height) {
    this->width = width;
    this->height = height;
    chooseVertex(degress, isVFlip);
    initCoord();
    initTexture();
    initLocation();
    preRender();
}

void Program::initCoord() {

    if (!Program::VAO && !Program::VBO) {
        float vertices[] = {
                -1.0f, -1.0f,
                1.0f, -1.0f,
                -1.0f, 1.0f,
                1.0f, 1.0f,
        };
        float textCoord[] = {

                0.0f, 1.0f,
                1.0f, 1.0f,
                0.0f, 0.0f,
                1.0f, 0.0f,

                1.0f, 1.0f,
                1.0f, 0.0f,
                0.0f, 1.0f,
                0.0f, 0.0f,

                1.0f, 0.0f,
                0.0f, 0.0f,
                1.0f, 1.0f,
                0.0f, 1.0f,

                0.0f, 0.0f,
                0.0f, 1.0f,
                1.0f, 0.0f,
                1.0f, 1.0f,

                //前置摄像头镜像
                0.0f, 0.0f,
                1.0f, 0.0f,
                0.0f, 1.0f,
                1.0f, 1.0f,

                1.0f, 0.0f,
                1.0f, 1.0f,
                0.0f, 0.0f,
                0.0f, 1.0f,

                1.0f, 1.0f,
                0.0f, 1.0f,
                1.0f, 0.0f,
                0.0f, 0.0f,

                0.0f, 1.0f,
                0.0f, 0.0f,
                1.0f, 1.0f,
                1.0f, 0.0f,

        };

        Program::VBO = new GLuint[9];
        Program::VAO = new GLuint[8];
        glUseProgram(mGLProgId);
        glGenVertexArrays(8, Program::VAO);
        glGenBuffers(9, Program::VBO);
        glBindBuffer(GL_ARRAY_BUFFER, Program::VBO[8]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
        for (int i = 0; i < 8; i++) {
            glBindVertexArray(Program::VAO[i]);
            glBindBuffer(GL_ARRAY_BUFFER, Program::VBO[8]);
            glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
            glEnableVertexAttribArray(0);

            glBindBuffer(GL_ARRAY_BUFFER, Program::VBO[i]);
            glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), textCoord + i * 8, GL_STATIC_DRAW);
            glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
            glEnableVertexAttribArray(1);
        }
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
    mIsInitialized = true;
}

int Program::initTexture() {
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    if (checkGlError("glBindTexture")) {
        return -1;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (checkGlError("glTexParameteri")) {
        return -1;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    if (checkGlError("glTexParameteri")) {
        return -1;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    if (checkGlError("glTexParameteri")) {
        return -1;
    }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    if (checkGlError("glTexParameteri")) {
        return -1;
    }
    return 1;

}

GLuint Program::getTextureId() {
    return textureId;
}

void Program::resetSize(int screenWidth, int screenHeight) {
    this->width = screenWidth;
    this->height = screenHeight;
}

void Program::chooseVertex(int degress, bool flip) {
    switch (degress) {
        case 90:
            vaoIndex = 1;
            break;
        case 180:
            vaoIndex = 2;
            break;
        case 270:
            vaoIndex = 3;
            break;
        case 0:
        default:
            vaoIndex = 0;
            break;
    }
    if (flip) {
        vaoIndex += 4;
    }
}

void Program::setTextureId(GLuint textureId) {
    Program::textureId = textureId;
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureId);
}


void Program::initLocation() {

}

void Program::preRender() {

}

