//
// Created by TY on 2018/8/10.
//

#include "show_program.h"

ShowProgram::ShowProgram() : Program(COMMON_VERTEX_SHADER, "common/commonfragmentshader.glsl") {}

void ShowProgram::chooseVertex(int degress, bool flip) {
    switch (degress) {
        case 90:
            vaoIndex = 0;
            break;
        case 180:
            vaoIndex = 3;
            break;
        case 270:
            vaoIndex = 0;
            break;
        case 0:
        default:
            vaoIndex = 0;
            break;
    }
    if (flip) {
        vaoIndex += 4;
    }
}
