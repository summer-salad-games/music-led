#include "Controller.hpp"

Controller::Controller(LedStrip &ledStrip, Button &button, Knob &brightnessKnob, Knob &hueKnob, SoundSensor &soundSensor)
    : ledStrip(ledStrip), button(button), brightnessKnob(brightnessKnob), hueKnob(hueKnob), soundSensor(soundSensor), lastSoundValue(0) {}

void Controller::begin()
{
    ledStrip.begin();
    button.begin();
    brightnessKnob.begin();
    hueKnob.begin();
    soundSensor.begin();

    initHueAndBrightness();
    initMessage();
}

void Controller::update()
{
    ledStrip.update();
    button.update();
    brightnessKnob.update();
    hueKnob.update();
    soundSensor.update();

    updateSound();
    updateButton();
    updateHue();
    updateBrightness();
}

void Controller::initHueAndBrightness()
{
    lastHueValue = hueKnob.get();
    lastBrightnessValue = brightnessKnob.get();
    ledStrip.setHue(lastHueValue);
    ledStrip.setBrightness(lastBrightnessValue);
}

void Controller::updateSound()
{
    unsigned long sound = soundSensor.get();
    long soundChange = lastSoundValue - sound;

    if (abs(soundChange) >= 2)
    {
        lastSoundValue = sound;
        ledStrip.setSoundIntensity(lastSoundValue);
    }
}

void Controller::initMessage()
{
    Serial.println("Controller initialized");

    debugHueValue();
    debugBrightnessValue();
}

void Controller::updateButton()
{
    if (button.isPressed())
    {
        ledStrip.cycleMode();
        Serial.println("Button is pressed");
    }
}

void Controller::updateHue()
{
    uint16_t currentHueValue = hueKnob.get();
    if (lastHueValue != currentHueValue)
    {
        lastHueValue = currentHueValue;
        ledStrip.setHue(lastHueValue);
        debugHueValue();
    }
}

void Controller::updateBrightness()
{

    uint16_t currentBrightnessValue = brightnessKnob.get();
    if (lastBrightnessValue != currentBrightnessValue)
    {
        lastBrightnessValue = currentBrightnessValue;
        ledStrip.setBrightness(lastBrightnessValue);
        debugBrightnessValue();
    }
}

void Controller::debugHueValue()
{
    Serial.print("Hue: ");
    Serial.println(lastHueValue);
}

void Controller::debugBrightnessValue()
{
    Serial.print("Brightness: ");
    Serial.println(lastBrightnessValue);
}