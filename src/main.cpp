#include <Arduino.h>
#include <FastLED.h>
#include "cube.h"
#include "constants.h"
#include "stripcontroller.h"
#include "animation.h"

#define LED_PIN 4
#define BRIGHTNESS 255
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

StripController<4> *stripControllers[6];
Animation *animation;
CubeGradientFadeAnimation *cubeGradientFadeAnimation;
GradientFadeAnimation *gradientFadeAnimation;

void setup() {
    delay(3000);
    Serial.begin(115200);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(Cube::getInstance()->leds, NUM_LEDS)
            .setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
    Cube *cube = Cube::getInstance();
    animation = new CubeGradientFadeAnimation(nullptr);
}

void loop() {
    animation -> draw();
//    for (int i = 0; i < STRIP_SIZE * 4; ++i) {
//        for (int j = 0; j < 6; ++j) {
//            stripControllers[j] -> drawRangeGradient(CHSV(0,255,0), CHSV(42 * j,255,255), i, 10);
//        }
//        FastLED.show();
//        delay(20);
//        for (int j = 0; j < 6; ++j) {
//            stripControllers[j] -> drawRange(CRGB::Black, i, 10);
//        }
//    }
//    for (int i = 0; i < STRIP_SIZE; ++i) {
//        stripController.setStripLights(CRGB::Red, i);
//        FastLED.show();
//        delay(100);
//    }
//    for (int i = 0; i < STRIP_SIZE; ++i) {
//        stripController.setStripLights(CRGB::Black, i);
//        FastLED.show();
//        delay(100);
//    }
//    for (int i = 0; i < STRIP_SIZE / 2; ++i) {
//        cube -> FULL_CUBE -> setStripLights(CRGB::Red, i);
//        cube -> FULL_CUBE -> invert();
//        cube -> FULL_CUBE -> setStripLights(CRGB::Red, i);
//        cube -> FULL_CUBE -> invert();
//        FastLED.show();
//        delay(100);
//    }
//
//    cube -> FULL_CUBE -> invert();
//
//    FastLED.show();
//    delay(100);
//
//    for (int i = 0; i < STRIP_SIZE; ++i) {
//        cube -> FULL_CUBE -> setStripLights(CRGB::Black, i);
//        FastLED.show();
//        delay(100);
//    }
//
//    cube -> FULL_CUBE -> invert();
}