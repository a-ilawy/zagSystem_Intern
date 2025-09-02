#include "hardware.h"

int led_array[] = LED_ARRAY;
int current_led = 0;
void setup_leds(){
  for(int i=0; i < NUMBER_OF_LEDS; i++){
    pinMode(led_array[i], OUTPUT);
  }
  digitalWrite(led_array[0], HIGH);
}

int mapping_current_led_value(int current_led){
  if (current_led < 0) return 0;
  if (current_led >= NUMBER_OF_LEDS) return NUMBER_OF_LEDS-1;
  return current_led;
}

void shift_leds(int directions){
  digitalWrite(led_array[current_led], LOW);
 
  current_led+=directions;
  
  current_led = mapping_current_led_value(current_led);
 
  digitalWrite(led_array[current_led], HIGH);
}

void switch_led_up(){
  shift_leds(1);
}

void switch_led_down(){
  shift_leds(-1);
}