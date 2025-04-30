#include "SoundSensor.hpp"
#include <Arduino.h>

SoundSensor::SoundSensor(uint8_t &pin, uint16_t &debounce, uint16_t &targetRangeMin, uint16_t &targetRangeMax, float &referenceVoltage)
    : pin(pin), debounce(debounce), targetRangeMin(targetRangeMin), targetRangeMax(targetRangeMax), referenceVoltage(referenceVoltage), smoothedValue(0)
{
    baseLine = (referenceVoltage / 5.0) * 1023.0;
}

void SoundSensor::begin()
{
    initMessage();
}

void SoundSensor::update()
{
    if (millis() > lastCheck + debounce)
    {
        read();
    }
}

long SoundSensor::get()
{
    int currentDifference = rawValue - baseLine;
    long mapped = map(abs(currentDifference), 0, baseLine, targetRangeMin, targetRangeMax);

    smoothedValue = (smoothedValue * 3 + mapped) / 4;
    return smoothedValue;
}

void SoundSensor::read()
{
    rawValue = analogRead(pin);
    lastCheck = millis();
}

void SoundSensor::initMessage()
{
    Serial.print("Sound Sensor on pin ");
    Serial.print(pin);
    Serial.print(" and debounce ");
    Serial.print(debounce);
    Serial.println(" initialized. ");
}