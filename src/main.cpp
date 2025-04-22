#include "Controller.hpp"

constexpr uint8_t LOOP_DEBOUNCE = 0;
constexpr uint8_t SETUP_DEBOUNCE = 0;

Controller controller;

void setup()
{
    Serial.begin(9600);
    while (!Serial);

    controller.begin();
    delay(SETUP_DEBOUNCE);
}

void loop()
{
    controller.update();
    delay(LOOP_DEBOUNCE);
}
