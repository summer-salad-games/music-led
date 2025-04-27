#include "Knob.hpp"
#include <Arduino.h>

Knob::Knob(uint8_t &pin, uint8_t &debounce, uint16_t &targetRangeMin, uint16_t &targetRangeMax, uint8_t &smooth)
    : debounce(debounce), pin(pin), targetRangeMin(targetRangeMin), targetRangeMax(targetRangeMax), smooth(smooth) {}

void Knob::begin()
{
    rawValue = analogRead(pin);
    lastCheck = millis();

    initMessage();
}

void Knob::update()
{
    if (millis() > lastCheck + debounce)
    {
        read();
    }
}

uint16_t Knob::get()
{
    return map(1023 - rawValue, 0, 1023, targetRangeMin, targetRangeMax);
}

void Knob::read()
{
    int currentValue = analogRead(pin);
    int difference = currentValue - rawValue;

    if (abs(difference) > smooth)
    {
        Serial.print("Current: ");
        Serial.println(currentValue);

        Serial.print("Old: ");
        Serial.println(rawValue);

        Serial.print("Smooth: ");
        Serial.println(smooth);

        Serial.print("Difference: ");
        Serial.println(abs(difference));

        rawValue = currentValue;
        lastCheck = millis();
    }
}

void Knob::initMessage()
{
    Serial.print("Knob on pin ");
    Serial.print(pin);
    Serial.print(" and debounce ");
    Serial.print(debounce);
    Serial.println(" initialized. ");
}