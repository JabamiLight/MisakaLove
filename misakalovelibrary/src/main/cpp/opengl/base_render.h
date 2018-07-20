//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_BASERENDER_H
#define MISAKALOVE_BASERENDER_H

#include <GLES3/gl3.h>
#include "program.h"

class BaseRender {

protected:
    virtual void render()=0;
    virtual void init(int degress, bool isVFlip, int textureWidth, int textureHeight, int cameraWidth, int cameraHeight)=0;
    Program* showProgram;
};


#endif //MISAKALOVE_BASERENDER_H
