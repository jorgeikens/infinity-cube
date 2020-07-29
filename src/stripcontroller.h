//
// Created by Samuel on 26/07/2020.
//

#ifndef INFINITY_CUBE_STRIPCONTROLLER_H
#define INFINITY_CUBE_STRIPCONTROLLER_H

#include <FastLED.h>
#include "strip.h"
#include "cube.h"
#include "constants.h"

//
// Needed for generic base pointers.
//
class StripControllerBase {
public:
    // When the strips are used in compound fashion, i.e. drawRange(Gradient) this allows the strip to be reversed.
    bool compoundReverse = true;

    int TARGET_COUNT_VALUE = 0;

    StripControllerBase() = default;

    virtual void invert() = 0;

    virtual void assign(Strip* targets[]) = 0;

    virtual void drawRange(CRGB color, int start, int length) = 0;

    virtual void setLight(CRGB color, int i) = 0;

    // Draws a gradient over a range in compound fashion.
    virtual void drawRangeGradient(CHSV startcolor, CHSV endcolor, int start, int length) = 0;

    // Sets the color for an index for every strip in the controller.
    virtual void setStripLights(CRGB color, int i) = 0;
};

// Amount of strips under control of this controller.
template < int TARGET_COUNT >

//
// A Strip Controller abstracts the control of a Strip such that it can be used in a compound fashion.
//
class StripController: public StripControllerBase {
Strip *targets[TARGET_COUNT];
public:

    explicit StripController(Strip* targets[]);

    explicit StripController(StripController **stripController);

    StripController();

    void invert() override;

    void assign(Strip* targets[]) override;

    void drawRange(CRGB Color, int start, int length) override;

    void drawRangeGradient(CHSV startcolor, CHSV endcolor, int start, int length) override;

    void setLight(CRGB color, int i) override ;

    void setStripLights(CRGB color, int i) override;
};

template<int TARGET_COUNT>
StripController<TARGET_COUNT>::StripController(Strip **targets) {
    this -> TARGET_COUNT_VALUE = TARGET_COUNT;
    for (int i = 0; i < TARGET_COUNT; ++i) {
        this -> targets[i] = targets[i];
    }
}

template<int TARGET_COUNT>
void StripController<TARGET_COUNT>::setStripLights(CRGB color, int i) {
    Cube *cube = Cube::getInstance();
    for (auto strip : targets) {
        cube -> leds[strip -> getLedIndex(i)] = color;
    }
}

template<int TARGET_COUNT>
void StripController<TARGET_COUNT>::assign(Strip **targets) {
    for (int i = 0; i < TARGET_COUNT; ++i) {
        this->targets[i] = targets[i];
    }
}

template<int TARGET_COUNT>
void StripController<TARGET_COUNT>::invert() {
    for (int i = 0; i < TARGET_COUNT; ++i) {
        targets[i] -> reverse = !(targets[i] -> reverse);
    }
}

template<int TARGET_COUNT>
StripController<TARGET_COUNT>::StripController(StripController **stripController) {
    int start = 0;
    for (StripController & strip : stripController) {
        for (int i = 0; i < strip -> TARGET_COUNT ; ++i) {
            this -> targets[start + i] = strip -> targets[i];
        }
        start += strip -> TARGET_COUNT;
    }
}

template<int TARGET_COUNT>
void StripController<TARGET_COUNT>::drawRange(CRGB color, int start, int length) {
    for (int i = 0; i < length; ++i) {
        int index = start + i;
        int strip = (index % (TARGET_COUNT * STRIP_SIZE)) / STRIP_SIZE;
        (Cube::getInstance()) -> leds[targets[strip] -> getLedIndex(index % STRIP_SIZE)] = color;
    }
}

template<int TARGET_COUNT>
void StripController<TARGET_COUNT>::drawRangeGradient(CHSV startcolor, CHSV endcolor, int start, int length) {
    if (length == 1) {
        CRGB color;
        hsv2rgb_rainbow(endcolor, color);
        setLight(color, start);
        return;
    }

    if( endcolor.value == 0 || endcolor.saturation == 0) {
        endcolor.hue = startcolor.hue;
    }

    if( startcolor.value == 0 || startcolor.saturation == 0) {
        startcolor.hue = endcolor.hue;
    }

    for (int i = 0; i < length; ++i) {
        float frac = (float) i / (float) (length - 1);
        frac = frac * 255;
        CRGB color = blend(startcolor, endcolor, frac);
        this->setLight(color, start + i);
    }
}

template<int TARGET_COUNT>
void StripController<TARGET_COUNT>::setLight(CRGB color, int i) {
    if (compoundReverse)  {
        i = TARGET_COUNT * STRIP_SIZE - i - 1;
    }

    // Underflow
    if (i < 0) i = i + TARGET_COUNT * STRIP_SIZE;

    int strip = (i % (TARGET_COUNT * STRIP_SIZE)) / STRIP_SIZE;
    (Cube::getInstance()) -> leds[targets[strip] -> getLedIndex(i % STRIP_SIZE)] = color;
}

#endif //INFINITY_CUBE_STRIPCONTROLLER_H
