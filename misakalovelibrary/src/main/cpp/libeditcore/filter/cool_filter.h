//
// Created by TY on 2018/8/9.
//

#ifndef MISAKALOVE_COOL_FILTER_H
#define MISAKALOVE_COOL_FILTER_H


#include "white_cat_filter.h"

class CoolFilter: public WhiteCatFilter {

public:
    CoolFilter();


    int initTexture() override;
};


#endif //MISAKALOVE_COOL_FILTER_H
