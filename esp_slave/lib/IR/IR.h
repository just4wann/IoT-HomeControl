#ifndef IR_H
#define IR_H

#include <LED.h>

class IR {
    public:
        IR(int irPin, LED& led);
        void begin();
        
        void irTVHandler(bool state);
        void irACHandler(bool state);
    private:
        int _irPin;

        LED _led;
};

#endif