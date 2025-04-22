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

private:
    static constexpr uint8_t NUM_LEDS = 60;
    static constexpr uint8_t BRIGHTNESS = 255;
    static constexpr uint8_t DATA_PIN = 5;
    static constexpr uint16_t MAX_CURRENT = 2000;
    static constexpr uint8_t MAX_VOLTAGE = 5;
    static constexpr uint16_t SETUP_DEBOUNCE = 2000;
    
    CRGB leds[NUM_LEDS];
};

#endif
