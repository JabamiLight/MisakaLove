//
// Created by TY on 2018/12/24.
//

#include "beauty_filter.h"

BeautyFilter::BeautyFilter() : Program(COMMON_VERTEX_SHADER, "beauty/beautyshader.glsl") {}

void BeautyFilter::initLocation() {
    glUseProgram(mGLProgId);
    scaleRatioLocation = glGetUniformLocation(mGLProgId, "scaleRatio");
    radiusLocation = glGetUniformLocation(mGLProgId, "radius");
    leftEyeCenterPosition = glGetUniformLocation(mGLProgId, "leftEyeCenterPosition");
    rightEyeCenterPosition = glGetUniformLocation(mGLProgId, "rightEyeCenterPosition");
    aspectRatioLocation = glGetUniformLocation(mGLProgId, "aspectRatio");
    faceValidateLocation = glGetUniformLocation(mGLProgId, "faceValidate");
}


void BeautyFilter::setFaceInfo(Face *face) {
    if (face->isInvalid) {
        leftEyePoint.x = 1.0f - face->points[72].x / face->cameraHeight;
        leftEyePoint.y = face->points[72].y / face->cameraWidth;
        RightEyePoint.x = 1.0f - face->points[52].x / face->cameraHeight;
        RightEyePoint.y = face->points[52].y / face->cameraWidth;
        radius = (face->points[59].x - face->points[72].x) / face->cameraHeight;
        faceValidate=1;
    } else{
        faceValidate=0;
    }
}

void BeautyFilter::preRender() {
    glUniform1i(faceValidateLocation, faceValidate);
    glUniform1f(scaleRatioLocation, scale);
    glUniform1f(radiusLocation, radius);
    glUniform2f(leftEyeCenterPosition, leftEyePoint.x, leftEyePoint.y);
    glUniform2f(rightEyeCenterPosition, RightEyePoint.x, RightEyePoint.y);
    glUniform1f(aspectRatioLocation, static_cast<float >(height) / static_cast<float >(width));
}




