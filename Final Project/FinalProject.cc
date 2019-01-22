#include "Wiimote.h"
#include <iostream>
#include <cstdlib>
#include <fcntl.h>
#include <sys/mman.h>
#include <cstdio>
#include <unistd.h>

const unsigned gpio_address = 0x400d0000;
const unsigned gpio_size = 0xff;

const int gpio_led1_offset = 0x12C;  // Offset for LED1
const int gpio_led2_offset = 0x130;  // Offset for LED2
const int gpio_led3_offset = 0x134;  // Offset for LED3
const int gpio_led4_offset = 0x138;  // Offset for LED4
const int gpio_led5_offset = 0x13C;  // Offset for LED5
const int gpio_led6_offset = 0x140;  // Offset for LED6
const int gpio_led7_offset = 0x144;  // Offset for LED7
const int gpio_led8_offset = 0x148;  // Offset for LED8

void RegisterWrite(char *ptr, int offset, int value) {
	*(int *)(ptr + offset) = value;
}

char *Initialize(int *fd) {
	*fd = open("/dev/mem", O_RDWR);
	return (char *)mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED, *fd,
			gpio_address);
}

void pwin(int pscore[], int cscore[], int round){
	pscore[round-1] = 1;
	cscore[round-1] = 0;

}

void cwin(int pscore[], int cscore[], int round){
	cscore[round-1] = 1;
	pscore[round-1] = 0;

}

void Print(int v[]) {

	for (int i = 0; i < 8; i++){
		std::cout << v[i] << "\n";
	}

}

void light_init(char *ptr){
	RegisterWrite(ptr, gpio_led8_offset, 0);
	RegisterWrite(ptr, gpio_led7_offset, 0);
	RegisterWrite(ptr, gpio_led6_offset, 0);
	RegisterWrite(ptr, gpio_led5_offset, 0);
	RegisterWrite(ptr, gpio_led4_offset, 0);
	RegisterWrite(ptr, gpio_led3_offset, 0);
	RegisterWrite(ptr, gpio_led2_offset, 0);
	RegisterWrite(ptr, gpio_led1_offset, 0);
}

void light(char *ptr, int round){
	switch(round){
		case 1: RegisterWrite(ptr, gpio_led8_offset, 1);
			break;
		case 2: RegisterWrite(ptr, gpio_led7_offset, 1);
			break;
		case 3: RegisterWrite(ptr, gpio_led6_offset, 1);
			break;
		case 4: RegisterWrite(ptr, gpio_led5_offset, 1);
			break;
		case 5: RegisterWrite(ptr, gpio_led4_offset, 1);
			break;
		case 6: RegisterWrite(ptr, gpio_led3_offset, 1);
			break;
		case 7: RegisterWrite(ptr, gpio_led2_offset, 1);
			break;
		case 8: RegisterWrite(ptr, gpio_led1_offset, 1);
			break;
			}
	}

int main(){

	Wiimote wiimote;

	int fd;
	char *ptr = Initialize(&fd);

	//1 = rock, 2 = paper, 3 = scissors
	int round = 1;
	int player, comp;
	int pscore[8] = {}, cscore[8] = {};
	int psum = 0, csum = 0;
	int code = 0;
	light_init(ptr);

	while(round < 9){
		std::cout<<"Please choose your move:\nLeft = Rock\nUp = Paper\nRight = Scissors\n";
		std::cout<<"Lock in your move with the Home button\n\n";
		while(code != 60){
			code = wiimote.Listen();
			if(code == 105){
				player = 1;
				std::cout<<"Your move is Rock\n";
				code = 0;
			}
			else if(code == 103){
				player = 2;
				std::cout<<"Your move is Paper\n";
				code = 0;
			}
			else if(code == 106){
				player = 3;
				std::cout<<"Your move is Scissors\n";
				code = 0;
			}
			else{
			}
		}
		code = 0;
		comp = (rand()%3 + 1);
		if (comp == 1){
			std::cout<<"Computer move is Rock\n";
		}
		else if(comp == 2){
			std::cout<<"Computer move is Paper\n";
		}
		else if(comp == 3){
			std::cout<<"Computer move is Scissors\n";
		}
		if((player == 1 && comp == 1) || (player == 2 && comp == 2) || (player == 3 && comp == 3)){
			//re-roll
			std::cout<<"You both chose the same move! Try again.\n\n";
		}
		else if(player == 1 && comp == 2 || player == 2 && comp == 3 || player == 3 && comp == 1){
			//comp win
			std::cout<<"You lose this round! Sorry bud.\n\n";
			cwin(pscore, cscore, round);
			csum++;
			round++;
		}
		else if(player == 1 && comp == 3 || player == 2 && comp == 1 || player == 3 && comp == 2){
			//player win
			std::cout<<"You win this round!\n\n";
			pwin(pscore, cscore, round);
			psum++;
			light(ptr, round);
			round++;
		}

		std::cout<<"Press the A button to continue...\n";

		while(code != 48){
			code = wiimote.Listen();
		}
	}
	std::cout<<"Player score is "<<psum<<"\n";
	std::cout<<"Computer score is "<<csum<<"\n";
	std::cout<<"Round history:\n";
	Print(pscore);

	if (psum > csum){
		std::cout<<"You win! Congratulations!\n";
	}
	else if (csum > psum){
		std::cout<<"You lose! Try again, homie.\n";
	}
	else if (psum = csum){
		std::cout<<"Tie game!\n";
	}
}
