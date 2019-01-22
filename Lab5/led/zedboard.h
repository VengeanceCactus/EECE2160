#ifndef ZEDBOARD_H_
#define ZEDBOARD_H_

class ZedBoard {
 private:
  char *ptr;
  int fd;

  static const unsigned gpio_address = 0x400d0000;

  // Length of memory-mapped IO window
  static const unsigned gpio_size = 0xff;

  static const int gpio_led1_offset = 0x12C;  // Offset for LED1
  static const int gpio_led2_offset = 0x130;  // Offset for LED2
  static const int gpio_led3_offset = 0x134;  // Offset for LED3
  static const int gpio_led4_offset = 0x138;  // Offset for LED4
  static const int gpio_led5_offset = 0x13C;  // Offset for LED5
  static const int gpio_led6_offset = 0x140;  // Offset for LED6
  static const int gpio_led7_offset = 0x144;  // Offset for LED7
  static const int gpio_led8_offset = 0x148;  // Offset for LED8
  
  static const int gpio_sw1_offset = 0x14C;  // Offset for Switch 1
  static const int gpio_sw2_offset = 0x150;  // Offset for Switch 2
  static const int gpio_sw3_offset = 0x154;  // Offset for Switch 3
  static const int gpio_sw4_offset = 0x158;  // Offset for Switch 4
  static const int gpio_sw5_offset = 0x15C;  // Offset for Switch 5
  static const int gpio_sw6_offset = 0x160;  // Offset for Switch 6
  static const int gpio_sw7_offset = 0x164;  // Offset for Switch 7
  static const int gpio_sw8_offset = 0x168;  // Offset for Switch 8

  static const int gpio_pbtnl_offset = 0x16C;  // Offset for left push button
  static const int gpio_pbtnr_offset = 0x170;  // Offset for right push button
  static const int gpio_pbtnu_offset = 0x174;  // Offset for up push button
  static const int gpio_pbtnd_offset = 0x178;  // Offset for down push button
  static const int gpio_pbtnc_offset = 0x17C;  // Offset for center push button

  void WriteRegister(int offset, int value);
  int ReadRegister(int offset);

 public:
  ZedBoard();
  ~ZedBoard();
  void SetLed(int id, int value);
  void SetLedByValue(int value);
};

#endif  // ZEDBOARD_H_
