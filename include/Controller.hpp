#include "LedStrip.hpp"
#include "Button.hpp"
#include "Knob.hpp"
#include "SoundSensor.hpp"

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller
{
public:
    Controller(LedStrip &ledStrip, Button &button, Knob &brightnessKnob, Knob &hueKnob, SoundSensor &soundSensor);
    void begin();
    void update();

private:
    LedStrip &ledStrip;
    Button &button;

    Knob &brightnessKnob;
    Knob &hueKnob;

    SoundSensor &soundSensor;

    uint8_t lastBrightnessValue;
    uint8_t lastHueValue;

    unsigned long lastCheck;

    void initHueAndBrightness();
    void initMessage();
    void updateButton();
    void updateBrightness();
    void updateHue();
    void debugHueValue();
    void debugBrightnessValue();
};

#endif
