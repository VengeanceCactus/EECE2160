#include <cstdlib>
#include <iostream>

#define TEST_MODE

void RegisterWrite(char *ptr, int offset, int value);
int RegisterRead(char *ptr, int offset);

#define main old_main
#include "../switch/switch.cc"
#undef main

int led_state[8] = {0};
int sw_state[8] = {0};

int RegisterRead(char *ptr, int offset) {
  int i = (offset - 0x14C) / 4;
  return sw_state[i];
}

void RegisterWrite(char *ptr, int offset, int value) {
  int i = (offset - 0x12C) / 4;
  led_state[i] = value;
}

void AssertLEDState(char state) {
  int mask = 1;
  for (int i = 0; i < 8; i++) {
    if (((state & mask)>>i) != led_state[i]) {
      std::cerr << "Error in led " << i << "\n";
      exit(-1);
    }
    mask = mask << 1;
  }
}

int main() {
  int value = 1;
  
  for (int i = 0; i < 8; i++) {
    sw_state[i] = 1;
    SwitchToLed((char *)gpio_address);
    AssertLEDState(value);
    value = (value << 1) + 1;
  }

  return 0;
}

