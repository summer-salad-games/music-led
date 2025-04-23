#include <Arduino.h>
#include <FastLED.h>

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller
{
public:
    Controller();
    void begin();
    void update();
    void setColor(CRGB &color, uint8_t &led);
    void fadeToColor(CRGB &color, uint8_t &led, unsigned long &duration);

private:
    static constexpr uint8_t NUM_LEDS = 60;
    static constexpr uint8_t BRIGHTNESS = 10;
    static constexpr uint8_t DATA_PIN = 5;
    static constexpr uint8_t MAX_VOLTAGE = 5;
    static constexpr uint16_t MAX_CURRENT = 2000;
    static constexpr uint16_t SETUP_DEBOUNCE = 2000;

    CRGB color = CRGB::Black;
    uint8_t factor = 0;
    CRGB leds[NUM_LEDS];
};

#endif
