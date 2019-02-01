//
// Created by TY on 2018/12/24.
//

#ifndef MISAKALOVE_FACE_H
#define MISAKALOVE_FACE_H

class BeautyPara {
public:
    float eyeScale = 0;
    float faceDelta = 0.5f;
    float texelOffset=0;
    float toneLevel=0;
    float beautyLevel=0;
    float brightLevel=0;
    float minstepoffset = -10;
    float maxstepoffset = 10;
    float minToneValue = -5;
    float maxToneValue = 5;
    float minbeautyValue = 0;
    float maxbeautyValue = 2.5f;
    float minbrightValue = 0;
    float maxbrightValue = 1;

    float range(int percentage, float start, float end) {
        return (end - start) * percentage / 100.0f + start;
    }
};

struct Pointf {
public:
    Pointf(int i, int i1);

    Pointf();

    float x;
    float y;
    char index=-1;

};

class Face {


public:
    int ID;
    int left;
    int top;
    int right;
    int bottom;
    int height;
    int width;
    int cameraWidth, cameraHeight;
    bool isInvalid = false;
    Pointf *points;

    ~Face();

    //左眼 1  34  54  59  35  67  3   12  94
    //右眼 91 27 104  41  85  20  47  43  51


};


#endif //MISAKALOVE_FACE_H
