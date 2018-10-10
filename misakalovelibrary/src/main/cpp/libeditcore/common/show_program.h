//
// Created by TY on 2018/8/10.
//

#ifndef MISAKALOVE_SHOW_PROGRAM_H
#define MISAKALOVE_SHOW_PROGRAM_H


#include "../../opengl/program.h"

class ShowProgram: public Program {
public:
    ShowProgram();


    void chooseVertex(int degress, bool flip) override;
};


#endif //MISAKALOVE_SHOW_PROGRAM_H
