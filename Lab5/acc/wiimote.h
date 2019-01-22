#ifndef WIIMOTE_H_
#define WIIMOTE_H_

/**
 * Wiimote encapsulates the interaction with the wiimote hardware
 */
class Wiimote {

int fd;

void PrintAccEvent(int acceleration, int value);

public:

Wiimote();

~Wiimote();

void Listen();

};

#endif  // WIIMOTE_H_
