#include "SoundSensor.hpp"
#include <Arduino.h>

SoundSensor::SoundSensor(uint8_t &pin, uint16_t &samplePeriod, uint16_t &targetRangeMin, uint16_t &targetRangeMax, float &referenceVoltage)
    : pin(pin), samplePeriod(samplePeriod), targetRangeMin(targetRangeMin), targetRangeMax(targetRangeMax), referenceVoltage(referenceVoltage), signalMax(baseLine), signalMin(0), lastCheck(0), peakToPeak(0)
{
    baseLine = (referenceVoltage / 5.0) * 1023.0;
}

void SoundSensor::begin()
{
    initMessage();
}

void SoundSensor::update()
{
    read();
}

unsigned long SoundSensor::get()
{
    unsigned long result = map(peakToPeak, 0, baseLine, targetRangeMin, targetRangeMax);
    return result;
}

void SoundSensor::read()
{
    unsigned long currentTime = millis();

    if ((currentTime - lastCheck) < samplePeriod)
    {
        int16_t difference = analogRead(pin) - baseLine;
        uint16_t sample = abs(difference);

        if (sample < signalMin)
            signalMin = sample;
        if (sample > signalMax)
            signalMax = sample;
    }
    else
    {
        peakToPeak = signalMax - signalMin;

        signalMax = 0;
        signalMin = 1023;
        lastCheck = currentTime;
    }
}

void SoundSensor::initMessage()
{
    Serial.print("Sound Sensor on pin ");
    Serial.print(pin);
    Serial.print(" and sample period ");
    Serial.print(samplePeriod);
    Serial.println(" initialized. ");
}