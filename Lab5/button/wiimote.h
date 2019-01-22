#ifndef WIIMOTE_H_
#define WIIMOTE_H_

/**
 * Wiimote encapsulates the interaction with the wiimote hardware
 */
class Wiimote {

  int fd;

  void PrintButtonEvent(int code, int value);

 public:

  /**
   * The Constructor opens the virtual file
   */
  Wiimote();

  /**
   * The Destructor closes the virtual file
   */
  ~Wiimote();

  /**
   * Listen runs an infinite loop that keeps listening to button events
   */
  void Listen();
};

#endif  // WIIMOTE_H_
