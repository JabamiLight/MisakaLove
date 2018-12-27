//
// Created by TY on 2018/12/24.
//

#ifndef MISAKALOVE_BEAUTYFILTER_H
#define MISAKALOVE_BEAUTYFILTER_H


#include "../../opengl/program.h"
#include "../../3rdparty/facedet/face.h"

class BeautyFilter : public Program{


//    float scaleRatio;// 缩放系数，0无缩放，大于0则放大
//    float radius;// 缩放算法的作用域半径
//    vec2 leftEyeCenterPosition; // 左眼控制点，越远变形越小
//    vec2 rightEyeCenterPosition; // 右眼控制点
//    aspectRatio; // 所处理图像的宽高比
private:
    GLint scaleRatioLocation;
    GLint radiusLocation;
    GLint leftEyeCenterPosition;
    GLint rightEyeCenterPosition;
    GLint aspectRatioLocation;

    float scale,radius;
    Pointf leftEyePoint;
    Pointf RightEyePoint;

public:
    BeautyFilter();
    void initLocation() override;
    void setFaceInfo(Face* face);


protected:
    void preRender() override;

};


#endif //MISAKALOVE_BEAUTYFILTER_H
