#include <Arduino.h>

#define DECODE_NEC
#define DECODE_DISTANCE_WIDTH

#include <IRremote.hpp>
#include <IR.h>

IR::IR(int irPin, LED& led): _irPin(irPin), _led(led) {}

void IR::begin() {
    IrSender.begin(_irPin);
}

void IR::irTVHandler(bool state) {
    if (state) {
        Serial.println("TV ON");
        IrSender.sendNEC(0x40, 0x12, NO_REPEATS);
        _led.blink(5, 50);
    } else {
        Serial.println("TV OFF");
        IrSender.sendNEC(0x40, 0x12, NO_REPEATS);
        _led.blink(5, 50);
    }
}

void IR::irACHandler(bool state) {
    if (state) {
        uint64_t tRawData[]={0x72110510CF5AAA, 0x51F6008008};
        IrSender.sendPulseDistanceWidthFromArray(38, 3900, 1850, 500, 1350, 500, 400, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 0, NO_REPEATS);
        Serial.println("AC ON");
        _led.blink(5, 50);
    } else {
        uint64_t tRawData[]={0x72210510CF5AAA, 0x61F6008008};
        IrSender.sendPulseDistanceWidthFromArray(38, 3900, 1850, 500, 1350, 500, 400, &tRawData[0], 104, PROTOCOL_IS_LSB_FIRST, 0, NO_REPEATS);
        Serial.println("AC OFF");
        _led.blink(5, 50);
    }
}