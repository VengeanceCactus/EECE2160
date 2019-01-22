#include "zedboard.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

ZedBoard::ZedBoard() {
  fd = open("/dev/mem", O_RDWR);
  ptr = (char *)mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd,
                      gpio_address);
}

ZedBoard::~ZedBoard() {
  munmap(ptr, ZedBoard::gpio_size);
  close(fd);
}

void ZedBoard::WriteRegister(int offset, int value) {
  *(int *)(ptr + offset) = value;
}

int ZedBoard::ReadRegister(int offset) {
  return *(int *)(ptr + offset);
}

void ZedBoard::SetLed(int id, int value) {
  WriteRegister(gpio_led1_offset + id * 4, value);
}

void ZedBoard::SetLedByValue(int value) {
  WriteRegister(gpio_led1_offset, value % 2);
  WriteRegister(gpio_led2_offset, (value / 2) % 2);
  WriteRegister(gpio_led3_offset, (value / 4) % 2);
  WriteRegister(gpio_led4_offset, (value / 8) % 2);
  WriteRegister(gpio_led5_offset, (value / 16) % 2);
  WriteRegister(gpio_led6_offset, (value / 32) % 2);
  WriteRegister(gpio_led7_offset, (value / 64) % 2);
  WriteRegister(gpio_led8_offset, (value / 128) % 2);
}
