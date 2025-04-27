#include "Controller.hpp"

Controller::Controller(LedStrip &ledStrip, Button &button, Knob &brightnessKnob, Knob &hueKnob)
    : ledStrip(ledStrip), button(button), brightnessKnob(brightnessKnob), hueKnob(hueKnob) 
    {
        // TODO handle first knob values
        // TODO Fix buton
        // TODO handle init delays
    }

void Controller::begin()
{
    ledStrip.begin();
    button.begin();
    brightnessKnob.begin();
    hueKnob.begin();

    initMessage();
}

void Controller::update()
{
    ledStrip.update();
    button.update();
    brightnessKnob.update();
    hueKnob.update();

    if (button.isPressed())
    {
        Serial.println("Button is pressed");
    }

    uint16_t currentHueValue = hueKnob.get();
    if (lastHueValue != currentHueValue)
    {
        Serial.print("Hue: ");
        Serial.println(currentHueValue);

        lastHueValue = currentHueValue;
    }

    uint16_t currentBrightnessValue = brightnessKnob.get();
    if (lastBrightnessValue != currentBrightnessValue)
    {
        Serial.print("Brightness: ");
        Serial.println(currentBrightnessValue);

        lastBrightnessValue = currentBrightnessValue;
    }
}

void Controller::initMessage()
{
    Serial.println("Controller initialized");
}