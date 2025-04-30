#include <stdint.h>

#ifndef SOUND_SENSOR_HPP
#define SOUND_SENSOR_HPP

class SoundSensor
{
public:
    SoundSensor(uint8_t &pin, uint16_t &debounce, uint16_t &targetRangeMin, uint16_t &targetRangeMax, float &referenceVoltage);
    void begin();
    void update();
    long get();

private:
    unsigned long lastCheck;
    int rawValue;
    long smoothedValue;
    int baseLine;
    
    uint8_t &pin;
    uint16_t &debounce;

    uint16_t &targetRangeMin;
    uint16_t &targetRangeMax;

    float &referenceVoltage;

    void initMessage();
    void read();
};

#endif
