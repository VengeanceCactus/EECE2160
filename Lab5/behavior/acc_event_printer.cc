#include "acc_event_printer.h"

#include <iostream>

void AccEventPrinter::PrintAccEvent(int code, int acceleration){
	std::cout<<"Event: code ="<<code<<", acceleration = "<<acceleration<<"\n";
}

AccEventPrinter::AccEventPrinter(){
}

AccEventPrinter::~AccEventPrinter(){
}
