//
// Created by TY on 2018/8/8.
//

#ifndef MISAKALOVE_AMARO_FILTER_H
#define MISAKALOVE_AMARO_FILTER_H

#include "../../opengl/program.h"


class AmaroFilter: public Program {

protected:
    void preInit() override;

private:
    GLuint inputTexture[3]={0, 0, 0};
    GLint inputTextureLocation[3]={0,0,0};

public:

    int initTexture() override;
    virtual ~AmaroFilter();
    void initLocation() override;

    GLint mGLStrengthLocation;

    AmaroFilter();
};


#endif //MISAKALOVE_AMARO_FILTER_H
