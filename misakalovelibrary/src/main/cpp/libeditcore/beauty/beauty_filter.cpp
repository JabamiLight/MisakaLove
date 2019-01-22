//
// Created by TY on 2018/12/24.
//

#include "beauty_filter.h"

BeautyFilter::BeautyFilter() : Program(COMMON_VERTEX_SHADER, "beauty/beautyfragshader.glsl") {}

void BeautyFilter::initLocation() {
    glUseProgram(mGLProgId);
    //大眼数据
    scaleRatioLocation = glGetUniformLocation(mGLProgId, "scaleRatio");
    radiusLocation = glGetUniformLocation(mGLProgId, "radius");
    leftEyeCenterPosition = glGetUniformLocation(mGLProgId, "leftEyeCenterPosition");
    rightEyeCenterPosition = glGetUniformLocation(mGLProgId, "rightEyeCenterPosition");
    aspectRatioLocation = glGetUniformLocation(mGLProgId, "aspectRatio");
    faceValidateLocation = glGetUniformLocation(mGLProgId, "faceValidate");


    //瘦脸数据
    faceRadiusLocations = glGetUniformLocation(mGLProgId, "faceRadius");
    faceAspectRatioLocation = glGetUniformLocation(mGLProgId, "faceAspectRatio");
    leftContourPointsLocation = glGetUniformLocation(mGLProgId, "leftContourPoints");
    rightContourPointsLocation = glGetUniformLocation(mGLProgId, "rightContourPoints");
    deltaArrayLocation = glGetUniformLocation(mGLProgId, "deltaArray");
    arraySizeLocation = glGetUniformLocation(mGLProgId, "arraySize");


    //磨皮位置
    singleStepOffsetLocation = glGetUniformLocation(mGLProgId, "singleStepOffset");
    paramsLocation = glGetUniformLocation(mGLProgId, "params");
    brightnessLocation = glGetUniformLocation(mGLProgId, "brightness");
    texelWidthOffsetLocation = glGetUniformLocation(mGLProgId, "texelWidthOffset");
    texelHeightOffsetLocation = glGetUniformLocation(mGLProgId, "texelHeightOffset");


}


