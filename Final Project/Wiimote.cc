#include "Wiimote.h"

#include <fcntl.h>
#include <cstdlib>
#include <iostream>

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

int Wiimote::Listen() {

	int code = 0;
	while(code == 0){
		char buffer[32];
		read(fd, buffer, 32);
		code = buffer[10];
		int value = buffer[12];
		if (code == 60 || code == 105 || code == 103 || code == 106){
			break;
		}
		break;
	}
}
