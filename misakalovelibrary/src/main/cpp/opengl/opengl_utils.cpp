//
// Created by TY on 2018/8/8.
//

#include "opengl_utils.h"
#include "../libeditcore/decoder/png_decoder.h"

GLuint OpenglUtils::loadTextureFromAssets(const char *path) {

    PngDecoder *decoder = new PngDecoder();
    GLuint textureId;

    if (decoder->openAssetsFile(path) > 0) {
        RGBAFrame *screenFrame = decoder->getRGBAFrame();
        decoder->closeFile();
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, screenFrame->width,screenFrame-> height,
                0, GL_RGBA, GL_RGBA, screenFrame->pixels);
        glBindTexture(GL_TEXTURE_2D, 0);
        delete screenFrame;
    }
    delete decoder;
    return textureId;
}
