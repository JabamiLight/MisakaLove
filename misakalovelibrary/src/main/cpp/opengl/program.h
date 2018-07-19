//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_PROGRAM_H
#define MISAKALOVE_PROGRAM_H


#include "../libcommon/egl_core/gl_tools.h"
#include "../libcommon/assetsutil/assets_reader.h"

class Program {
public:
    Program(const char* vertexPath, const char* fragPath);
    void init(int width,int height);
    void render();

protected:
    virtual ~Program();
    void destory();
    GLuint mGLProgId;
    bool mIsInitialized;
    GLuint mTextureLocation;
    GLuint VAO;
    GLuint VBO;
    GLuint textureId;
    int width,height;

private:
    void initCoord();
    int initTexture();
};


#endif //MISAKALOVE_PROGRAM_H
