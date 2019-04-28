// alle patronen voor display
const byte LOPEN = B01010001;
const byte NIETLOPEN = B10111011;

#define it 0

boolean switchLeds[32] {
  false,// 0
  false,
  false,
  false,
  false,
  false,
  false,
  false, // 7

  false, // 8
  false,
  false,
  false,
  false,
  false,
  false,
  false, // 15

  false, // 16
  false,
  false,
  false,
  false,
  false,
  false,
  false, // 23

  false, // 24
  false,
  false,
  false,
  false,
  false,
  false,
  false // 31
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
