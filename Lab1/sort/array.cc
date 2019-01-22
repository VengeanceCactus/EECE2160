#include <iostream>
using namespace std;

void PrintArray(int v[], int size){
	for (int i = 0; i < size; i++){
		cout << v[i] << "\n";
	}
}

void InputArray(int v[], int size){
    cout << "Input 10 numbers between 0 and 100:"<<"\n";
	for (int i = 0; i< size; i++){
		cin >> v[i];
		if (v[i]>100){
            cout << "Enter a number less than 100, playa! \n";
            cin >>v[i];
		}
	}
	cout <<"\n";
}

void SortArray(int v[], int size){
    for(int i=0; i < size; i++)
    {
        for(int j = i+1;j < size; j++)
        {
            if(v[i]>v[j])
            {
                int temp = v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    }

int main(){
    int size = 10;
    int thing[size];
    InputArray(thing, size);
    SortArray(thing, size);
    PrintArray(thing, size);
}
