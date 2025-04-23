#include "Led.hpp"

Led::Led(CRGB &led, uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness)
    : led(led), red(red), green(green), blue(blue), brightness(brightness)
{
    apply();
}

void Led::setColor(uint8_t red, uint8_t green, uint8_t blue, unsigned long duration)
{
    // TODO: Implement color animation
    this->red = red;
    this->green = green;
    this->blue = blue;
    apply();
}

void Led::setBrightness(uint8_t brightness, unsigned long duration)
{
    // TODO: Implement brightness animation
    this->brightness = brightness;
    apply();
}

void Led::on()
{
    led.red = red;
    led.green = green;
    led.blue = blue;
}

void Led::off()
{
    led.red = 0;
    led.green = 0;
    led.blue = 0;
}

uint8_t Led::getBrightness() const
{
    return brightness;
}

uint8_t Led::getRed() const
{
    return red;
}

uint8_t Led::getGreen() const
{
    return green;
}

uint8_t Led::getBlue() const
{
    return blue;
}

void Led::apply()
{
    led.red = (red * brightness) / 255;
    led.green = (green * brightness) / 255;
    led.blue = (blue * brightness) / 255;
}