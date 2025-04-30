#include <FastLED.h>

#ifndef LEDSTRIP_HPP
#define LEDSTRIP_HPP

class LedStrip
{
public:
    LedStrip(uint8_t &hue);
    void begin();
    void update();
    void setHue(uint8_t &hue);
    void setBrightness(uint8_t &brightness);
    void cycleMode();
    void setSoundIntensity(unsigned long &soundIntensity);

private:
    enum Mode
    {
        START,
        END,
        EDGES,
        CENTER
    };

    static const uint8_t NUM_LEDS = 60;
    static const uint8_t INIT_BRIGHTNESS = 255;
    static const uint8_t DATA_PIN = 11;
    static const uint8_t MAX_VOLTAGE = 5;
    static const uint16_t MAX_CURRENT = 2000;

    Mode currentMode = Mode::START;
    CRGB INIT_COLOR = CRGB::Red;
    CRGB leds[NUM_LEDS];
    uint8_t &hue;

    void initColor();
    void initMessage();
};

#endif
