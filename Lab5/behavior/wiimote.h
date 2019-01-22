#ifndef WIIMOTE_H_
#define WIIMOTE_H_

#include "acc_event_handler.h"
#include "acc_event_printer.h"
/**
 * Wiimote encapsulates the interaction with the wiimote hardware
 */
class Wiimote : public AccEventPrinter {

int fd;

public:

Wiimote();

~Wiimote();

void Listen();

};

#endif  // WIIMOTE_H_
