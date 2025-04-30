#include <stdint.h>

#ifndef SOUND_SENSOR_HPP
#define SOUND_SENSOR_HPP

class SoundSensor
{
public:
    SoundSensor(uint8_t &pin, uint16_t &samplePeriod, uint16_t &targetRangeMin, uint16_t &targetRangeMax, float &referenceVoltage);
    void begin();
    void update();
    unsigned long get();

private:
    unsigned long lastCheck;
    uint16_t peakToPeak;
    uint16_t baseLine;
    uint16_t signalMin;
    uint16_t signalMax;

    uint8_t &pin;
    uint16_t &samplePeriod;
    uint16_t &targetRangeMin;
    uint16_t &targetRangeMax;

    float &referenceVoltage;

    void initMessage();
    void read();
};

#endif
