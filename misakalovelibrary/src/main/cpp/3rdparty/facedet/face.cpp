//
// Created by TY on 2018/12/24.
//

#include "face.h"


Face::~Face() {
    if(points){
        delete []points;
    }

}

Pointf::Pointf(int i, int i1):x(i) ,y(i1){

}

Pointf::Pointf() {}
