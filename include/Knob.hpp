#include <stdint.h>

#ifndef KNOB_HPP
#define KNOB_HPP

class Knob
{
public:
    Knob(uint8_t &pin, uint8_t &debounce, uint16_t &targetRangeMin, uint16_t &targetRangeMax, uint8_t &smooth);
    void begin();
    void update();
    uint16_t get();

private:
    unsigned long lastCheck;
    uint16_t rawValue;
    
    uint8_t &pin;
    uint8_t &debounce;

    uint16_t &targetRangeMin;
    uint16_t &targetRangeMax;

    uint8_t &smooth;

    void initMessage();
    void read();
};

#endif
