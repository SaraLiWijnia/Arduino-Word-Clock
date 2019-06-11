/*

*/
#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button
{
  public:
    Button(int pin, unsigned long pressDelay);
    bool CheckClicked(unsigned long currentTime);
    bool CheckDown();
  private:
    int _pin;
    unsigned long _lastPress;
    unsigned long _pressDelay;
};

#endif
