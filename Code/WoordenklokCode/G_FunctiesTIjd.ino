void woorden_Setup() { 
  switchLeds[19] = true;
}

void woorden_loop() { 
  setMinuut();
}

void setMinuut () {
  int minuut = returnMinute();

  if (minuut > 5) {
    // it is five over <hour> . am, pm
  }

  if (minuut > 10 ) {
    // it is ten over hour . am pm
  }

  if (minuut > 15) {
    //  it is fifteen past hour, am, pm
  }

  if (minuut > 20) {
    // it is twenty past hour, am, pm
  }

  if (minuut > 25 ) {
    // vijf minuten voor half
  }

  if (minuut > 30 ) {
    // het is half
  }

  if (minuut > 35 ) {
    // het is vijf over half
  }

  if (minuut > 40) {
    // het is tien over half
  }

  if (minuut > 45 ) {
    // kwart voor
  }

  if (minuut > 50 ) {
    // tien voor
  }

  if (minuut > 55 ) {
    // vijf voor
  }
}

int geefUur () {
  int uur = getHour();
  if (uur > 12) {
    uur = uur - 12
  }
  return uur;
}

void setAMorPM () {
  if (getHour() < 12) {
    switchLeds[17] = true;
    switchLeds[18] = false;
  } else {
    switchLeds[17] = false;
    switchLeds[18] = true;
  }
}
