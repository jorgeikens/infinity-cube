//
// Created by Samuel on 13/11/2020.
//
#pragma once
#include "main.h"

#ifndef INFINITY_CUBE_CUBE_H
#define INFINITY_CUBE_CUBE_H

/**
 * Singleton Cube class
 */
class Cube {
    static Cube *instance;

    void setDefaults();

    Cube();

public:

    static Cube *getInstance();

    CRGB* leds;
};


#endif //INFINITY_CUBE_CUBE_H
