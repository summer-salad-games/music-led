#include "Controller.hpp"

uint8_t buttonPin = 12;
uint8_t buttonDebounce = 100;

uint8_t brightnessPin = A0;
uint8_t brightnessDebounce = 100;
uint16_t brightnessMinRange = 0;
uint16_t brightnessMaxRange = 255;
uint8_t brightnessSmooth = 33;

uint8_t huePin = A1;
uint8_t hueDebounce = 100;
uint16_t hueMinRange = 0;
uint16_t hueMaxRange = 255;
uint8_t hueSmooth = 33;

uint8_t soundSensorPin = A2;
uint16_t soundSensorSamplePeriod = 150;
uint16_t soundSensorMinRange = 0;
uint16_t soundSensorMaxRange = 60;
float soundSensorReferenceVoltage = 1.25;

LedStrip ledStrip;
Button button(buttonPin, buttonDebounce);
Knob brightnessKnob(brightnessPin, brightnessDebounce, brightnessMinRange, brightnessMaxRange, brightnessSmooth);
Knob hueKnob(huePin, hueDebounce, hueMinRange, hueMaxRange, hueSmooth);
SoundSensor soundSensor(soundSensorPin, soundSensorSamplePeriod, soundSensorMinRange, soundSensorMaxRange, soundSensorReferenceVoltage);

Controller controller(ledStrip, button, brightnessKnob, hueKnob, soundSensor);

void initSerial()
{
    Serial.begin(9600);
    while (!Serial);
    delay(1000);
    Serial.println("Serial console initilized");
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