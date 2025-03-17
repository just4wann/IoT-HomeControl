#include <BuiltinLED.h>
#include <Arduino.h>

BuiltinLED::BuiltinLED(int pin): _pin(pin) {
    pinMode(_pin, OUTPUT);
}

void BuiltinLED::blink(int loop, int duration) {
    for (int i = 0; i < loop; i++) {
        digitalWrite(_pin, true);
        vTaskDelay(duration / portTICK_PERIOD_MS);
        digitalWrite(_pin, false);
        vTaskDelay(duration / portTICK_PERIOD_MS);
    }
}

void BuiltinLED::steady() {
    digitalWrite(_pin, true);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
}