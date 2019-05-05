byte shiftRegister1;
byte shiftRegister2;
byte shiftRegister3;
byte shiftRegister4;


void setShiftRegisters () {
  for (int i = 0; i < 8; i++) {
    bitWrite(shiftRegister1, i, switchLeds[i]);

  }

  for (int i = 8; i < 16; i++ ) {
    bitWrite(shiftRegister2, i, switchLeds[i]);

  }

  for (int i = 16; i < 24; i++ ) {
    bitWrite (shiftRegister3, i, switchLeds[i]);
  }

  for (int i = 24; i < 32; i++ ) {
    bitWrite (shiftRegister4, i, switchLeds[i]);
  }

}
