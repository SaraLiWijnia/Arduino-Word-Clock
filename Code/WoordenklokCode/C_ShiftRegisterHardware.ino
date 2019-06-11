 // ZET HIER DE PINS VOOR ALLE SHIFT REGISTERS. 

const int DS = 13; // data pin
const int ST_CP = 12; // klok pin
const int SH_CP = 11; // einde / begin signaal pin

void shiftRegister_Setup() {
  pinMode(DS, OUTPUT);
  pinMode(ST_CP, OUTPUT);
  pinMode(SH_CP, OUTPUT);
}


void setShiftRegisterPattern(int pattern) {
  digitalWrite(ST_CP, LOW);

  for (int i = 0; i < 15; i++) {
    digitalWrite(SH_CP, LOW);
    digitalWrite(DS, bitRead(pattern, i));
    digitalWrite(SH_CP, HIGH);
  }

  digitalWrite(ST_CP, HIGH);
  digitalWrite(ST_CP, LOW);
}
