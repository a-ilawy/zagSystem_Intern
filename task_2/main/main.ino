#include "config.h"
#include "hardware.h"

int mode_number = 1;
void setup() {
  // put your setup code here, to run once:
  setup_leds();
  setup_buttons();
  setup_segment_display();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(button_mode_pressed()){
    mode_number ++;
    if (mode_number > NUMBER_OF_MODES) mode_number=1;
    displayDigit(mode_number);
    reset_leds();
    delay(BUTTON_DELAY);
  }

  if(button_up_pressed()){
    switch(mode_number){
      case 1: switch_led_up();
        break;
      case 2: shift_leds_up();
        break;
      case 3: switch_random_led();
        break;
        default:  break;
    }
    
    delay(BUTTON_DELAY);
  }
  if( button_down_pressed()){
     switch(mode_number){
      case 1: switch_led_down();
        break;
      case 2: shift_leds_down();
        break;
      case 3: switch_random_led();
        break;
        default:  break;
    }
    
    delay(BUTTON_DELAY);
  }

 
}