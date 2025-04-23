#include <Arduino.h>
#include <FastLED.h>

#ifndef LED_HPP
#define LED_HPP

class Led
{
public:
    Led(CRGB &led, uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t brightness = 255);
    void on();
    void off();

    void setColor(uint8_t red, uint8_t green, uint8_t blue, unsigned long duration);
    void setBrightness(uint8_t brightness, unsigned long duration);

    uint8_t getBrightness() const;
    uint8_t getRed() const;
    uint8_t getGreen() const;
    uint8_t getBlue() const;

private:
    uint8_t colorAnimationFactor = 0;
    uint8_t brightnessAnimationFactor = 0;

    CRGB &led;
    uint8_t brightness;
    uint8_t red;
    uint8_t green;
    uint8_t blue;

    void apply();
};

#endif
