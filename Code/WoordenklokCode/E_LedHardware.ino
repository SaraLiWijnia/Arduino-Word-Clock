
const int PINARRAY[2][3] = {
  {9, 8, 7}, // A1 = ROOD. A2 = GEEL. A3 = GROEN
  {4, 3, 2} // 4 = ROOD. 3 = GEEL. 2 = GROEN
};

const int PINARRAY_LENGTH = 1;
const int PINARRAY_INDEX = 2;

void ledSetup() {
  for (int Length = 0; Length <= PINARRAY_LENGTH; Length++) {
    for (int index = 0; index <= PINARRAY_INDEX; index++) {
      pinMode(PINARRAY[Length][index], OUTPUT);
    }
  }
}

void ledAan(int welke, int pinNummer) {
  digitalWrite(PINARRAY[welke][pinNummer], HIGH);  
}

void ledUit (int welke, int pinNummer) {
  digitalWrite(PINARRAY[welke][pinNummer], LOW);   
}

int getPinArrayLength () { 
  return PINARRAY_LENGTH;
}

int getPinArrayIndex() { 
  return PINARRAY_INDEX;
}
