#include "hardware.h"

void setup_buttons(){
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
}

bool button_up_pressed(){
  return (digitalRead(BUTTON_UP) == LOW);
}

bool button_down_pressed(){
  return (digitalRead(BUTTON_DOWN) == LOW);
}