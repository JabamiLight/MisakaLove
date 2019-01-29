//
// Created by TY on 2019/1/21.
//

#include "stick_filter.h"

StickFilter::StickFilter() : Program("common/vertexshader.glsl", "beauty/stickfragshader.glsl") {

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
    if (mouthPoints) {
        glUniform2fv(mousePointLocation, 18, mouthPoints);
    }

}

void StickFilter::render() {
    glUseProgram(mGLProgId);
    preRender();
    glViewport(0, 0, width, height);
//    glClear(GL_COLOR_BUFFER_BIT);
//    if (mouthPoints) {
//        float vertices[] = {
//                mouthPoints[0], mouthPoints[1], 0.0f,
//                mouthPoints[20], mouthPoints[21], 0.0f,
//                mouthPoints[18], mouthPoints[19], 0.0f,
//        };
//    float vertices[] = {
//            0.5f, 0.5f, 0.0f, // top
//            -0.5f, -0.5f, 0.0f, // bottom left
//            0.5f, -0.5f, 0.0f  // bottom right
//    };
//    float textCoord[] = {
//            -1.0f, 1.0f,//左上
//            -1.0f, -1.0f,//左下
//            1.0f, 1.0f,//右上
//            1.0f, -1.0f,//右下
//    };
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, vertices);
//    glEnableVertexAttribArray(0);
//    }
//    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, textCoord);
//    glEnableVertexAttribArray(1);

    if (mouthPoints) {
        glBindVertexArray(VaoMouth);
//    float vertices[] = {
//            0.5f, 0.5f, 0.0f, // top
//            -0.5f, -0.5f, 0.0f, // bottom left
//            0.5f, -0.5f, 0.0f  // bottom right
//    };

//        float vertices[] = {
//                mouthPoints[0], mouthPoints[1], 0.0f,
//                mouthPoints[20], mouthPoints[21], 0.0f,
//                mouthPoints[18], mouthPoints[19], 0.0f,
//        };
        float vertices[] = {
                (1.0f-mouthPoints[0]* 2 ), (mouthPoints[1]  * 2 - 1.0f),0.0f,//45//0
                (1.0f-mouthPoints[20]* 2), (mouthPoints[21]  * 2 - 1.0f),0.0f,//37
                (1.0f-mouthPoints[18]* 2), (mouthPoints[19]  * 2 - 1.0f),0.0f,//40  //0 1 2
                (1.0f-mouthPoints[22]* 2), (mouthPoints[23]  * 2 - 1.0f),0.0f,//39  //2 1 3
                (1.0f-mouthPoints[16]* 2), (mouthPoints[17]  * 2 - 1.0f),0.0f,//36  //2 3 4
                (1.0f-mouthPoints[24]* 2), (mouthPoints[25]  * 2 - 1.0f),0.0f,//38  //4 3 5
                (1.0f-mouthPoints[30]* 2), (mouthPoints[31]  * 2 - 1.0f),0.0f,//25  //4 5 6
                (1.0f-mouthPoints[26]* 2), (mouthPoints[27]  * 2 - 1.0f),0.0f,//26  //6 5 7
                (1.0f-mouthPoints[36]* 2), (mouthPoints[37]  * 2 - 1.0f),0.0f, //42
                (1.0f-mouthPoints[28]* 2), (mouthPoints[29]  * 2 - 1.0f),0.0f,//33

        };

        glBindBuffer(GL_ARRAY_BUFFER, VboCoord);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(0);

        glDrawArrays(GL_TRIANGLE_STRIP, 0, 10);

    }
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
            mouthPoints = new float[38];
        }
