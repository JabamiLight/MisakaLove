//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_CAMERA_PREVIEW_PROGRAM_H
#define MISAKALOVE_CAMERA_PREVIEW_PROGRAM_H


#include "../opengl/program.h"
#include <GLES2/gl2ext.h>
class CameraPreviewProgram: public Program {
public:
    CameraPreviewProgram(const char *vertexPath, const char *fragPath);

    int initTexture() override;

    void render() override;

    void chooseVertex(int degress, bool flip) override;
};


#endif //MISAKALOVE_CAMERA_PREVIEW_PROGRAM_H
