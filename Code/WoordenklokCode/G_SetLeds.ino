void woorden_Setup() {
  switchLeds[0] = true; // it
  switchLeds[1] = true; // is
  switchLeds[24] = true; // )
  switchLeds[25] = true; // (
  switchLeds[27] = true; // o clock
  switchLeds[28] = true; // .
}

int geefUur() {
  int uur = getHour();
  if (uur > 12) {
    uur = uur - 12
  }
  return uur;
}

void setUurKlok () { 
  int uur = getUur();

  if (uur = 1 ) { 
    switchLeds[6] = true; // 1
    switchLeds[23] = false; // 12
  }

if (uur = 2) { 
  switchLeds[6] = false; // 1
  switchLeds[7] = true; // 2
}

if (uur = 3) { 
  switchLeds[7] = false; // 2
  switchLeds[13] = true; // 3
}

if (uur = 4) { 
  switchLeds[13] = false // 3
  switchLeds[12] = true;
}

it is 4 o clock
it is 4 past 4 0 clock
it is 10 past 4 0 clock
it is a quarter past 4 o clock
it is twenty past 4 0 clock
it is twenty five past 4 o clock
it is 

  
}

  false,// 6 - one
  false, //7 - two

  false, // 8 - ten
  false, // 9 - a quarter
  false,// 10 - to
  false, // 11 - five
  false, // 12 - four
  false,  // 13 - three
  false, // 14 - 
  false, // 15 - 

  false, // 16 - six
  false, // 17 - seven
  false, // 18 - eight
  false, // 19 - nine
  false, // 20 - ten
  false, // 21 - eleven
  false, // 22 - twelve
  false, // 23 - midnight
void setMinKlok () {
  int minuut = returnMinute();

  if (minuut > 5) {
    //  five over <hour> . am, pm
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



void setAMorPM () {
  if (getHour() < 12) {
switchLeds[29] = true; // ante
switchLeds[31] = true; // meridien
switchLeds[30] = false; // post
  } else {
switchLeds[29] = false // ante
switchLeds[31] = true; // meridien
switchLeds[30] = true; // post
  }
}
