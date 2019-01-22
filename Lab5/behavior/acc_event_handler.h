#ifndef ACC_EVENT_HANDLER_H_
#define ACC_EVENT_HANDLER_H_

class AccEventHandler {
  virtual void HandleAccEvent(int code, short value) = 0;
};

#endif  // ACC_EVENT_HANDLER_H_

