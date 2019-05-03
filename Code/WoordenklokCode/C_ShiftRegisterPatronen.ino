// alle patronen voor display

#define it 0

boolean switchLeds[32] {
  false,// 0 - it 
  false,// 1 - is
  false,// 2 - a
  false,// 3 - quarter
  false,// 4 - past
  false,// 5 - one
  false,// 6 - two
  false, //7 - three

  false, // 8 - four
  false, // 9 - five
  false,// 10 - six
  false, // 11 - seven
  false, // 12 - eight
  false,  // 13 - nine
  false, // 14 - ten
  false, // 15 - eleven

  false, // 16 - twelve
  false, // 17 - am
  false, // 18 - pm
  false, // 19 - .
  false,
  false,
  false,
  false, // 23

  false, // 24
  false,
  false,
  false,
  false, 
  false,// 29 - .
  false, // 30 - pm
  false // 31 - am
};





byte patronen_nummers[7] {
  B00111111, // 6
  B01110111, // 5
  B10110011, // 4
  B11100111, // 3
  B11101101, // 2
  B10000011, //1
  B11011111 // 0
};

byte patronen_getLopen() {
  return LOPEN;
}

byte patronen_getNietLopen() {
  return NIETLOPEN;
}
