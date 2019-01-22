//
// Created by TY on 2019/1/21.
//

#include "stick_filter.h"

StickFilter::StickFilter() : Program(COMMON_VERTEX_SHADER, "beauty/stickfragshader.glsl") {

}


int StickFilter::initTexture() {
    textureId = OpenglUtils::loadTextureFromSdcard(
            "/sdcard/new_ptv_template_usable/video_maonvws_iOS/lian.png");
    glActiveTexture(GL_TEXTURE0 + 1);
    glBindTexture(GL_TEXTURE_2D, textureId);
    return 1;
}

void StickFilter::initLocation() {
    inputImageTexture = glGetUniformLocation(mGLProgId, "inputImageTexture");
    mousePointLocation = glGetUniformLocation(mGLProgId, "mousePoint");

}

void StickFilter::preInit() {
    glUniform1i(inputImageTexture, 1);
}

void StickFilter::preRender() {
    if(mouthPoint){
        glUniform2fv(mousePointLocation, 18, mouthPoints);
    }

}

void StickFilter::render() {
    glUseProgram(mGLProgId);
    preRender();
    glViewport(0, 0, width, height);
//    glClear(GL_COLOR_BUFFER_BIT);
    glBindVertexArray(Program::VAO[vaoIndex]);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void StickFilter::setMouth(float x, float y) {
    mouthX = x;
    mouthY = y;
}

void StickFilter::setFaceInfo(Face *face) {
    if (face->isInvalid) {
//        if(!mouthPoint){
//            mouthPoint=new float*[18];
//        }
//        mouthPoint[0]=new float[2]{1.0f-face->points[45].x/face->cameraHeight,face->points[45].y/face->cameraWidth};
//        mouthPoint[1]=new float[2]{1.0f-face->points[50].x/face->cameraHeight,face->points[50].y/face->cameraWidth};
//        mouthPoint[2]=new float[2]{1.0f-face->points[65].x/face->cameraHeight,face->points[65].y/face->cameraWidth};
//        mouthPoint[3]=new float[2]{1.0f-face->points[64].x/face->cameraHeight,face->points[64].y/face->cameraWidth};
//        mouthPoint[4]=new float[2]{1.0f-face->points[32].x/face->cameraHeight,face->points[32].y/face->cameraWidth};
//        mouthPoint[5]=new float[2]{1.0f-face->points[30].x/face->cameraHeight,face->points[30].y/face->cameraWidth};
//        mouthPoint[6]=new float[2]{1.0f-face->points[4].x/face->cameraHeight,face->points[4].y/face->cameraWidth};
//        mouthPoint[7]=new float[2]{1.0f-face->points[2].x/face->cameraHeight,face->points[2].y/face->cameraWidth};
//        mouthPoint[8]=new float[2]{1.0f-face->points[36].x/face->cameraHeight,face->points[36].y/face->cameraWidth};
//        mouthPoint[9]=new float[2]{1.0f-face->points[40].x/face->cameraHeight,face->points[40].y/face->cameraWidth};
//        mouthPoint[10]=new float[2]{1.0f-face->points[37].x/face->cameraHeight,face->points[37].y/face->cameraWidth};
//        mouthPoint[11]=new float[2]{1.0f-face->points[39].x/face->cameraHeight,face->points[39].y/face->cameraWidth};
//        mouthPoint[12]=new float[2]{1.0f-face->points[38].x/face->cameraHeight,face->points[38].y/face->cameraWidth};
//        mouthPoint[13]=new float[2]{1.0f-face->points[26].x/face->cameraHeight,face->points[26].y/face->cameraWidth};
//        mouthPoint[14]=new float[2]{1.0f-face->points[33].x/face->cameraHeight,face->points[33].y/face->cameraWidth};
//        mouthPoint[15]=new float[2]{1.0f-face->points[25].x/face->cameraHeight,face->points[25].y/face->cameraWidth};
//        mouthPoint[16]=new float[2]{1.0f-face->points[103].x/face->cameraHeight,face->points[103].y/face->cameraWidth};
//        mouthPoint[17]=new float[2]{1.0f-face->points[63].x/face->cameraHeight,face->points[63].y/face->cameraWidth};

        if (!mouthPoints) {
            mouthPoints=new float[36];
            mouthPoints[0] = 1.0f - face->points[45].x / face->cameraHeight;
            mouthPoints[1] = face->points[45].y / face->cameraWidth;
            mouthPoints[2] = 1.0f - face->points[50].x / face->cameraHeight;
            mouthPoints[3] = face->points[50].y / face->cameraWidth;
            mouthPoints[4] = 1.0f - face->points[65].x / face->cameraHeight;
            mouthPoints[5] = face->points[65].y / face->cameraWidth;
            mouthPoints[6] = 1.0f - face->points[64].x / face->cameraHeight;
            mouthPoints[7] = face->points[64].y / face->cameraWidth;
            mouthPoints[8] = 1.0f - face->points[32].x / face->cameraHeight;
            mouthPoints[9] = face->points[32].y / face->cameraWidth;
            mouthPoints[10] = 1.0f - face->points[30].x / face->cameraHeight;
            mouthPoints[11] = face->points[30].y / face->cameraWidth;
            mouthPoints[12] = 1.0f - face->points[4].x / face->cameraHeight;
            mouthPoints[13] = face->points[4].y / face->cameraWidth;
            mouthPoints[14] = 1.0f - face->points[2].x / face->cameraHeight;
            mouthPoints[15] = face->points[2].y / face->cameraWidth;
            mouthPoints[16] = 1.0f - face->points[36].x / face->cameraHeight;
            mouthPoints[17] = face->points[36].y / face->cameraWidth;
            mouthPoints[18] = 1.0f - face->points[40].x / face->cameraHeight;
            mouthPoints[19] = face->points[40].y / face->cameraWidth;
            mouthPoints[20] = 1.0f - face->points[37].x / face->cameraHeight;
            mouthPoints[21] = face->points[37].y / face->cameraWidth;
            mouthPoints[22] = 1.0f - face->points[39].x / face->cameraHeight;
            mouthPoints[23] = face->points[39].y / face->cameraWidth;
            mouthPoints[24] = 1.0f - face->points[38].x / face->cameraHeight;
            mouthPoints[25] = face->points[38].y / face->cameraWidth;
            mouthPoints[26] = 1.0f - face->points[26].x / face->cameraHeight;
            mouthPoints[27] = face->points[26].y / face->cameraWidth;
            mouthPoints[28] = 1.0f - face->points[33].x / face->cameraHeight;
            mouthPoints[29] = face->points[33].y / face->cameraWidth;
            mouthPoints[30] = 1.0f - face->points[25].x / face->cameraHeight;
            mouthPoints[31] = face->points[25].y / face->cameraWidth;
            mouthPoints[32] = 1.0f - face->points[103].x / face->cameraHeight;
            mouthPoints[33] = face->points[103].y / face->cameraWidth;
            mouthPoints[34] = 1.0f - face->points[63].x / face->cameraHeight;
            mouthPoints[35] = face->points[63].y / face->cameraWidth;


        }
    }

}

