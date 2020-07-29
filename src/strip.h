//
// Created by Samuel on 26/07/2020.
//

#ifndef INFINITY_CUBE_STRIP_H
#define INFINITY_CUBE_STRIP_H

#include "constants.h"

class Strip {
    // Array containing the indices of this strip.
    int leds[STRIP_SIZE]{};

    // Index of the strip in the cube
    int index;

public:
    explicit Strip(int i);

    int getLedIndex(int i);

// Used so that 2 strips on an edge have the same indices.
bool reverse = false;
};


#endif //INFINITY_CUBE_STRIP_H
