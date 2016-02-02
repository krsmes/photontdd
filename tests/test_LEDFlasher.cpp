#include "../LEDFlasher.h"
#include "ParticleMock.h"

class test_LEDFlasher : public ::testing::Test {
public:
    LEDFlasher subject;
};


TEST_F(test_LEDFlasher, setup_should_accept_led_pin) {
    EXPECT_CALL(*getParticleMock(), pinMode(7, OUTPUT));
    subject.setup(7);
    releaseParticleMock();
}


TEST_F(test_LEDFlasher, update_should_set_pin_high) {
    subject.setup(5);
    EXPECT_CALL(*getParticleMock(), digitalWrite(5, HIGH));
    subject.update(0);
    releaseParticleMock();
}
