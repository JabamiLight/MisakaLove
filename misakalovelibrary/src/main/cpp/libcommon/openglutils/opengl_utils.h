//
// Created by TY on 2018/8/8.
//

#ifndef MISAKALOVE_OPENGL_UTILS_H
#define MISAKALOVE_OPENGL_UTILS_H


#include <GLES3/gl3.h>

class OpenglUtils {

public:
    static GLuint loadTextureFromAssets(const char *path);

    static GLuint loadTexture(unsigned char*,int,int);

    static GLuint loadTextureFromSdcard(const char*);





};


#endif //MISAKALOVE_OPENGL_UTILS_H
