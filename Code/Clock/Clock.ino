
unsigned long previousMillis;

void setup() {

  Serial.begin(115200);
  while (!Serial) {}
  
  Serial.println("reset");
  
  InitTimeModuleFunctions();
  InitShiftRegisterFunctions();

  previousMillis = millis();
}

void loop() {

  // allows us to do computations that require the delta time.
  // we may be over engineering the situation :(.
  unsigned long currentMillis = millis();
  unsigned long dt = currentMillis - previousMillis;
  previousMillis = currentMillis;

  // check for input and, if there is input, update the time.
  LoopTimeModuleFunctions(currentMillis, dt);
  LoopShiftRegisterFunctions(currentMillis, dt);
}
