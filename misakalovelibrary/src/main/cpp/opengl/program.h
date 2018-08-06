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

    virtual void render();
    GLuint getTextureId();
    void resetSize(int screenWidth,int screenHeight);
    void destory();
    virtual ~Program();

    virtual void chooseVertex(int degress, bool flip);
    void setTextureId(GLuint textureId);
    void initCoord();

    virtual int initTexture();
    static GLuint* VAO;
    static GLuint* VBO;
protected:
    GLuint mGLProgId;
    bool mIsInitialized;
    GLuint mTextureLocation;
    GLuint textureId;
    int width,height;
    int vaoIndex=0;


};


#endif //MISAKALOVE_PROGRAM_H
