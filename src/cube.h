//
// Created by Samuel on 26/07/2020.
//
//

#ifndef INFINITY_CUBE_CUBE_H
#define INFINITY_CUBE_CUBE_H

#include <FastLED.h>
#include "strip.h"
#include "constants.h"

// Forward deceleration for pointer
template < int TARGET_COUNT >
class StripController;

// Singleton Cube class.
class Cube {
    static Cube *instance;

    void setDefaults();

    Cube();

public:
    StripController<24> *FULL_CUBE;
    StripController<4> *FACES[6];
    StripController<8> *Z_AXIS;
    StripController<8> *Y_AXIS;
    StripController<8> *X_AXIS;

    CRGB leds[NUM_LEDS];
    Strip *strips[STRIP_COUNT];

    void invert(int index);

    static Cube *getInstance() {
        if (!instance) {
            instance = new Cube();
        }
        return instance;
    }
};


#endif //INFINITY_CUBE_CUBE_H
