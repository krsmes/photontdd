#include "ParticleMock.h"

static ParticleMock* particleMock = NULL;

ParticleMock* getParticleMock() {
    if (!particleMock) {
        particleMock = new ParticleMock();
    }
    return particleMock;
}

void releaseParticleMock() {
    if (particleMock) {
        delete particleMock;
        particleMock = NULL;
    }
}


void pinMode(short pin, int mode) {
    particleMock->pinMode(pin, mode);
}

void digitalWrite(short pin, int value) {
    particleMock->digitalWrite(pin, value);
}