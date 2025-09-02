#include "hardware.h"

int led_array[] = LED_ARRAY;
int current_led = 0;
int last_led = 0;
void setup_leds(){
  for(int i=0; i < NUMBER_OF_LEDS; i++){
    pinMode(led_array[i], OUTPUT);
  }
  digitalWrite(led_array[0], HIGH);
  current_led=0;
  last_led = 0;
}
void reset_leds(){
  for(int i=0; i < NUMBER_OF_LEDS; i++){
     digitalWrite(led_array[i], LOW);
  }
  digitalWrite(led_array[0], HIGH);
  current_led=0;
  last_led = 0;
}

int mapping_current_led_value(int current_led){
  if (current_led < 0) return 0;
  if (current_led >= NUMBER_OF_LEDS) return NUMBER_OF_LEDS-1;
  return current_led;
}

void switch_leds(int directions){
  digitalWrite(led_array[current_led], LOW);
 
  current_led+=directions;
  
  current_led = mapping_current_led_value(current_led);
 
  digitalWrite(led_array[current_led], HIGH);
}

void switch_led_up(){
  switch_leds(1);
}

void switch_led_down(){
  switch_leds(-1);
}

void shift_leds_up(){
  current_led++;
  current_led = mapping_current_led_value(current_led);
 
  digitalWrite(led_array[current_led], HIGH);
}

void shift_leds_down(){
  current_led = mapping_current_led_value(current_led);
  if (current_led!=0){
    digitalWrite(led_array[current_led], LOW);
    current_led--;
  }
}

int getRandomNumber(int index) {
  return random(0, index); // +1 so index is included
}

void switch_random_led(){
  digitalWrite(led_array[last_led], LOW);

  int led_index = 0; 

  while(led_index == last_led){
    led_index = getRandomNumber(NUMBER_OF_LEDS);
  }
  
  digitalWrite(led_array[led_index], HIGH);
  last_led = led_index;
}