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
        glBindVertexArray(vaoMouth);
        float vertices1[] = {
                0.5f, -0.5f, 0.0f,  // bottom right
                0.5f, 0.5f, 0.0f, // top
                -0.5f, -0.5f, 0.0f, // bottom left
        };
//        mouthPoints[16] = 1.0f - face->points[36].x / face->cameraHeight;
//        mouthPoints[17] = face->points[36].y / face->cameraWidth;
//
//        float vertices1[] = {
//                (1.0f-mouthPoints[0]* 2 ), (mouthPoints[1]  * 2 - 1.0f),0.0f,//45  //0
//                (1.0f-mouthPoints[20]* 2), (mouthPoints[21]  * 2 - 1.0f),0.0f,//37 //1
//                (1.0f-mouthPoints[18]* 2), (mouthPoints[19]  * 2 - 1.0f),0.0f,//40 //2
//                (1.0f-mouthPoints[22]* 2), (mouthPoints[23]  * 2 - 1.0f),0.0f,//39 //3
//                (1.0f-mouthPoints[16]* 2), (mouthPoints[17]  * 2 - 1.0f),0.0f,//36 //4
//                (1.0f-mouthPoints[24]* 2), (mouthPoints[25]  * 2 - 1.0f),0.0f,//38 //5
//                (1.0f-mouthPoints[30]* 2), (mouthPoints[31]  * 2 - 1.0f),0.0f,//25 //6
//                (1.0f-mouthPoints[26]* 2), (mouthPoints[27]  * 2 - 1.0f),0.0f,//26 //7
//                (1.0f-mouthPoints[28]* 2), (mouthPoints[29]  * 2 - 1.0f),0.0f,//33 //8
//                (1.0f-mouthPoints[36]* 2), (mouthPoints[37]  * 2 - 1.0f),0.0f, //42//9
//                (1.0f-mouthPoints[38]* 2), (mouthPoints[39]  * 2 - 1.0f),0.0f,//50 //10
//                (1.0f-mouthPoints[14]* 2), (mouthPoints[15]  * 2 - 1.0f),0.0f,//2  //11
//                (1.0f-mouthPoints[12]* 2), (mouthPoints[13]  * 2 - 1.0f),0.0f,//4  //12
//                (1.0f-mouthPoints[10]* 2), (mouthPoints[11]  * 2 - 1.0f),0.0f,//30//13
//                (1.0f-mouthPoints[32]* 2), (mouthPoints[33]  * 2 - 1.0f),0.0f,//103//14
//                (1.0f-mouthPoints[8]* 2),  (mouthPoints[9]  * 2 - 1.0f),0.0f,//32  //15
//                (1.0f-mouthPoints[34]* 2), (mouthPoints[35]  * 2 - 1.0f),0.0f,//63 //16
//                (1.0f-mouthPoints[6]* 2),  (mouthPoints[7]  * 2 - 1.0f),0.0f,//64  //17
//                (1.0f-mouthPoints[4]* 2),  (mouthPoints[5]  * 2 - 1.0f),0.0f,//65  //18
//                (1.0f-mouthPoints[40]* 2), (mouthPoints[41]  * 2 - 1.0f),0.0f,//61 //19
//
//        };

        float *vertices = new float[106 * 3];
        for (int i = 0; i < 318; i += 3) {
            vertices[i] = (1.0f - (1.0f - face->points[i / 3].x / face->cameraHeight) * 2);
            vertices[i + 1] = (1.0f - ((face->points[36].y / face->cameraWidth) * 2 - 1.0f) * 2);
            vertices[i + 2] = 0.0f;
        }

        glBindBuffer(GL_ARRAY_BUFFER, VboCoord);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        glEnableVertexAttribArray(0);
//        glBindVertexArray(VAO[vaoIndex]);
//        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        glDrawElements(GL_TRIANGLES, 44*3, GL_UNSIGNED_INT, 0);

    }
}


void StickFilter::setFaceInfo(Face *face) {
    if (face->isInvalid) {
        this->face = face;
//        if (!mouthPoints) {
//            mouthPoints = new float[42];
//        }
    }

}

void StickFilter::initCoord() {
    glGenVertexArrays(1, &vaoMouth);
    glBindVertexArray(vaoMouth);
    glGenBuffers(1, &VboCoord);
    glGenBuffers(1, &vboTexture);
    glGenBuffers(1, &eboCoord);
//    float textCoord[]={
//            0.0f,0.0f,
//            1.0f,1.0f,
//            0.0f,1.0f
//    };

//    float textCoord1[] = {
//            312.0f / 800.0f, 719.0f / 1067.0f,//45
//            346.0f / 800.0f, 713.0f / 1067.0f,//37
//            354.0f / 800.0f, 727.0f / 1067.0f,//40
//            379.0f / 800.0f, 710.0f / 1067.0f,//39
//            400.0f / 800.0f, 731.0f / 1067.0f,//36
//            401.0f / 800.0f, 714.0f / 1067.0f,//38
//            442.0f / 800.0f, 729.0f / 1067.0f,//25
//            421.0f / 800.0f, 713.0f / 1067.0f,//26
//            454.0f / 800.0f, 713.0f / 1067.0f,//33
//            489.0f / 800.0f, 717.0f / 1067.0f,//42
//            489.0f / 800.0f, 717.0f / 1067.0f,//50
//            442.0f / 800.0f, 736.0f / 1067.0f,//2
//            464.0f / 800.0f, 741.0f / 1067.0f,//4
//            434.0f / 800.0f, 758.0f / 1067.0f,//30
//            401.0f / 800.0f, 741.0f / 1067.0f,//103
//            399.0f / 800.0f, 766.0f / 1067.0f,//32
//            352.0f / 800.0f, 736.0f / 1067.0f,//63
//            364.0f / 800.0f, 759.0f / 1067.0f,//64
//            335.0f / 800.0f, 743.0f / 1067.0f,//65
//            312.0f / 800.0f, 719.0f / 1067.0f,//61
//
//    };
    float *texCoord = new float[106 * 2];
    for (int i = 0; i < 212; i += 2) {
        texCoord[i]=faceConstant::textureCoord[faceConstant::colorIndex[i]]/800.0f;
        texCoord[i+1]=faceConstant::textureCoord[faceConstant::colorIndex[i]+1]/1067.0f;
    }


    glBindBuffer(GL_ARRAY_BUFFER, vboTexture);
    glBufferData(GL_ARRAY_BUFFER, 106*2* sizeof(float), texCoord,
                 GL_STATIC_DRAW);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(1);


    // 3. 复制我们的索引数组到一个索引缓冲中，供OpenGL使用
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboCoord);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 44* sizeof(int),
                 faceConstant::mouthIndex, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}


