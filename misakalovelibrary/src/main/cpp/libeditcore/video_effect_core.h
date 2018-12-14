//
// Created by TY on 2018/7/25.
//

#ifndef MISAKALOVE_VIDEO_EFFECT_PROGRAM_H
#define MISAKALOVE_VIDEO_EFFECT_PROGRAM_H

#include "../opengl/program.h"
#include <list>
#include <GLES2/gl2ext.h>
#include "common/camera_preview_program.h"
#include "../libcommon/CommonTools.h"

using namespace std;

class VideoEffectCore {

private:
    list<Program*> filterPrograms;
    Program* copyCommonProgram;
    GLuint* processTextureIds;
    GLuint cameraTextureId;
    uint8_t processTextureIndex=0;
    GLuint FBO;
    jint  degress;
    bool isVFilp;
    int textureWidth,textureHeight;
public:
    void init(jint textureWidth, bool textureHeight, int i, int i1);

    void initTexture();

    void initPbo();

    void process();

    void addFilter(Program* program);

    GLuint getAfterTextureId();

    GLuint getESTextureId();

    virtual ~VideoEffectCore();

    void clearFilter();


    void *ptr;
};


#endif //MISAKALOVE_VIDEO_EFFECT_PROGRAM_H
