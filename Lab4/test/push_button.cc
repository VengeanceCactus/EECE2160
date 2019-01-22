#include <cstdlib>
#include <iostream>

#define TEST_MODE

void RegisterWrite(char *ptr, int offset, int value);
int RegisterRead(char *ptr, int offset);

#define main old_main
#include "../push_button/push_button.cc"
#undef main

int pb_state[5] = {0};
int led_state[8] = {0};
int sw_state[8] = {0};

int RegisterRead(char *ptr, int offset) {
  if (offset >= 0x14C && offset <= 0x168) {
    int i = (offset - 0x14C) / 4;
    return sw_state[i];
  } else if (offset >= 0x16C && offset <= 0x17C) {
    int i = (offset - 0x16C) / 4;
    return pb_state[i];
  } else {
    std::cerr << "Invalid register offset " << offset << "to read.";
  }
}

void RegisterWrite(char *ptr, int offset, int value) {
  if (offset >= 0x12C && offset <= 0x148) {
    int i = (offset - 0x12C) / 4;
    led_state[i] = value;
  } else {
    std::cerr << "Invalid register offset " << offset << "to write.";
  }
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
  
  PushButtonToLed(NULL);
  AssertLEDState(0);

  pb_state[2] = 1;
  PushButtonToLed(NULL);
  AssertLEDState(0x01);
  PushButtonToLed(NULL);
  AssertLEDState(0x01);

  pb_state[2] = 0;
  pb_state[0] = 1;
  PushButtonToLed(NULL);
  AssertLEDState(0x02);
  PushButtonToLed(NULL);
  AssertLEDState(0x02);

  pb_state[0] = 0;
  pb_state[1] = 1;
  PushButtonToLed(NULL);
  AssertLEDState(0x01);
  PushButtonToLed(NULL);
  AssertLEDState(0x01);

  pb_state[1] = 0;
  pb_state[3] = 1;
  PushButtonToLed(NULL);
  AssertLEDState(0x00);
  PushButtonToLed(NULL);
  AssertLEDState(0x00);

  sw_state[4] = 1;
  pb_state[3] = 0;
  pb_state[4] = 1;
  PushButtonToLed(NULL);
  AssertLEDState(0x10);
  PushButtonToLed(NULL);
  AssertLEDState(0x10);

  return 0;
}

