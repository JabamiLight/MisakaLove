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
    if (Program::VAO && Program::VBO) {
        glDeleteVertexArrays(8, Program::VAO);
        glDeleteBuffers(9, Program::VBO);
        Program::VAO= nullptr;
        Program::VBO= nullptr;
    }
}

void BaseRender::setDegree(int degree, bool isFlip) {
    showProgram->chooseVertex(degree,isFlip);
}
