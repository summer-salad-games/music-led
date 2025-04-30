#include "LedStrip.hpp"

LedStrip::LedStrip() {}

void LedStrip::begin()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTAGE, MAX_CURRENT);
    initColor();
    initMessage();
}

void LedStrip::update()
{
}

void LedStrip::setMode(uint8_t &mode)
{
}

void LedStrip::setHue(uint8_t &hue)
{
    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i].setHue(hue);
    }
    FastLED.show();
}

void LedStrip::setBrightness(uint8_t &beightness)
{
    FastLED.setBrightness(beightness);
    FastLED.show();
}

void LedStrip::setSoundIntensity(unsigned long &soundIntensity)
{
    FastLED.clear();

    for (int i = 0; i < soundIntensity; i++)
    {
        leds[i] = INIT_COLOR;
    }

    FastLED.show();

}

void LedStrip::initColor()
{
    FastLED.clear();
    FastLED.setBrightness(INIT_BRIGHTNESS);
    FastLED.setCorrection(TypicalLEDStrip);

    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = INIT_COLOR;
    }

    FastLED.show();
}

void LedStrip::initMessage()
{
    Serial.print("LedStrip on pin ");
    Serial.print(DATA_PIN);
    Serial.println(" initialized");
}