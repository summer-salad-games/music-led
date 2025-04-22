#include "Controller.hpp"

Controller::Controller() {}

void Controller::begin()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTAGE, MAX_CURRENT);
    FastLED.clear();
    delay(SETUP_DEBOUNCE);
    Serial.println("Controller initialized.");

}

void Controller::update()
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        FastLED.clear();
        leds[i] = CRGB(0, 255, 0);
        FastLED.show();
        delay(25);
    }

    for (int i = NUM_LEDS - 1; i >= 0; i--)
    {
        FastLED.clear();
        leds[i] = CRGB(0, 0, 255);
        FastLED.show();
        delay(25);
    }

    FastLED.show();
}
