#include <Arduino.h>
#include <MillisDelay.h>

MillisDelay::MillisDelay(): prevMillis(0) {};

void MillisDelay::executeTask(void (*fn)(), unsigned long duration) {
    if (millis() - prevMillis >= duration) {
        prevMillis = millis();
        fn();
    }
}