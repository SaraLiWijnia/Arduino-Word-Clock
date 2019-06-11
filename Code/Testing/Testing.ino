#include "Button.h"

Button b1(2, 250);
Button b2(3, 250);

void setup()
{
  Serial.begin(9600);
  Serial.println("reset");
}

void loop()
{
  unsigned long t = millis();
  if(b1.CheckClicked(t))
  {
    Serial.println("b1 is pressed!");
  }

    if(b2.CheckClicked(t))
  {
    Serial.println("b2 is pressed!");
  }
}
