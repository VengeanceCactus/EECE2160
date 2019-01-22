#ifndef ACC_EVENT_PRINTER_H_
#define ACC_EVENT_PRINTER_H_

#include "acc_event_handler.h"

class AccEventPrinter {

public:

  void PrintAccEvent(int code, int acceleration);


AccEventPrinter();

~AccEventPrinter();

};

#endif  // ACC_EVENT_PRINTER_H_
