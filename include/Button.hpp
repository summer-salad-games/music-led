#include <stdint.h>

#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button
{
public:
    Button(uint8_t &pin, uint8_t &debounce);
    void begin();
    void update();
    bool isPressed();

private:
    unsigned long lastCheck;
    bool ready;

    uint8_t &debounce;
    uint8_t &pin;

    void initMessage();
};

#endif
