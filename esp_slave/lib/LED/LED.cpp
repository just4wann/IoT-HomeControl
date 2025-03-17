#include <Arduino.h>
#include <LED.h>

LED::LED(const int pin): _pin(pin) {
  pinMode(_pin, OUTPUT);
};

void LED::blink(int loop, int duration) {
  for (int i = 0; i < loop; i++) {
    digitalWrite(2, true);
    delay(duration);
    digitalWrite(2, false);
    delay(duration);
  }
}