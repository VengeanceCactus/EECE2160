#include "wiimote.h"
#include "zedboard.h"
#include "acc_event_led_viewer.h"

int main() {
  Wiimote wiimote;
  Zedboard zedboard;
  wiimote.Listen();
  zedboard.SetLed();
  return 0;
}
