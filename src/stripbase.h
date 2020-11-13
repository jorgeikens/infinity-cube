//
// Created by Samuel on 13/11/2020.
//
#ifndef INFINITY_CUBE_STRIPBASE_H
#define INFINITY_CUBE_STRIPBASE_H

#include "constants.h"

class StripBase {
public:
    StripBase() = default;

    virtual int getLength() = 0;

    virtual void setUniformCRGB(CRGB color) = 0;
};

#endif //INFINITY_CUBE_STRIPBASE_H
