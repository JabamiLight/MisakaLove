//
// Created by TY on 2018/12/24.
//

#ifndef MISAKALOVE_BEAUTYFILTER_H
#define MISAKALOVE_BEAUTYFILTER_H


#include "../../opengl/program.h"
#include "../../3rdparty/facedet/face.h"

#define LOG_TAG "BeautyFilter"

class BeautyFilter : public Program {


//    float scaleRatio;// 缩放系数，0无缩放，大于0则放大
//    float radius;// 缩放算法的作用域半径
//    vec2 leftEyeCenterPosition; // 左眼控制点，越远变形越小
//    vec2 rightEyeCenterPosition; // 右眼控制点
//    aspectRatio; // 所处理图像的宽高比
public:
    //大眼参数和位置
    GLint scaleRatioLocation;
    GLint radiusLocation;
    GLint leftEyeCenterPosition;
    GLint rightEyeCenterPosition;
    GLint aspectRatioLocation;
    GLint faceValidateLocation;

    float eyeScale=.0, eyeRadius;
    Pointf leftEyePoint;
    Pointf RightEyePoint;
    int faceValidate;

    //瘦脸参数和位置
    GLint faceRadiusLocations;
    GLint faceAspectRatioLocation;
    GLint leftContourPointsLocation;
    GLint rightContourPointsLocation;
    GLint deltaArrayLocation;
    GLint arraySizeLocation;

    float faceRadius, faceAspectRatio;
    float *leftContourPoints = nullptr;
    float *rightContourPoints = nullptr;
    float *deltaArray = nullptr;
    float delta = 0.5f;
    int arraySize = 10;

    //磨皮参数和位置
    GLint singleStepOffsetLocation;
    GLint paramsLocation;
    GLint brightnessLocation;
    GLint texelWidthOffsetLocation;
    GLint texelHeightOffsetLocation;

    float* singleStepOffset=nullptr;
    float* params= nullptr;
    float brightness=0.47f;
    float texelWidthOffset=2.0f;
    float texelHeightOffset=2.0f;
    float toneLevel=-0.5;
    float beautyLevel =1.2;
    float brightLevel  =0.47;


    BeautyFilter();

    void initLocation() override;

    void setFaceInfo(Face *face);

protected:
    void preRender() override;

};


#endif //MISAKALOVE_BEAUTYFILTER_H
