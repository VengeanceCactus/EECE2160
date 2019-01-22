#include "wiimote.h"

#include <fcntl.h>
#include <cstdlib>
#include <iostream>

void Wiimote::PrintButtonEvent(int code, int value) {
  std::cout << "Event: code=" << code << ", value=" << value <<"\n";
}

Wiimote::Wiimote() {
  fd = open("/dev/input/event2", O_RDONLY);
  if (fd == -1){
	  std::cerr << "Error: Could not open event file - forgot sudo?\n";
	  exit(1);
  }
}

Wiimote::~Wiimote() {
  close(fd);
}

void Wiimote::Listen() {
  while(true){
    char buffer[32];
    read(fd, buffer, 32);
    int code = buffer[10];
    int value = buffer[12];
    PrintButtonEvent(code, value);
}
}
