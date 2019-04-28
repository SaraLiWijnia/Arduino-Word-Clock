
void clock_Setup() {
  rtc.begin();
}

void setClockTime30Forwards() {
  int second = 30;

  if (returnSecond() + second > 60) { // als groter dan 60
    int a = (returnSecond() + second) - 60;

    if (returnMinute() + 1 != 60 ) { // als min niet groter is dan 60
      rtc.setTime(returnHour(), returnMinute() + 1, a + 1);

    } else {
      // als het wel groter is dan 60 min
      if (returnHour() + 1 != 24) {
        // als hour niet groter is dan 24
        rtc.setTime(returnHour() + 1, 00, a + 1);
      } else {
        // als hour wel groter is dan 24
        rtc.setTime(0, 0, a + 1);
      }
    }
  } else {
    rtc.setTime(returnHour(), returnMinute(), returnSecond() + second);

  }
}

void setClockTime(bool addition)
{
  int offset = 30;

  int seconds = returnSecond();
  int minutes = returnMinute();
  int hours = returnHour();

  if (addition)
  {
    seconds += offset;

    if (seconds > 60)
    {
      seconds -= 60;
      minutes += 1;
    }

    if (minutes > 60)
    {
      minutes -= 60;
      hours += 1;
    }

    if (hours > 24)
    {
      hours -= 24;
    }
  }
  else
  {
    seconds -= offset;

    if (seconds < 0)
    {
      seconds += 60;
      minutes -= 1;
    }

    if (minutes < 0)
    {
      minutes += 60;
      hours -= 1;
    }

    if (hours < 0)
    {
      hours += 24;
    }
  }

  rtc.setTime(hours, minutes, seconds);
  t = rtc.getTime();
}

void setTime5MinutesForward() { 
  for (int i = 0; i<10; i++) { 
      setClockTime(true);
  }
}

void setTime5MinutesBackwards() { 
    for (int i = 0; i<10; i++) { 
      setClockTime(false);
  }
}


int returnHour () {
  return t.hour;
}


int returnMinute () {
  return t.min;
}

int returnSecond() {
  return t.sec;
}


boolean isItAM() {

}

boolean isItPM () {

}
