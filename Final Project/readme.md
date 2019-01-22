# Andrew Ricci's Final Project: Rock Paper Scissors Game Using Wiimote and Zedboard LEDs

### Overview:

For my final project, I created a program that functions as a rock-paper-scissors game. The player uses the Wiimote to make selections, and the computer generates a random value for the computer's choice. The program determines the victor of the game, and lights an LED on the Zedboard if the player wins a particular round. The game runs for eight rounds, and after the rounds are completed, the program announces the winner as well as the outcomes of each round.

### Relevance

This project draws much of its subject matter from Labs 1, 4 and 5. Information from rounds is stored in arrays, and the zedboard is used to light LEDs and connect to our Wiimote. This project also contains elements of object oriented programming, as the Wiimote functionality is reserved to a separate C++ file. 

### Rock-Paper-Scissors Mechanics

Outside of the main function, there are three functions that are necessary for our Rock-Paper-Scissors game to work. 

The first is pwin. This function takes the player score array, the computer score array, and the round number from our main function. It uses these to add a 1 to the player array and a zero to the computer array for the particular round that the player just won.

```C++

void pwin(int pscore[], int cscore[], int round){ //inputs are player array, computer array, and round #
	pscore[round-1] = 1; //sets the player score for the round (-1 since the rounds start at 1 and array at 0) to a win
	cscore[round-1] = 0; //sets the computer score for the round to a loss

}
```

The second function, cwin, does a nearly identical function, but for a computer victory.

The third function is our print function. This is used to print the player array at the end of the game.

```C++

void Print(int v[]){ //takes array as input

	for (int i = 0; i < 8; i++){ //i increases as to total number of rounds
		std::cout << v[i] << "\n"; //outputs the value of the ith round in the array
	}

}
```

The rest of the game functionality is contained within the main function.

At the start of our main function, we declare our variables.

```C++

int round = 1; //sets the intial round value, this value increments after a loss or victory
	int player, comp; //these values represent the player and computer choices, 1-3 represent rock-paper-scissors
	int pscore[8] = {}, cscore[8] = {}; //initialize blank arrays for player and computer scores, these are updated through pwin and cwin functions
	int psum = 0, csum = 0; //player and computer totals
	int code = 0; //represents the button value from our wiimote
```
We then enter into our main while loop, which is essentially run for the entire game. We can break this loop down into four separate parts.

The first is our intial button input. This stage is a while loop that waits for the user to make a move selection, and ends when the user presses the home button, which is designated by the code "60".

```C++
while(code != 60){ //while home button is not pressed
			code = wiimote.Listen(); //our code value is derived from our wiimote listen function, explained in the wiimote functionality
			if(code == 105){ //if player presses left button
				player = 1; //1 is selected, representing rock
				std::cout<<"Your move is Rock\n"; //outputs the choice
				code = 0;
			}
			else if(code == 103){ //if player presses up button
				player = 2; //2 is selected, representing paper
				std::cout<<"Your move is Paper\n"; //outputs the choice
				code = 0;
			}
			else if(code == 106){ //if player presses right button
				player = 3; //3 is selected, representing scissors
				std::cout<<"Your move is Scissors\n"; //outputs the choice
				code = 0;
			}
			else{ //otherwise, the program waits for the player to press the proper buttons
			}
}
code = 0; //button value is reset
```

The second part of this main loop is our computer move selection. The program generates a random value for the computer choice, and then displays the choice.

```C++

		comp = (rand()%3 + 1); //rand function generates a value between 1 and 3
		if (comp == 1){ //if the option selected is rock
			std::cout<<"Computer move is Rock\n"; //outputs the choice
		}
		else if(comp == 2){
			std::cout<<"Computer move is Paper\n";
		}
		else if(comp == 3){
			std::cout<<"Computer move is Scissors\n";
}
```

The third part of the loop is the decision logic. This compares the player and computer values and determines who the winner is.

```C++

if((player == 1 && comp == 1) || (player == 2 && comp == 2) || (player == 3 && comp == 3)){ //if the values match
			//re-roll, round is not counted or progressed
			std::cout<<"You both chose the same move! Try again.\n\n";
		}
		else if(player == 1 && comp == 2 || player == 2 && comp == 3 || player == 3 && comp == 1){
			//comp win
			std::cout<<"You lose this round! Sorry bud.\n\n";
			cwin(pscore, cscore, round); //cwin function is activated, both arrays are updated
			csum++; //the computer total is increased by one
			round++; //the round number is increased by one
		}
		else if(player == 1 && comp == 3 || player == 2 && comp == 1 || player == 3 && comp == 2){
			//player win
			std::cout<<"You win this round!\n\n";
			pwin(pscore, cscore, round); //pwin function is activated, arrays are updated
			psum++; //player total is increased by one
			light(ptr, round); //the LED on the Zedboard is lit for the corresponding round, more explanation in LED section
			round++; //the round total is increased by one
}
```

