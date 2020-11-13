//
// Created by Samuel on 13/11/2020.
//
#ifndef INFINITY_CUBE_STRIP_IMPL_H
#define INFINITY_CUBE_STRIP_IMPL_H

#include <Arduino.h>
#include "stripbase.h"

template<int STRIP_LEN>
class Strip: public StripBase {
public:
    explicit Strip(){};

    CRGB* array[STRIP_LEN];

    explicit Strip(CRGB *indices[]){
        for (int i = 0; i < STRIP_LEN; ++i) {
            array[i] = indices[i];
        }
    };

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