//        mouthPoints[0] = 1.0f - face->points[45].x / face->cameraHeight;
//        mouthPoints[1] = face->points[45].y / face->cameraWidth;
//        mouthPoints[2] = 1.0f - face->points[50].x / face->cameraHeight;
//        mouthPoints[3] = face->points[50].y / face->cameraWidth;
//        mouthPoints[4] = 1.0f - face->points[65].x / face->cameraHeight;
//        mouthPoints[5] = face->points[65].y / face->cameraWidth;
//        mouthPoints[6] = 1.0f - face->points[64].x / face->cameraHeight;
//        mouthPoints[7] = face->points[64].y / face->cameraWidth;
//        mouthPoints[8] = 1.0f - face->points[32].x / face->cameraHeight;
//        mouthPoints[9] = face->points[32].y / face->cameraWidth;
//        mouthPoints[10] = 1.0f - face->points[30].x / face->cameraHeight;
//        mouthPoints[11] = face->points[30].y / face->cameraWidth;
//        mouthPoints[12] = 1.0f - face->points[4].x / face->cameraHeight;
//        mouthPoints[13] = face->points[4].y / face->cameraWidth;
//        mouthPoints[14] = 1.0f - face->points[2].x / face->cameraHeight;
//        mouthPoints[15] = face->points[2].y / face->cameraWidth;
//        mouthPoints[16] = 1.0f - face->points[36].x / face->cameraHeight;
//        mouthPoints[17] = face->points[36].y / face->cameraWidth;
//        mouthPoints[18] = 1.0f - face->points[40].x / face->cameraHeight;
//        mouthPoints[19] = face->points[40].y / face->cameraWidth;
//        mouthPoints[20] = 1.0f - face->points[37].x / face->cameraHeight;
//        mouthPoints[21] = face->points[37].y / face->cameraWidth;
//        mouthPoints[22] = 1.0f - face->points[39].x / face->cameraHeight;
//        mouthPoints[23] = face->points[39].y / face->cameraWidth;
//        mouthPoints[24] = 1.0f - face->points[38].x / face->cameraHeight;
//        mouthPoints[25] = face->points[38].y / face->cameraWidth;
//        mouthPoints[26] = 1.0f - face->points[26].x / face->cameraHeight;
//        mouthPoints[27] = face->points[26].y / face->cameraWidth;
//        mouthPoints[28] = 1.0f - face->points[33].x / face->cameraHeight;
//        mouthPoints[29] = face->points[33].y / face->cameraWidth;
//        mouthPoints[30] = 1.0f - face->points[25].x / face->cameraHeight;
//        mouthPoints[31] = face->points[25].y / face->cameraWidth;
//        mouthPoints[32] = 1.0f - face->points[103].x / face->cameraHeight;
//        mouthPoints[33] = face->points[103].y / face->cameraWidth;
//        mouthPoints[34] = 1.0f - face->points[63].x / face->cameraHeight;
//        mouthPoints[35] = face->points[63].y / face->cameraWidth;


        mouthPoints[0] =  face->points[45].x / face->cameraHeight;
        mouthPoints[1] = face->points[45].y / face->cameraWidth;
        mouthPoints[2] =  face->points[50].x / face->cameraHeight;
        mouthPoints[3] = face->points[50].y / face->cameraWidth;
        mouthPoints[4] =  face->points[65].x / face->cameraHeight;
        mouthPoints[5] = face->points[65].y / face->cameraWidth;
        mouthPoints[6] =  face->points[64].x / face->cameraHeight;
        mouthPoints[7] = face->points[64].y / face->cameraWidth;
        mouthPoints[8] =  face->points[32].x / face->cameraHeight;
        mouthPoints[9] = face->points[32].y / face->cameraWidth;
        mouthPoints[10] =  face->points[30].x / face->cameraHeight;
        mouthPoints[11] = face->points[30].y / face->cameraWidth;
        mouthPoints[12] =  face->points[4].x / face->cameraHeight;
        mouthPoints[13] = face->points[4].y / face->cameraWidth;
        mouthPoints[14] =  face->points[2].x / face->cameraHeight;
        mouthPoints[15] = face->points[2].y / face->cameraWidth;
        mouthPoints[16] =  face->points[36].x / face->cameraHeight;
        mouthPoints[17] = face->points[36].y / face->cameraWidth;
        mouthPoints[18] =  face->points[40].x / face->cameraHeight;
        mouthPoints[19] = face->points[40].y / face->cameraWidth;
        mouthPoints[20] =  face->points[37].x / face->cameraHeight;
        mouthPoints[21] = face->points[37].y / face->cameraWidth;
        mouthPoints[22] =  face->points[39].x / face->cameraHeight;
        mouthPoints[23] = face->points[39].y / face->cameraWidth;
        mouthPoints[24] =  face->points[38].x / face->cameraHeight;
        mouthPoints[25] = face->points[38].y / face->cameraWidth;
        mouthPoints[26] =  face->points[26].x / face->cameraHeight;
        mouthPoints[27] = face->points[26].y / face->cameraWidth;
        mouthPoints[28] =  face->points[33].x / face->cameraHeight;
        mouthPoints[29] = face->points[33].y / face->cameraWidth;
        mouthPoints[30] =  face->points[25].x / face->cameraHeight;
        mouthPoints[31] = face->points[25].y / face->cameraWidth;
        mouthPoints[32] =  face->points[103].x / face->cameraHeight;
        mouthPoints[33] = face->points[103].y / face->cameraWidth;
        mouthPoints[34] =  face->points[63].x / face->cameraHeight;
        mouthPoints[35] = face->points[63].y / face->cameraWidth;
        mouthPoints[36] = face->points[42].x / face->cameraHeight;
        mouthPoints[37] = face->points[42].y / face->cameraWidth;


    }

}

void StickFilter::initCoord() {
    glGenVertexArrays(1, &VaoMouth);
    glBindVertexArray(VaoMouth);
    glGenBuffers(1, &VboCoord);
    glGenBuffers(1, &VboTexture);


    float textCoord[] = {
            1.0f-312.0f/800.0f,719.0f/1067.0f,//0
            1.0f-346.0f/800.0f,713.0f/1067.0f,//37
            1.0f-354.0f/800.0f,727.0f/1067.0f,//40
            1.0f-379.0f/800.0f,710.0f/1067.0f,//39
            1.0f-400.0f/800.0f,731.0f/1067.0f,//36
            1.0f-401.0f/800.0f,714.0f/1067.0f,//38
            1.0f-442.0f/800.0f,729.0f/1067.0f,//25
            1.0f-421.0f/800.0f,713.0f/1067.0f,//26
            1.0f-489.0f/800.0f,717.0f/1067.0f,//42
            1.0f-454.0f/800.0f,713.0f/1067.0f,//33
    };
    glBindBuffer(GL_ARRAY_BUFFER, VboTexture);
    glBufferData(GL_ARRAY_BUFFER, sizeof(textCoord), textCoord, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);

//    float vertices[] = {
//            0.5f, 0.5f, 0.0f, // top
//            -0.5f, -0.5f, 0.0f, // bottom left
//            0.5f, -0.5f, 0.0f  // bottom right
//    };
//    glBindBuffer(GL_ARRAY_BUFFER, VboCoord);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
//    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

