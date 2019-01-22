# Lab 2 Report

The second lab tasked us with writing a program to alter the size and contents of an array using dynamic memory. The instructions were to create a menu of options for users to alter the array based on their own input.

### Pre-lab

I began this lab by creating my prelab. This essentially involved coding the menu of options for the lab. After the user input a choice, it would send back a basic response and redisplay the menu. The only functions created at this time was Initialize(), which created the array that would be used in this program, and Print(), which was identical to the print function in the previous lab.

Below is a screenshot of the output of the pre-lab:

![prelab](https://github.com/eece2160-fall17-s8/lab2-andrewteam/blob/master/lab2prelab.png?raw=true)

### Grow() Function

Following this, the first function I created was the Grow() function. This function's job was to increase the size of the array once all values were filled.

Here is the code for my Grow() function:

```c++
void Grow(int v[], int size) {
    size = size * 2; //function begins by doubling size variable
    int* nv = new int[size]; //creates a temporary array of the new size
    nv[size] = {0}; //initializes all values to zero
    std::copy(v, v + (size/2), nv); //copies values from original array to temp one
    v = new int[size]; //makes original array new size
    v[size]={0}; //initializes values
    v = nv; //gives original array values from temp
    delete[] nv; //deletes temp from memory
    std::cout<<"\nThe array reached its limit. Its size has now been doubled. \n";
    std::cout<<"Previous capacity: "<<size/2<<" elements \n";
    std::cout<<"New capacity: "<<size<<" elements \n";
}
```

### Append() Function

The next function I wrote was the Append() function. This function worked to add new elements to the array. What the function did was cycle through the array until it found the first empty value, and then fill that with the user selected number. When all the spaces in the array were filled, it would invoke the grow function.

Here is the code for my Append() function:

```c++
void Append(int v[], int size) {
    for(int i = 0; i < size; i++){ //starts with basic i loop
    if(v[i] < 1){ //once we find an array value that is zero
        std::cout << "Insert New Value: ";
        std::cin >> v[i]; //insert the user chosen new value into it
        break;
    }
    else{ //if the value isn't zero, continue loop without doing anything
    }
    }
}
```
### Remove() Function

The remove function was one of the trickiest to write, since it involved shifting all the values down to fill in the function that was removed. The user input a value, and then the program shifted all values down to meet that index, and then deleted the value of the highest index.

Here is my code for the Remove() function:

```c++
void Remove(int index) {
    if (index > size - 1){ //the operation won't work if the inputted value is larger than any value in the array
        std::cout<<"\nOperation failed. Position not legitimate. \n";
    }
    else{
                for (int i = (index + 1); i<size; i++ ){ //start at the indexed value, moving up until we reach the array max
                    v[i-1]=v[i]; //make the value above into the current value, effectively "removing" the index value
                }
		v[size-1] = 0; //set the last value in the array to zero, so that the last value isn't just a copy of the second to last value
                std::cout<<"\nElement successfully deleted!\n";
            }
        }
```

### Insert() Function

The final function of the program was the Insert() function. Insert() was essentially the same as Remove(), but worked in the opposite fashion. Instead of starting from the lowest index and working its way up, the Insert() started at the max and moved every function up until it reached the inputted index value.

Here is the code for my Insert() function:

```c++
void Insert(int index, double number) {
    if (index > size - 1){ //like remove, cannot have a value larger than array size
        std::cout<<"\nOperation failed. Position not legitimate. \n";
    }
    else{
    for (int i = size; i > index; i--){ //start at max, move down to index value
        v[i] = v[i-1]; //set every current value to the one less than it
    }
    v[index] = number; //then set index value to the user entered new number
    std::cout<<"\nInsertion successful!\n";
    }
}
```

All these functions combined to form the entirety of the program.
