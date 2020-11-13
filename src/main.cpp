#include <Arduino.h>
#include <FastLED.h>
#include "constants.h"
#include "strip.h"
#include "helper.h"

CRGB leds[NUM_LEDS];
Strip<STRIP_SIZE>* strip;

void setup() {
    delay(3000);
    Serial.begin(115200);
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(BRIGHTNESS);

    CRGB **pointers = getSegmentFromIndex(leds, 0);
    strip = new Strip<STRIP_SIZE>(pointers);
    delete[] pointers;

    Serial.println(strip->getLength());
}

void loop() {
    strip->setUniformCRGB(CRGB(random(255), random(255), random(255)));
    FastLED.show();
    delay(50);
}