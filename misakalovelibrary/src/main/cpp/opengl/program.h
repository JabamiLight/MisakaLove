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
    void init(int width, bool height, int i, int i1);
    void render();
    GLuint getTextureId();
    void resetSize(int screenWidth,int screenHeight);
    void destory();
    virtual ~Program();
    void chooseVertex(int degress, bool flip);
protected:
    GLuint mGLProgId;
    bool mIsInitialized;
    GLuint mTextureLocation;
    GLuint* VAO= nullptr;
    GLuint* VBO= nullptr;
    GLuint textureId;
    int width,height;
    int vaoIndex=0;

private:
    void initCoord();
    int initTexture();
};


#endif //MISAKALOVE_PROGRAM_H
