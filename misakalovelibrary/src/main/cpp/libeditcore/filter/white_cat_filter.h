//
// Created by TY on 2018/8/9.
//

#ifndef MISAKALOVE_WHITE_CAT_H
#define MISAKALOVE_WHITE_CAT_H


#include "../../opengl/program.h"

class WhiteCatFilter : public Program{
public:
    WhiteCatFilter();

    WhiteCatFilter(const char *vertexPath, const char *fragPath);

    int initTexture() override;


protected:
    void preRender() override;

public:
    void initLocation() override;

    virtual ~WhiteCatFilter();

    GLuint mToneCurveTexture;
    GLint mToneCurveTextureUniformLocation;
};


#endif //MISAKALOVE_WHITE_CAT_H
