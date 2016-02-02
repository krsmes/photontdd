#ifndef TESTING // this is so CLion picks up the real application.h in the editor
//#include <application.h>
#endif

typedef enum PinMode {
    OUTPUT,
} PinMode;

enum PinState {
    LOW = 0,
    HIGH = 1
};

void pinMode(short pin, int mode);
void digitalWrite(short pin, int value);


#include <gmock/gmock.h>

class ParticleMock {
public:
    MOCK_METHOD2(pinMode, void (short, int));
    MOCK_METHOD2(digitalWrite, void (short, int));
};

ParticleMock* getParticleMock();
void releaseParticleMock();
