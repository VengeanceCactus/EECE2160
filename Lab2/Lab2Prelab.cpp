#include <iostream>
int *v;
int size = 2;

void Initialize(){
	v = new int[size];
    	v[size] = {0};
}

void Finalize(){

}

void Print(int v[], int size) {

	for (int i = 0; i < size; i++){
		std::cout << v[i] << "\n";
	}

}

int main(){
	Initialize();
	int choice = 0;
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
		std::cout<<"This option will append the array \n";
		}
		else if (choice == 3){
            	std::cout<<"This option will remove an element \n";
		}
		else if (choice == 4){
            	std::cout<<"This option will insert an element \n";
           	}
		else if (choice == 5){
			Finalize();
		}
		else{
			std::cout << "Please choose a real option! You're not getting out of this one! \n";
		}
	}

}
