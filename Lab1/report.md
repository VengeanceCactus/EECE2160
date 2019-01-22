# Lab 1 Report

Our first lab involved the Zedboard and our lab computers. I began the lab by connecting the Zedboard to my computer and starting an SSH session to the device using MobaXterm. After inputting the username and password for the device, I began by copying over the lab startcode from Github.

### Assignment 1: Hello World

For the first assignment, I was tasked with writing a simple hello world program, compiling it, and running it. The program code was written as follows:

```c++

//hello world program
#include <iostream>

int main()
{
  std::cout<<"Hello World! \n";
}

```

The program outputted "Hello World!" with a line break. Here were the commands I used:

* Edited the code initially using the "vi" command
* Compiled it using the "g++" command, created file called a.out
* Ran it using "./" before the file name

Below is a screenshot of the commands and the output.

![Helloworld Screenshot](https://github.com/eece2160-fall17-s8/lab1-andrewteam/blob/master/Capture.PNG?raw=true)

### Assignment 2: Selection Sort

The second assignment had us write a far more complicated program. This program allowed users to input 10 integers from 0 to 100, and then sorted them from lowest to highest value. The sorting method used is called Selection Sort. Here is the code for this program:

```c++

#include <iostream> //allows input and output
using namespace std; //uses standard formatting throughout

void PrintArray(int v[], int size){ //first function, prints array after intialized and sorted
	for (int i = 0; i < size; i++){ //loop runs through numbers one at a time until the value of i reaches size
		cout << v[i] << "\n"; //outputs values of the array
	}
}

void InputArray(int v[], int size){ //second function, takes array input from user
    cout << "Input 10 numbers between 0 and 100:"<<"\n";
	for (int i = 0; i< size; i++){ //loops through until i reaches size
		cin >> v[i]; //takes input from user
		if (v[i]>100){ //prevents user from inputting value greater than 100
            cout << "Enter a number less than 100, playa! \n";
            cin >>v[i];
		}
	}
	cout <<"\n"; //adds final line break between inputted numbers and final sorted numbers
}

void SortArray(int v[], int size){ //final function, used to sort array
    for(int i=0; i < size; i++) //loops until i reaches size, i functions as "stationary" value
    {
        for(int j = i+1;j < size; j++) //loops until j reaches size, j functions as "searching" value
        {
            if(v[i]>v[j]) //loop that swaps smaller value forward in the array
            {
                int temp = v[i]; //uses temp so that i value is not lost
                v[i]=v[j]; //swaps large value for smaller one
                v[j]=temp; //swaps original i value for j value
            }
        }
    }
    }

int main(){ //here's where it all comes together!!
    int size = 10; //array size is set to 10 as instructed
    int thing[size]; 
    InputArray(thing, size); //values are inputted
    SortArray(thing, size); //values are sorted
    PrintArray(thing, size); //values are printed!!
}

```

This program took 10 numbers of input, and then outputted them in an organized array. The commands used for this program are as follows:

* Edited the code initially using the "vi" command
* Compiled it using the "g++" command
* Ran it using "./" before the file name

Below is a screenshot of the successful execution of the program.

![Helloworld Screenshot](https://github.com/eece2160-fall17-s8/lab1-andrewteam/blob/master/Capture1.PNG?raw=true)
