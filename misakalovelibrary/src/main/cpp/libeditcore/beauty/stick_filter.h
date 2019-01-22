//
// Created by TY on 2019/1/21.
//

#ifndef MISAKALOVE_STICK_FILTER_H
#define MISAKALOVE_STICK_FILTER_H


#include "../../opengl/program.h"
#include "../../3rdparty/facedet/face.h"

class StickFilter : public Program {


public:
    GLint inputImageTexture=-1;
    GLint mousePointLocation;



    float **mouthPoint;
    float *mouthPoints;
    float mouthX,mouthY;

    StickFilter();

    int initTexture() override;

    void initLocation() override;

    void setMouth(float x, float y);

    void setFaceInfo(Face *face);


protected:
    void preInit() override;

    void preRender() override;

public:
    void render() override;
};


#endif //MISAKALOVE_STICK_FILTER_H
