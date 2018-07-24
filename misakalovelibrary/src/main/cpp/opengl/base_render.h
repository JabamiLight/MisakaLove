//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_BASERENDER_H
#define MISAKALOVE_BASERENDER_H

#include <GLES3/gl3.h>
#include "program.h"

class BaseRender {

public:
    void resetSize(int screenWidth,int screenHeigth);
    void destory();
    void setDegree(int ,bool);

protected:
    virtual void render()=0;
    virtual void init(jint degress, bool isVFlip, int textureWidth, int textureHeight, int cameraWidth,
                          int cameraHeight, int i, int i1)=0;

    Program* showProgram;
};


#endif //MISAKALOVE_BASERENDER_H
