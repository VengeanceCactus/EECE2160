#include "wiimote.h"
#include "acc_event_printer.h"

int main() {
  Wiimote wiimote;
  AccEventPrinter acceventprinter;
  wiimote.Listen();
  return 0;
}
