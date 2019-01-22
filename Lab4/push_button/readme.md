### Push Button Solution

For the push button problem, we were tasked with writing a program to respond to the pressing of buttons on the zedboard. Each button press had a different function, and that function resulted in a reaction from the leds.

```C++
void PushButtonToLed(char *ptr) {
 
  int upval = 0; //values for each button are initialized at zero
  int downval = 0;
  int centval = 0;
  int rightval = 0;
  int leftval = 0;
 
  upval = RegisterRead(ptr, gpio_pbtnu_offset); //takes value from up button pointer
  if(upval > 0){ //if value is greater than zero, add one to the total value for the leds
  count++;
  }
  downval = RegisterRead(ptr, gpio_pbtnd_offset);
  if(downval > 0){ //if value is greater than zero, subtract one from the total led value
  count--;
  }
  centval = RegisterRead(ptr, gpio_pbtnc_offset);
  if(centval > 0){ //resets counter when pressed
    count = 0;
    }
  rightval = RegisterRead(ptr, gpio_pbtnr_offset);
  if(rightval > 0){ //to "shift leds right" the overall value is divided by two
    count = count / 2;
  }
  leftval = RegisterRead(ptr, gpio_pbtnl_offset);
  if(leftval > 0){ //to "shift leds left" overall value is multiplied by two
    count = count * 2;
  }
 
  SetLedNumber(ptr, count); //resulting "count" value (which is stored as a global variable) determines led value
}
```

Video demo: https://www.youtube.com/watch?v=XlFi0gjoWxY
