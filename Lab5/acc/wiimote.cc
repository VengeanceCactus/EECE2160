#include "wiimote.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
// Implement functions here

void Wiimote::PrintAccEvent(int code, int acceleration){
	std::cout<<"Event: code ="<<code<<", acceleration ="<<acceleration<<"\n";
}

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
		PrintAccEvent(code, acceleration);
}
}