void BeautyFilter::setFaceInfo(Face *face) {
    if (face->isInvalid) {
        //人眼数据测量
        //旋转导致宽高颠倒
        int cameraHeight = face->cameraHeight;
        int cameraWidth = face->cameraWidth;
        leftEyePoint.x = 1.0f - face->points[72].x / cameraHeight;
        leftEyePoint.y = face->points[72].y / cameraWidth;
        RightEyePoint.x = 1.0f - face->points[52].x / cameraHeight;
        RightEyePoint.y = face->points[52].y / cameraWidth;
        eyeRadius = (face->points[59].x - face->points[72].x) / cameraHeight;

        //配置人脸轮廓
        //102  80  76  左边
        // 56  98  97  右边
        faceRadius = 0.08;
        if (!leftContourPoints) {
            leftContourPoints = new float[20];
        }
        leftContourPoints[0] = 1.0f - face->points[5].x / cameraHeight;
        leftContourPoints[1] = face->points[5].y / cameraWidth;
        leftContourPoints[2] = 1.0f - face->points[102].x / cameraHeight;
        leftContourPoints[3] = face->points[102].y / cameraWidth;
        leftContourPoints[4] = 1.0f - face->points[66].x / cameraHeight;
        leftContourPoints[5] = face->points[66].y / cameraWidth;
        leftContourPoints[6] = 1.0f - face->points[82].x / cameraHeight;
        leftContourPoints[7] = face->points[82].y / cameraWidth;
        leftContourPoints[8] = 1.0f - face->points[81].x / cameraHeight;
        leftContourPoints[9] = face->points[81].y / cameraWidth;
        leftContourPoints[10] = 1.0f - face->points[80].x / cameraHeight;
        leftContourPoints[11] = face->points[80].y / cameraWidth;
        leftContourPoints[12] = 1.0f - face->points[57].x / cameraHeight;
        leftContourPoints[13] = face->points[57].y / cameraWidth;
        leftContourPoints[14] = 1.0f - face->points[78].x / cameraHeight;
        leftContourPoints[15] = face->points[78].y / cameraWidth;
        leftContourPoints[16] = 1.0f - face->points[77].x / cameraHeight;
        leftContourPoints[17] = face->points[77].y / cameraWidth;
        leftContourPoints[18] = 1.0f - face->points[76].x / cameraHeight;
        leftContourPoints[19] = face->points[76].y / cameraWidth;

        if (!rightContourPoints) {
            rightContourPoints = new float[20];
        }
        rightContourPoints[0] = 1.0f - face->points[18].x / cameraHeight;
        rightContourPoints[1] = face->points[18].y / cameraWidth;
        rightContourPoints[2] = 1.0f - face->points[56].x / cameraHeight;
        rightContourPoints[3] = face->points[56].y / cameraWidth;
        rightContourPoints[4] = 1.0f - face->points[49].x / cameraHeight;
        rightContourPoints[5] = face->points[49].y / cameraWidth;
        rightContourPoints[6] = 1.0f - face->points[99].x / cameraHeight;
        rightContourPoints[7] = face->points[99].y / cameraWidth;
        rightContourPoints[8] = 1.0f - face->points[98].x / cameraHeight;
        rightContourPoints[9] = face->points[98].y / cameraWidth;
        rightContourPoints[10] = 1.0f - face->points[101].x / cameraHeight;
        rightContourPoints[11] = face->points[101].y / cameraWidth;
        rightContourPoints[12] = 1.0f - face->points[100].x / cameraHeight;
        rightContourPoints[13] = face->points[100].y / cameraWidth;
        rightContourPoints[14] = 1.0f - face->points[96].x / cameraHeight;
        rightContourPoints[15] = face->points[96].y / cameraWidth;
        rightContourPoints[16] = 1.0f - face->points[95].x / cameraHeight;
        rightContourPoints[17] = face->points[95].y / cameraWidth;
        rightContourPoints[18] = 1.0f - face->points[97].x / cameraHeight;
        rightContourPoints[19] = face->points[97].y / cameraWidth;

        if (!deltaArray) {
            deltaArray = new float[10];
        }
        for (size_t i = 0; i < 10; i++) {
            deltaArray[i] = delta - (9 - i) * 0.01f;
        }
        faceValidate = 1;
    } else {
        faceValidate = 0;
    }
}

void BeautyFilter::preRender() {
    glUniform1i(faceValidateLocation, faceValidate);
    if (faceValidate) {
        //配置大眼数据
        glUniform1f(scaleRatioLocation, eyeScale);
        glUniform1f(radiusLocation, eyeRadius);
        glUniform2f(leftEyeCenterPosition, leftEyePoint.x, leftEyePoint.y);
        glUniform2f(rightEyeCenterPosition, RightEyePoint.x, RightEyePoint.y);
        glUniform1f(aspectRatioLocation, static_cast<float >(height) / static_cast<float >(width));
        //配置瘦脸数据
        glUniform1f(faceRadiusLocations, faceRadius);
        glUniform1fv(leftContourPointsLocation, 20, leftContourPoints);
        glUniform1fv(rightContourPointsLocation, 20, rightContourPoints);
        glUniform1fv(deltaArrayLocation, 10, deltaArray);
        glUniform1i(arraySizeLocation, arraySize);
    }
    //配置磨皮数据
//    if(!singleStepOffset){
//        singleStepOffset=new float[2];
//        singleStepOffset[0]=2.0f/width;
//        singleStepOffset[1]=2.0f/height;
//    }
//    glUniform2fv(singleStepOffsetLocation, 1, singleStepOffset);

    if (!params) {
        params = new float[4];
        params[0] = 1.0f - 0.6f * beautyLevel;
        params[1] = 1.0f - 0.3f * beautyLevel;
        params[2] = 0.1f + 0.3f * toneLevel;
        params[3] = 0.1f + 0.3f * toneLevel;
    }
    glUniform4fv(paramsLocation, 1, params);
    glUniform1f(brightnessLocation, 0.6f * (-0.5f + brightLevel));
    glUniform1f(texelWidthOffsetLocation, texelWidthOffset/width);
    glUniform1f(texelHeightOffsetLocation, texelHeightOffset/height);

}




