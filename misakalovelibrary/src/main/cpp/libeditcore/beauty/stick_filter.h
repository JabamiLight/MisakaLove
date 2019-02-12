//
// Created by TY on 2019/1/21.
//

#ifndef MISAKALOVE_STICK_FILTER_H
#define MISAKALOVE_STICK_FILTER_H


#include "../../opengl/program.h"
#include "../../3rdparty/facedet/face.h"
#include "../../libcommon/face/face_constant.h"
#define LOG_TAG "StickFilter"
class StickFilter : public Program {


public:
    GLint inputImageTexture=-1;
    GLint mousePointLocation=-1;



//    float **mouthPoint;
    float *mouthPoints= nullptr;
    float mouthX,mouthY;
    Face* face= nullptr;
    float *vertices= nullptr;

    int frameIndex=0;

    GLuint vaoMouth,vboTexture,VboCoord,eboCoord;

    StickFilter();

    int initTexture() override;

    void initLocation() override;


    void setFaceInfo(Face *face);


    void initCoord() override;

protected:
    void preInit() override;

    void preRender() override;

public:
    void render() override;

};


#endif //MISAKALOVE_STICK_FILTER_H
