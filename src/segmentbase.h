//
// Created by Samuel on 13/11/2020.
//
#pragma once

#ifndef INFINITY_CUBE_SEGMENTBASE_H
#define INFINITY_CUBE_SEGMENTBASE_H

#include "constants.h"

/**
 * Base class for the Segment so that Segment arrays can be created.
 */
class SegmentBase {
public:
    SegmentBase() = default;

    virtual int getLength() = 0;

    virtual void setUniformCRGB(CRGB color) = 0;
};

#endif //INFINITY_CUBE_SEGMENTBASE_H
