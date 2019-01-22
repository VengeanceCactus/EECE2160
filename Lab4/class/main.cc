#include "ZedBoard.h"
#include <iostream>


int main(){

    ZedBoard zb;
    int value;
    std::cin>>value;
    zb.SetLedValue(value);
    return 0;

}
