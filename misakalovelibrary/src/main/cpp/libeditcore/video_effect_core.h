//
// Created by TY on 2018/7/25.
//

#ifndef MISAKALOVE_VIDEO_EFFECT_PROGRAM_H
#define MISAKALOVE_VIDEO_EFFECT_PROGRAM_H


#define LOG_TAG "VideoEffectCore"
#include "../opengl/program.h"
#include <list>
#include <GLES2/gl2ext.h>
#include "common/camera_preview_program.h"
#include "../libcommon/CommonTools.h"
#include "../3rdparty/facedet/detector.h"
#include "filter/cool_filter.h"
#include "../3rdparty/facedet/face.h"
#include "beauty/beauty_filter.h"

#include <map>
#define EFFECT_FILTER 1
#define EFFECT_BEAUTY 2
using namespace std;

class VideoEffectCore {



private:
    map<int,Program*> filterPrograms;
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

    void addFilter(Program *program, int i);

    GLuint getAfterTextureId();

    GLuint getESTextureId();

    virtual ~VideoEffectCore();

    void clearFilter();


    /**
     * 设置人脸数据给program
     */

    void setFaceInfo(Face* face);

    void *ptr;
};


#endif //MISAKALOVE_VIDEO_EFFECT_PROGRAM_H
