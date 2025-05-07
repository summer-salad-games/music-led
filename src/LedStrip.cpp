#include "LedStrip.hpp"

LedStrip::LedStrip(uint8_t &hue) : hue(hue) {}

void LedStrip::begin()
{
    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(MAX_VOLTAGE, MAX_CURRENT);
    initColor();
    initMessage();
}

void LedStrip::update()
{
    if (rainbow && millis() > rainbowLastCheck + RAINBOW_DEBOUNCE)
    {
        hue = (hue + 1) % 256;
        rainbowLastCheck = millis();
    }
}

void LedStrip::setHue(uint8_t &newHue)
{
    if (newHue >= 240)
    {
        rainbow = true;
    }
    else
    {
        hue = newHue;
        rainbow = false;
    }
}

void LedStrip::setBrightness(uint8_t &beightness)
{
    FastLED.setBrightness(beightness);
    FastLED.show();
}

void LedStrip::setSoundIntensity(unsigned long &soundIntensity)
{
    FastLED.clear();

    uint8_t clamped = constrain(soundIntensity, 0, NUM_LEDS);
    int center = NUM_LEDS / 2;
    int half = clamped / 2;

    if (currentMode == CENTER)
    {
        for (int i = 0; i < half; i++)
        {
            leds[center - i - 1] = INIT_COLOR;
            leds[center - i - 1].setHue(hue);

            leds[center + i] = INIT_COLOR;
            leds[center + i].setHue(hue);
        }
    }

    if (currentMode == START)
    {
        for (int i = 0; i < clamped; i++)
        {
            leds[i] = INIT_COLOR;
            leds[i].setHue(hue);
        }
    }

    if (currentMode == EDGES)
    {
        for (int i = 0; i < half; i++)
        {
            leds[i] = INIT_COLOR;
            leds[i].setHue(hue);

            leds[NUM_LEDS - i - 1] = INIT_COLOR;
            leds[NUM_LEDS - i - 1].setHue(hue);
        }
    }

    if (currentMode == END)
    {
        for (int i = 0; i < clamped; i++)
        {
            int ledIndex = NUM_LEDS - 1 - i;
            leds[ledIndex] = INIT_COLOR;
            leds[ledIndex].setHue(hue);
        }
    }

    FastLED.show();
}

void LedStrip::initColor()
{
    FastLED.clear();
    FastLED.setBrightness(INIT_BRIGHTNESS);
    FastLED.setCorrection(TypicalLEDStrip);

    for (int i = 0; i < NUM_LEDS; i++)
    {
        leds[i] = INIT_COLOR;
    }

    FastLED.show();
}

void LedStrip::initMessage()
{
    Serial.print("LedStrip on pin ");
    Serial.print(DATA_PIN);
    Serial.println(" initialized");
}

void LedStrip::cycleMode()
{
    switch (currentMode)
    {
    case Mode::START:
        currentMode = Mode::END;
        break;
    case Mode::END:
        currentMode = Mode::EDGES;
        break;
    case Mode::EDGES:
        currentMode = Mode::CENTER;
        break;
    case Mode::CENTER:
        currentMode = Mode::START;
        break;
    default:
        currentMode = Mode::START;
    }
}