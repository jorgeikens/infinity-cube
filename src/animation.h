//
// Created by Samuel on 28/07/2020.
//

#ifndef INFINITY_CUBE_ANIMATION_H
#define INFINITY_CUBE_ANIMATION_H

#include "stripcontroller.h"
#include "delays.h"

class Animation {
protected:
    StripControllerBase* target;
public:
    explicit Animation(StripControllerBase *target) {
        this -> target = target;
    }

    virtual void draw() = 0;
};

class GradientFadeAnimation: public Animation {
public:
    explicit GradientFadeAnimation(StripControllerBase *target) : Animation(target) {}

    bool build = true;
    CHSV color = CHSV(0, 255, 255);

    void draw() override {
        for (int i = 1; i <= STRIP_SIZE * target -> TARGET_COUNT_VALUE; ++i) {
            target->drawRangeGradient(CHSV(0, 255, 0), color,
                    0, i);
            if (i < 44) target->setLight(CRGB::White, i);
            FastLED.show();
            delay(5);
        }
        target -> compoundReverse = !(target -> compoundReverse);
    }
};

class CubeGradientFadeAnimation: public Animation {
public:
    GradientFadeAnimation *fades[6];
    CHSV color = CHSV(0, 255, 255);

    explicit CubeGradientFadeAnimation(StripControllerBase *target) : Animation(target) {
        for (int i = 0; i < 6; ++i) {
            fades[i] = new GradientFadeAnimation(Cube::getInstance() -> FACES[i]);
        }
    }

    void draw() override {
        color.h = (color.h + 50) % 255;
        for (auto & fade : fades) {
            fade -> color.h = (this -> color.h) + 5 - random(10);
            fade -> color.s = 255;
            fade -> color.v = 200 - random(50);
            fade -> draw();
        }
        delay(500);
        shuffle();
    }

    void black() {
        int h = color.h;
        color.setHSV(0, 255, 0);
        for (auto & fade : fades) {
            fade -> color = color;
            fade -> draw();
        }
        color.h = h;
        shuffle();
    }

    // Fisher-Yates algorithm
    void shuffle() {
        for (int i = 5; i != 0; i--) {
            int j = random(0,i);
            GradientFadeAnimation *temp = fades[j];
            fades[j] = fades[i];
            fades[i] = temp;
        }
    }
};

#endif //INFINITY_CUBE_ANIMATION_H
