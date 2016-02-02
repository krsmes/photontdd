#include "LEDFlasher.h"
#include "dependencies.h"

void LEDFlasher::setup(int pin) {
    this->pin = pin;
    pinMode(pin, OUTPUT);
}

void LEDFlasher::update(unsigned int millis) {
    digitalWrite(pin, HIGH);
}
