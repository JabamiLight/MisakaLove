//
// Created by TY on 2018/7/25.
//

#ifndef MISAKALOVE_VIDEO_EFFECT_PROGRAM_H
#define MISAKALOVE_VIDEO_EFFECT_PROGRAM_H

#include "../opengl/program.h"
#include <list>
#include <GLES2/gl2ext.h>
using namespace std;

class VideoEffectCore {

private:
    list<Program*> filterPrograms;
    GLuint afterEditTextureId;
    GLuint cameraTextureId;
    GLuint FBO;
    int textureWidth,textureHeight;
public:
    void init(int textureWidth,int textureHeight);

    void initTexture();

    void initPbo();

    void process();

    void addFilter(Program* program);
};


#endif //MISAKALOVE_VIDEO_EFFECT_PROGRAM_H
