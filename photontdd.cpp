#pragma SPARK_NO_PREPROCESSOR
#include "dependencies.h"
#include "LEDFlasher.h"

LEDFlasher flasher;

void setup() {
    flasher.setup(7);
}

void loop() {
    flasher.update(millis());
}
