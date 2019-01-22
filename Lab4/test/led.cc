#include <cstdlib>
#include <iostream>

#define TEST_MODE

void RegisterWrite(char *ptr, int offset, int value);
int RegisterRead(char *ptr, int offset);

#define main old_main
#include "../led/led.cc"
#undef main

int led_state[8] = {0};

void RegisterWrite(char *ptr, int offset, int value) {
  if(ptr != (char *)gpio_address) {
    std::cerr << "GPIO Address not correct.\n";
    exit(-1);
  }

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
  SetLedState((char *)gpio_address, 0, 1);
  SetLedState((char *)gpio_address, 2, 1);
  SetLedState((char *)gpio_address, 4, 1);
  SetLedState((char *)gpio_address, 6, 1);
  AssertLEDState(0x55);

  SetLedState((char *)gpio_address, 1, 1);
  SetLedState((char *)gpio_address, 3, 1);
  SetLedState((char *)gpio_address, 5, 1);
  SetLedState((char *)gpio_address, 7, 1);
  AssertLEDState(0xff);

  return 0;
}

