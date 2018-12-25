//
// Created by TY on 2018/12/24.
//

#include "beauty_filter.h"

BeautyFilter::BeautyFilter() : Program(COMMON_VERTEX_SHADER, "beauty/beautyshader.glsl") {}

void BeautyFilter::initLocation() {
    scaleRatio = glGetUniformLocation(mGLProgId, "scaleRatio");
    radius = glGetUniformLocation(mGLProgId, "radius");
    leftEyeCenterPosition = glGetUniformLocation(mGLProgId, "leftEyeCenterPosition");
    rightEyeCenterPosition = glGetUniformLocation(mGLProgId, "rightEyeCenterPosition");
    aspectRatio = glGetUniformLocation(mGLProgId, "aspectRatio");
}

void BeautyFilter::preRender() {
    glUniform1f(scaleRatio,30.0f);
    glUniform1f(radius, 0.5f);
    glUniform2f(leftEyeCenterPosition, 0.0f,0.0f);
    glUniform2f(rightEyeCenterPosition, 0.0f,0.0f);
    glUniform1f(aspectRatio, 1080.0f/1920.0f);
}




