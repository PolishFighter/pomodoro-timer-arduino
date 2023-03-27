#include <Arduino.h>
#include <Pomodoro.h>

Pomodoro timer;

void setup() {
  timer.init();
}

void loop() {
  timer.update();
}