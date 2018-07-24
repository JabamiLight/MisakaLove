//
// Created by TY on 2018/7/19.
//

#include "base_render.h"

void BaseRender::resetSize(int screenWidth, int screenHeigth) {
    showProgram->resetSize(screenWidth,screenHeigth);
}

void BaseRender::destory() {

    showProgram->destory();
    delete showProgram;
    showProgram= nullptr;
}

void BaseRender::setDegree(int degree, bool isFlip) {
    showProgram->chooseVertex(degree,isFlip);
}
