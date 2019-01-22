//
// Created by TY on 2018/8/8.
//

#include "amaro_filter.h"

AmaroFilter::AmaroFilter() : Program(COMMON_VERTEX_SHADER, "filter/amaro.glsl") {}

int AmaroFilter::initTexture() {
    inputTexture[0] = OpenglUtils::loadTextureFromAssets("filterpic/brannan_blowout.png");
    inputTexture[1] = OpenglUtils::loadTextureFromAssets("filterpic/overlaymap.png");
    inputTexture[2] = OpenglUtils::loadTextureFromAssets("filterpic/amaromap.png");
    for (int i = 0; i < 3; i++) {
        glActiveTexture(GL_TEXTURE0 + i + 1);
        glBindTexture(GL_TEXTURE_2D, inputTexture[i]);
    }
    return 1;
}

AmaroFilter::~AmaroFilter() {
    glDeleteTextures(3, inputTexture);
}

void AmaroFilter::preInit() {
    glUniform1f(mGLStrengthLocation, 1.0f);
    glUniform1i(inputTextureLocation[0], 1);
    glUniform1i(inputTextureLocation[1], 2);
    glUniform1i(inputTextureLocation[2], 3);
}

void AmaroFilter::initLocation() {
    mGLStrengthLocation = glGetUniformLocation(mGLProgId, "strength");
    inputTextureLocation[0] = glGetUniformLocation(mGLProgId, "inputImageTexture2");
    inputTextureLocation[1] = glGetUniformLocation(mGLProgId, "inputImageTexture3");
    inputTextureLocation[2] = glGetUniformLocation(mGLProgId, "inputImageTexture4");
}


