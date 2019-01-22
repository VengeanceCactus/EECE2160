#include <iostream>
int *v;
int size = 2;

void Initialize() {
	v = new int[size];
    	v[size] = {0};
}

void Finalize() {}

void Grow(int v[], int size) {
    size = size * 2;
    int* nv = new int[size];
    nv[size] = {0};
    std::copy(v, v + (size/2), nv);
    v = new int[size];
    v[size]={0};
    v = nv;
    delete[] nv;
    std::cout<<"\nThe array reached its limit. Its size has now been doubled. \n";
    std::cout<<"Previous capacity: "<<size/2<<" elements \n";
    std::cout<<"New capacity: "<<size<<" elements \n";
}

void Append(int v[], int size) {
    for(int i = 0; i < size; i++){
    if(v[i] < 1){
        std::cout << "Insert New Value: ";
        std::cin >> v[i];
        break;
    }
    else{
    }
    }
}

void Remove(int index) {
    if (index > size - 1){
        std::cout<<"\nOperation failed. Position not legitimate. \n";
    }
    else{
                for (int i = (index + 1); i<size; i++ ){
                    v[i-1]=v[i];
                }
		v[size-1] = 0;
                std::cout<<"\nElement successfully deleted!\n";
            }
        }

void Insert(int index, double number) {
    if (index > size - 1){
        std::cout<<"\nOperation failed. Position not legitimate. \n";
    }
    else{
    for (int i = size; i > index; i--){
        v[i] = v[i-1];
    }
    v[index] = number;
    std::cout<<"\nInsertion successful!\n";
    }
}

void Print(int v[], int size) {

	for (int i = 0; i < size; i++){
		std::cout << v[i] << "\n";
	}

}


int main() {
	delete[] v;
	int choice = 0;
	double number;
	int index;
    Initialize();
	while (choice != 5){
		std::cout << "\nMain Menu: \n \n"
		<< "    1. Print the array \n"
		<< "    2. Append element at the end \n"
		<< "    3. Remove one element \n"
		<< "    4. Insert one element \n"
		<< "    5. Exit \n\n"
		<< "Select an option: ";

		std::cin >> choice;

		if (choice == 1){
			Print(v, size);
		}
		else if (choice == 2){
			if (v[size-1] < 1){
                Append(v, size);
            }
            else{
                Grow(v, size);
                size = size * 2;
            }
		}
		else if (choice == 3){
            std::cout<<"What is the position of the element you wish to remove? ";
            std::cin>>index;
			Remove(index);
		}
		else if (choice == 4){
            if (v[size-1] < 1){
            std::cout<<"Please input a new element to be inserted: ";
            std::cin>>number;
            std::cout<<"Where will the new element go? ";
            std::cin>>index;
			Insert(index, number);
            }
            else{
                Grow(v, size);
                size = size * 2;
            }
		}
		else if (choice == 5){
			Finalize();
		}
		else{
			std::cout << "Please choose a real option! You're not getting out of this one! \n";
		}
	}
	std::cout << "Thanks for playing! It's been fun. \n";
return -1; }
