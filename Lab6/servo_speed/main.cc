#include <iostream>
#include "gpio.h"
#include <cmath>

int main() {

  int servo = 1;
  float start = 0;
  float end = 0;
  float speed = 0;
  std::cerr << "Which servo you want to move?\n"
               "  1. Base \n" 
               "  2. Bicep \n" 
               "  3. Elbow \n" 
               "  4. Wrist \n" 
               "  5. Gripper \n" ;
  std::cin >> servo;

  std::cerr << "What start angle?\n";
  std::cin >> start;
  std::cerr << "What end angle?\n";
  std::cin >> end;
  std::cerr << "What speed (degree/sec)?\n";
  std::cin >> speed;

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
  
  int pulse = (start*10) + 600;
  int period = 20000;
  int num_periods = 50;
  gpio.GeneratePWM(period, pulse, num_periods);
  pulse = (end*10) + 600;
  period = ((std::abs(end - start)/speed)*1000000+1000000)/50;
  gpio.GeneratePWM(period, pulse, num_periods);

  return 0;
}
