//
// Created by Samuel on 13/11/2020.
//
#pragma once
#include <FastLED.h>
#include "constants.h"

CRGB** getSegmentFromIndex(CRGB leds[], int index){
    CRGB** pointers = new CRGB*[STRIP_SIZE];
    for (int i = 0; i < STRIP_SIZE; ++i) {
        pointers[i] = &leds[i + STRIP_SIZE * index];
    }
    return pointers;
}