#include "Button.hpp"
#include <Arduino.h>

Button::Button(uint8_t &pin, uint8_t &debounce)
    : lastCheck(0), ready(true), debounce(debounce), pin(pin) {}

void Button::begin()
{
    pinMode(pin, INPUT_PULLUP);
    initMessage();
}

void Button::update()
{
    ready = digitalRead(pin) == HIGH;
}

bool Button::isPressed()
{
    if (ready && millis() > lastCheck + debounce)
    {
        ready = false;
        return digitalRead(pin) == LOW;
    }

    return false;
}

void Button::initMessage()
{
    Serial.print("Button on pin ");
    Serial.print(pin);
    Serial.print(" and debounce ");
    Serial.print(debounce);
    Serial.println(" initialized. ");
}