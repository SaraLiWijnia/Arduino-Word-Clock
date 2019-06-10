
void clock_Setup() {
  rtc.begin();
}


void setClockTime30(bool addition)
{
  int offset = 30;

  int seconds = getSecond();
  int minutes = getMinute();
  int hours = getHour();

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
  for (int i = 0; i < 10; i++) {
    setClockTime30(true);
  }
}

void setTime5MinutesBackwards() {
  for (int i = 0; i < 10; i++) {
    setClockTime30(false);
  }
}


int getHour () {
  return t.hour;
}


int getMinute () {
  return t.min;
}

int getSecond() {
  return t.sec;
}
