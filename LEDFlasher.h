#ifndef PHOTONTDD_LEDFLASHER_H
#define PHOTONTDD_LEDFLASHER_H

class LEDFlasher {
public:
    void setup(int pin);

    void update(unsigned int millis);

private:
    int pin;
};

#endif //PHOTONTDD_LEDFLASHER_H
