#include "Controller.hpp"

uint8_t buttonPin = 12;
uint8_t buttonDebounce = 100;

uint8_t brightnessPin = A0;
uint8_t brightnessDebounce = 100;
uint16_t brightnessMinRange = 0;
uint16_t brightnessMaxRange = 255;
uint8_t brightnessSmooth = 100;

uint8_t huePin = A1;
uint8_t hueDebounce = 100;
uint16_t hueMinRange = 0;
uint16_t hueMaxRange = 255;
uint8_t hueSmooth = 100;

LedStrip ledStrip;
Button button(buttonPin, buttonDebounce);

Knob brightnessKnob(brightnessPin, brightnessDebounce, brightnessMinRange, brightnessMaxRange, brightnessSmooth);
Knob hueKnob(huePin, hueDebounce, hueMinRange, hueMaxRange, hueSmooth);

Controller controller(ledStrip, button, brightnessKnob, hueKnob);

void initSerial()
{
    Serial.begin(9600);
    while (!Serial);
}

void setup()
{
    initSerial();
    controller.begin();
}

void loop()
{
    controller.update();
}