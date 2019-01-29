//
// Created by TY on 2018/7/19.
//

#ifndef MISAKALOVE_PROGRAM_H
#define MISAKALOVE_PROGRAM_H
#define COMMON_VERTEX_SHADER "common/vertexshader.glsl"
#define COMMON_FRAG_SHADER "common/commonfragmentshader.glsl"

#include "../libcommon/egl_core/gl_tools.h"
#include "../libcommon/assetsutil/assets_reader.h"
#include "../libcommon/openglutils/opengl_utils.h"

class Program {
public:
    Program(const char* vertexPath, const char* fragPath);
    void init(int degress, bool isVFlip, int width, int height);

    virtual void render();
    GLuint getTextureId();
    void resetSize(int screenWidth,int screenHeight);
    void destory();
    virtual ~Program();

    virtual void chooseVertex(int degress, bool flip);
    void setTextureId(GLuint textureId);

    virtual void initCoord();

    virtual int initTexture();

    virtual void initLocation();
    static GLuint* VAO;
    static GLuint* VBO;
    bool overlay= false;
protected:
    GLuint mGLProgId;
    bool mIsInitialized;
    GLuint mTextureLocation;
    GLuint textureId;
    int width,height;
    int vaoIndex=0;

    virtual void preInit();
    virtual void preRender();

};


#endif //MISAKALOVE_PROGRAM_H
