// Module ButtonHardware
// Configuratie en uitlezen van de fysieke knop
// van OnderwijsOnline

int button_Pins[4] = {A1,  // A1 = off, on
                      A2, // forward - backward
                      A0 // 30 seconden
                     // A4 // 5 minuten. 
                     };
int button_Pins_Length = 3;

// --- Setup -------------------

void buttonHardware_Setup() {
  for (int i = 0; i < button_Pins_Length; i++) {
    pinMode(button_Pins[i], INPUT);
  }
}

// --- Events -----------

boolean buttonHardware_Down(int welkeButton) {
  // Pull down resistor used.
  return (digitalRead(button_Pins[welkeButton]) == HIGH);
  // if pull down resistor is used, compare to HIGH
}

boolean buttonHardware_Up(int welkeButton) {
  return !buttonHardware_Down(welkeButton);
}
