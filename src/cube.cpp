//
// Created by Samuel on 26/07/2020.
//

#include "cube.h"
#include "stripcontroller.h"
#include <FastLED.h>

Cube *Cube::instance = nullptr;

Cube::Cube() {
    for (int i = 0; i < STRIP_COUNT; ++i) {
        auto *strip = new Strip(i);
        strips[i] = strip;
    }
    for (auto & led : leds) {
        led = CRGB::Black;
    }
    setDefaults();
}

// Inverts the direction of a strip
void Cube::invert(int index) {
    (*strips[index]).reverse =  !(*strips[index]).reverse;
}

const int TO_INVERT[] = {0, 1, 4, 5, 8, 9, 12, 15, 16, 19, 20, 21};
//const int Z_INDICES[] = {5, 7, 8, 10, 12, 14, 16, 18};
//const int X_INDICES[] = {0, 2, 9, 11, 17, 19, 21, 23};
//const int Y_INDICES[] = {1, 3, 4, 6, 13, 15, 20, 22};

// Generates default and constants.
void Cube::setDefaults() {
    FULL_CUBE = &(*new StripController<24>(strips));

    for (int i = 0; i < 6; ++i) {
        Strip *face[4] = {strips[0 + 4 * i], strips[1 + 4 * i], strips[2 + 4 * i], strips[3 + 4 * i]};
        FACES[i] = &(*new StripController<4>(face));
    }

    for (int i = 0; i < 11; ++i) {
//        invert(TO_INVERT[i]);
    }
}
