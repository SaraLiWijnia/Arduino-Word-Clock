
// a library allowing us to communicate with the hardware.
// can be found at: https://github.com/rodan/ds3231
#include <DS3231.h>

// local library, hence the " instead of '<' or '>'.
#include "Button.h"

const int _minutesPerClick = 1;
const int _hoursPerClick = 1;

// represents the module.
DS3231 rtc(SDA, SCL);

// represents the current time.
Time t;

// represent the buttons that allow us to influence the time.
Button forwardMinute(2, 250);
Button backwardMinute(3, 250);
Button forwardHour(4, 250);
Button backwardHour(5, 250);

unsigned long updateTimeModule = 0;
const unsigned long updateTimeModuleThreshold = 500;

void InitTimeModuleFunctions()
{
  rtc.begin();
}

void LoopTimeModuleFunctions(unsigned long mil, unsigned long dt)
{
  t = rtc.getTime();
  //SerializeTime();

  bool adjusted = false;
  int seconds = t.sec;
  int minutes = t.min;
  int hours = t.hour;

  if(forwardMinute.CheckClicked(mil))
  { 
    minutes += _minutesPerClick; 
    adjusted = true;
  }

  if(backwardMinute.CheckClicked(mil))
  { 
    minutes -= _minutesPerClick; 
    adjusted = true;
  }

  if(forwardHour.CheckClicked(mil))
  { 
    hours += _hoursPerClick; 
    adjusted = true;
  }

  if(backwardHour.CheckClicked(mil))
  { 
    hours -= _hoursPerClick; 
    adjusted = true;
  }

  if(adjusted)
  { 
    MakeTimeCorrect(hours, minutes);
    rtc.setTime(hours, minutes, seconds);
    t = rtc.getTime();
    SerializeTime();
  }
  
}

void ExtractTime(int &hours, int &minutes)
{
  minutes = t.min;
  hours = t.hour;
}

void MakeTimeCorrect(int &hours, int &minutes)
{
  while(minutes >= 60)
  {
    minutes -= 60;
    hours += 1;
  }

  while(minutes < 0)
  {
    minutes += 60;
    hours -= 1;
  }

  while (hours >= 24)
  { hours -= 24; }

  while (hours < 0)
  { hours += 24; }
}

void SerializeTime()
{
  Serial.print("Seralized time: ");
  Serial.print(t.hour, DEC);
  Serial.print(":");
  Serial.print(t.min, DEC);
  Serial.print(":");
  Serial.println(t.sec, DEC);
}
