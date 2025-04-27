#include "LedStrip.hpp"
#include "Button.hpp"
#include "Knob.hpp"

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller
{
public:
    Controller(LedStrip &ledStrip, Button &button, Knob &brightnessKnob, Knob &hueKnob);
    void begin();
    void update();

private:
    LedStrip &ledStrip;
    Button &button;

    Knob &brightnessKnob;
    Knob &hueKnob;

    uint16_t lastBrightnessValue;
    uint16_t lastHueValue;

    void initMessage();
};

#endif
