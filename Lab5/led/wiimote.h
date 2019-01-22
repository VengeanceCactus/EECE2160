#ifndef WIIMOTE_H_
#define WIIMOTE_H_
#include "acc_event_led_viewer.h"
/**
 * Wiimote encapsulates the interaction with the wiimote hardware
 */
class Wiimote : public LedEventViewer {
  int fd;

  public:

  Wiimote();

  ~Wiimote();

  void Listen();
};

#endif  // WIIMOTE_H_
