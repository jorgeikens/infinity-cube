//
// Created by Samuel on 26/07/2020.
//

#include "strip.h"
#include "constants.h"

//
// Fills the array with leds according to the index.
//
void getStrip(int arr[11], int index) {
    for (int i = 0; i < 11; i++) {
        arr[i] = i + 11 * index;
    }
}

Strip::Strip(int i) {
    getStrip(leds, i);
    this->index = i;
}

int Strip::getLedIndex(int i) {
    if (reverse) {
        return leds[STRIP_SIZE - 1] - i;
    } else {
        return leds[i];
    }
}
