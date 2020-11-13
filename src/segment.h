//
// Created by Samuel on 13/11/2020.
//
#pragma once
#include "main.h"
#include "segmentbase.h"

#ifndef INFINITY_CUBE_STRIP_IMPL_H
#define INFINITY_CUBE_STRIP_IMPL_H

template<int STRIP_LEN>
class Segment: public SegmentBase {
public:
    explicit Segment(){};

    CRGB* array[STRIP_LEN];

    explicit Segment(CRGB *indices[]) {
        for (int i = 0; i < STRIP_LEN; ++i) {
            array[i] = indices[i];
        }
    }

    void setUniformCRGB(CRGB color) override {
        for (int i = 0; i < STRIP_LEN; ++i) {
            *(array[i]) = color;
        }
    }

    int getLength() override {
        return STRIP_LEN;
    }
};

#endif //INFINITY_CUBE_STRIP_IMPL_H
