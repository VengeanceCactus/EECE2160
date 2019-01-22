### LED Set Problem

For this task, we had to write a function to set an LED on our Zedboard based on user entry. A user would enter a number from 0-7 and in turn our Zedboard would light up that particular LED. 

This worked by an input in the main funcion, and a switch in our SetLedState function that took the input and wrote a particular value to the LED via the RegisterWrite function.

```C++
void SetLedState(char *ptr, int led_index, int state) {
  switch(led_index){ //switch takes in the user inputted led_index variable
	case 0: { //based on the value of the led_index, we set a certain LED with either a 1 or a 0, depending on the state value
		RegisterWrite(ptr, gpio_led1_offset, state);
	}
	case 1: {
		RegisterWrite(ptr, gpio_led2_offset, state);
	}
	case 2: {
		RegisterWrite(ptr, gpio_led3_offset, state);
	}
	case 3: {
    		 RegisterWrite(ptr, gpio_led4_offset, state);
        }
	case 4: {
    		 RegisterWrite(ptr, gpio_led5_offset, state);
        }
	case 5: {
    		 RegisterWrite(ptr, gpio_led6_offset, state);
    	}
	case 6: {
	    	 RegisterWrite(ptr, gpio_led7_offset, state);
    	}
	case 7: {
    		 RegisterWrite(ptr, gpio_led8_offset, state);
   	}
}
}
```

Video: https://www.youtube.com/watch?v=9GT9sf7yvis
