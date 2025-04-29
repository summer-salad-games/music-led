#include "SoundSensor.hpp"
#include <Arduino.h>

SoundSensor::SoundSensor(uint8_t &pin, uint16_t &debounce, uint16_t &targetRangeMin, uint16_t &targetRangeMax, float &referenceVoltage)
    : pin(pin), debounce(debounce), targetRangeMin(targetRangeMin), targetRangeMax(targetRangeMax), referenceVoltage(referenceVoltage) {}

void SoundSensor::begin()
{
    baseLine = (1.25 / 5.0) * 1023.0;

    rawValue = analogRead(pin);
    lastCheck = millis();

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
    long result = map(abs(currentDifference), 0, baseLine, targetRangeMin, targetRangeMax);

    Serial.print("Raw: ");
    Serial.print(rawValue);

    Serial.print(", Base: ");
    Serial.print(baseLine);

    Serial.print(", Difference: ");
    Serial.print(abs(currentDifference));

    Serial.print(", Range min: ");
    Serial.print(targetRangeMin);

    Serial.print(", Range max: ");
    Serial.print(targetRangeMax);

    Serial.print(", Mapped: ");
    Serial.println(result);

    Serial.println();

    return result;
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