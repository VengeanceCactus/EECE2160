### Switch Solution

For the switch problem, we were tasked to create a function that would read the values of the switches and light the leds based on the position of the switch. 

In this task, it was necessary to have a continually running function. The variable 'readval' was established to contain the value of each switch. As the function ran, the RegisterRead function would set the readval, which would then be output to the leds using the RegisterWrite function. The code for the function is so:

```C++
void SwitchToLed(char *ptr) {
  int readval; //establishes value used to set leds
  readval = RegisterRead(ptr, gpio_sw1_offset); //reads the switch value and then sets readval to either 0/1
  RegisterWrite(ptr, gpio_led1_offset, readval); //uses the 0/1 from readval to set the LED
  readval = RegisterRead(ptr, gpio_sw2_offset); //runs through remainder of switches
  RegisterWrite(ptr, gpio_led2_offset, readval);
  readval = RegisterRead(ptr, gpio_sw3_offset);
  RegisterWrite(ptr, gpio_led3_offset, readval);
  readval = RegisterRead(ptr, gpio_sw4_offset);
  RegisterWrite(ptr, gpio_led4_offset, readval);
  readval = RegisterRead(ptr, gpio_sw5_offset);
  RegisterWrite(ptr, gpio_led5_offset, readval);
  readval = RegisterRead(ptr, gpio_sw6_offset);
  RegisterWrite(ptr, gpio_led6_offset, readval);
  readval = RegisterRead(ptr, gpio_sw7_offset);
  RegisterWrite(ptr, gpio_led7_offset, readval);
  readval = RegisterRead(ptr, gpio_sw8_offset);
  RegisterWrite(ptr, gpio_led8_offset, readval);
}
```

Video: https://www.youtube.com/watch?v=IQFQNG68dy4
