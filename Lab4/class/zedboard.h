class Zedboard {
  char *ptr;
  int fd;
  
public:

  ZedBoard(){
  
  }
  
  ~ZedBoard(){
  
  }
  
  void RegisterWrite(int offset, int value){
  
  }
  
  void RegisterRead(int offset){
  
  }
  
  void SetLedState(char *ptr, int led_index, int state) {
  switch(led_index){
	case 0: {
		RegisterWrite(gpio_led1_offset, state);
	        }
	case 1: {
		RegisterWrite(gpio_led2_offset, state);
	        }
	case 2: {
		RegisterWrite(gpio_led3_offset, state);
	        }
	case 3: {
    		RegisterWrite(gpio_led4_offset, state);
          }
	case 4: {
    		RegisterWrite(gpio_led5_offset, state);
          }
	case 5: {
   	 	RegisterWrite(gpio_led6_offset, state);
         	}
	case 6: {
	  	RegisterWrite(gpio_led7_offset, state);
         	}
	case 7: {
    		RegisterWrite(gpio_led8_offset, state);
        	}
}
}
  
  }
