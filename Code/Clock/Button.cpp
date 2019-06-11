#include "Arduino.h"
#include "Button.h"

Button::Button(int pin, unsigned long pressDelay)
{
  pinMode(pin, OUTPUT);

  // receive the data for the behaviour of this button.
  _pin = pin;
  _pressDelay = pressDelay;
  _lastPress = 0;
}

bool Button::CheckClicked(unsigned long currentTime)
{
  // to prevent dithering and double presses!
  if(currentTime - _lastPress > _pressDelay)
  {
    // check if the button is actually being pressed.
    int buttonState = digitalRead(_pin);
    if(buttonState == HIGH)
    {
      _lastPress = currentTime;
      return true;
    }
  }

  return false;
}

bool Button::CheckDown()
{
  int buttonState = digitalRead(_pin);
  return buttonState == HIGH;
}