The final part of our main loop is the continue section. The main purpose of this was to alleviate an issue in which the home button would be registered twice, and two round would pass when only one ought to.

```C++

std::cout<<"Press the A button to continue...\n";

		while(code != 48){ //while the value corresponding to the a button is not selected
			code = wiimote.Listen(); //wait for the a button to be pressed
}
```

### Wiimote Implementation

In order to use our Wiimote with the program, we implemented much of the Wiimote logic used from Lab 5. Our Wiimote functionality is contained in a separate file called Wiimote.cc, which our main program instantiates and calls.

```C++

#include "Wiimote.h"

#include <fcntl.h>
#include <cstdlib>
#include <iostream>

Wiimote::Wiimote() {
	fd = open("/dev/input/event2", O_RDONLY); //opens the event2 file, which contains the input information from our Wiimote
	if (fd == -1){
		std::cerr << "Error: Could not open event file - forgot sudo?\n"; //this function will not work without sudo
		exit(1);
	}
}

Wiimote::~Wiimote() {
	close(fd);
}

int Wiimote::Listen() { //our main program uses this to take Wiimote input information

	int code = 0;
	while(code == 0){ //loop runs while code is equal to 0
		char buffer[32];
		read(fd, buffer, 32);
		code = buffer[10]; //sets code to number value repesenting each button
		int value = buffer[12];
		if (code == 60 || code == 105 || code == 103 || code == 106){ //if code equals any of our relevant button values
			break; //end this function
		}
		break; //end it just in case!
	}
}
```

Our FinalProject.cc's main function begins by instantiating Wiimote.cc with the Wiimote wiimote; line, and then calls the listen function at the start of the first loop as well as between games to continue.

### LED Implementation

In order to implement our LEDs, we used a number of concepts from Lab 4. All of our LED functionality is contained in functions in our FinalProject.cc file.

We began by initializing the LED values and basic functionality for our code to work with the Zedboard.

```C++
const unsigned gpio_address = 0x400d0000; //we begin by assigning the gpio address and size to the program, so the offsets can be programmed relative to this
const unsigned gpio_size = 0xff;

const int gpio_led1_offset = 0x12C;  // Offset for LED1
const int gpio_led2_offset = 0x130;  // Offset for LED2
const int gpio_led3_offset = 0x134;  // Offset for LED3
const int gpio_led4_offset = 0x138;  // Offset for LED4
const int gpio_led5_offset = 0x13C;  // Offset for LED5
const int gpio_led6_offset = 0x140;  // Offset for LED6
const int gpio_led7_offset = 0x144;  // Offset for LED7
const int gpio_led8_offset = 0x148;  // Offset for LED8

void RegisterWrite(char *ptr, int offset, int value) { //our registerwrite function assigns the 0 or 1 value to our LED addresses
	*(int *)(ptr + offset) = value;
}

char *Initialize(int *fd) { //the intialize function opens the Zedboard's memory and establishes connection
	*fd = open("/dev/mem", O_RDWR);
	return (char *)mmap(NULL, gpio_size, PROT_READ | PROT_WRITE, MAP_SHARED, *fd,
			gpio_address);
}
```

Next is our light init function. This function sets all LEDs to off and is called at the very start of our main function.

```C++
void light_init(char *ptr){ //takes our pointer as input
	RegisterWrite(ptr, gpio_led8_offset, 0); //sets each LED to zero
	RegisterWrite(ptr, gpio_led7_offset, 0);
	RegisterWrite(ptr, gpio_led6_offset, 0);
	RegisterWrite(ptr, gpio_led5_offset, 0);
	RegisterWrite(ptr, gpio_led4_offset, 0);
	RegisterWrite(ptr, gpio_led3_offset, 0);
	RegisterWrite(ptr, gpio_led2_offset, 0);
	RegisterWrite(ptr, gpio_led1_offset, 0);
}
```

Finally, we have our main light function. This function turns an LED on based on the round of our game and whether or not the player has won.

```C++
void light(char *ptr, int round){ //our function takes the pointer and the round as inputs
	switch(round){ //based on the round, a particular case will be activated
		case 1: RegisterWrite(ptr, gpio_led8_offset, 1); //if round 1 is a player victory, LED8, the leftmost LED will be activated
			break; //once the LED is set, the function is broken
		case 2: RegisterWrite(ptr, gpio_led7_offset, 1); //this pattern continues from left to right as the rounds increase
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
```

Video Demonstration: https://youtu.be/BiBdg6H2uBo
