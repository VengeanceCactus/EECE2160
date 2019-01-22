#include <iostream>
#include "gpio.h"

int main() {

  int servo = 1;
  int angle = 0;
  std::cerr << "Which servo you want to move?\n"
               "  1. Base \n" 
               "  2. Bicep \n" 
               "  3. Elbow \n" 
               "  4. Wrist \n" 
               "  5. Gripper \n" ;
  std::cin >> servo;

  std::cerr << "What angle?\n";
  std::cin >> angle;

  if(servo == 1){
	servo = 13;
  }
  else if(servo == 2){
	servo = 10;
  }
  else if(servo == 3){
	servo = 11;
  }
  else if(servo == 4){
  	servo = 12;
  }
  else if(servo == 5){
  	servo = 0;
  }	
  GPIO gpio(servo);
  int pulse = (angle*10) + 600;
  int period = 20000;
  int num_periods = 50;
  gpio.GeneratePWM(period, pulse, num_periods);
 
  return 0;
}
