#ifndef LED_H
#define LED_H

class LED {
    public:
        LED(const int pin);
        void blink(int loop, int duration);
    private:
        const int _pin;
};

#endif