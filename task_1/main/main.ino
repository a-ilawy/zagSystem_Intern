#include "config.h"

void setup() {
  // put your setup code here, to run once:
  setup_leds();
  setup_buttons();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(button_up_pressed()){
    switch_led_up();
    delay(BUTTON_DELAY);
  }
  if( button_down_pressed()){
    switch_led_down();
    delay(BUTTON_DELAY);
  }

}