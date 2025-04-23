#include "Controller.hpp"

Controller::Controller() {}

void Controller::begin()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTAGE, MAX_CURRENT);
    FastLED.clear();
    delay(SETUP_DEBOUNCE);
    Serial.println("Controller initialized.");
}

void Controller::update()
{
}

void Controller::setColor(CRGB &color, uint8_t &led)
{
    if (led > NUM_LEDS - 1)
    {
        led = NUM_LEDS - 1;
    }

    if (led < 0)
    {
        led = 0;
    }

    leds[led] = color;
    FastLED.show();
}

void Controller::fadeToColor(CRGB &color, uint8_t &led, unsigned long &duration)
{
    if (duration == 0)
    {
        duration = 1;
    }
    

    factor = (factor + 5) % 255;

    leds[led] = leds[led].lerp8(color, factor);

    FastLED.show();
    delay(duration);
}
