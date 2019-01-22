#include "wiimote.h"
#include "acc_event_printer.h"
#include <fcntl.h>
#include <cstdlib>
#include <iostream>

Wiimote::Wiimote(){
	fd = open("/dev/input/event0", O_RDONLY);
	if(fd == -1){
		std::cerr<<"Error: could not open event file - forgot sudo?\n";
		exit(1);
	}
}

Wiimote::~Wiimote(){
	close(fd);
}

void Wiimote::Listen(){
	while(true){
		char buffer[32];
		read(fd, buffer, 32);
		int code = buffer[10];
		short acceleration = *(short *)(buffer + 12);
		AccEventPrinter acceventprinter;
		acceventprinter.PrintAccEvent(code, acceleration);
}
}


