//
// Created by TY on 2018/12/24.
//

#ifndef MISAKALOVE_FACE_H
#define MISAKALOVE_FACE_H

struct Pointf{
public:
    Pointf(int i, int i1);

    Pointf();

    float x;
    float y;

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
     int cameraWidth,cameraHeight;
     bool isInvalid= false;
     Pointf* points;

     ~Face();

     //左眼 1  34  54  59  35  67  3   12  94
     //右眼 91 27 104  41  85  20  47  43  51


};



#endif //MISAKALOVE_FACE_H
