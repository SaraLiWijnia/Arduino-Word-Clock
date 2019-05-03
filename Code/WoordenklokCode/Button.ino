// Module Button - van OnderwijsOnline

// --- States -----------
const int BUTTON_STATE_RELEASED = 1;
const int BUTTON_STATE_CHECK_PRESSED = 2;
const int BUTTON_STATE_PRESSED = 3;
const int BUTTON_STATE_CHECK_RELEASED = 4;

// Current state - array voor 3
int button_State[4];
int button_State_Length = 4;


// Timer variables
const int BUTTON_INTERVAL = 10; // 10 msec
unsigned long button_Previous[4]; // array voor 3

// Click variable - ARRAY voor 3
boolean button_Click[4];



// --- Setup -------------------

void button_Setup() {
  // Start state
  for (int i = 0; i < button_State_Length; i++ ) {
     button_State[i] = BUTTON_STATE_RELEASED;
    button_Click[i] = false;
  } 
  button_Released_Entry();

}
// --- Events -----------

boolean button_Clicked(int welkeButton) { // moet meegeven welke button
  // If read, set back to false
  if (button_Click[welkeButton] == true) {
    // reset value for click
    Serial.print("Clicked! :");
    Serial.println(welkeButton);
    button_Click[welkeButton] = false;
    return true;
  }
  else {
    return false;
  }
}
// --- Loop --------------------
void button_Loop() {
 
  for (int i = 0; i < button_State_Length; i++) {
    switch (button_State[i]) {
      case BUTTON_STATE_RELEASED:
        button_Released_Do();
        if (buttonHardware_Down(i) == true) {
          button_Released_Exit();
          button_State[i] = BUTTON_STATE_CHECK_PRESSED;
          button_Check_Pressed_Entry(i);
        }
        break;
      case BUTTON_STATE_CHECK_PRESSED:
        button_Check_Pressed_Do();
        if (buttonHardware_Up(i) == true) {
          button_Check_Pressed_Exit();
          button_State[i] = BUTTON_STATE_RELEASED;
          button_Released_Entry();
        }
        else if ((buttonHardware_Down(i) == true)
                 && (millis() - BUTTON_INTERVAL >= button_Previous)) {
          button_Check_Pressed_Exit();
          button_State[i] = BUTTON_STATE_PRESSED;
          button_Pressed_Entry();
        }
        break;
      case BUTTON_STATE_PRESSED:
        button_Pressed_Do();

        if (buttonHardware_Up(i) == true) {
          button_Pressed_Exit();
          button_State[i] = BUTTON_STATE_CHECK_RELEASED;
          button_Check_Released_Entry(i);
        }
        break;
      case BUTTON_STATE_CHECK_RELEASED:
        button_Check_Released_Do();
        if (buttonHardware_Down(i) == true) {
          button_Check_Released_Exit();
          button_State[i] = BUTTON_STATE_PRESSED;
          button_Pressed_Entry();
        }
        else if ((buttonHardware_Up(i) == true)
                 && (millis() - BUTTON_INTERVAL >= button_Previous)) {
          button_Check_Released_Exit();
          button_State[i] = BUTTON_STATE_RELEASED;
          // On this transition the click has occured.
          button_Click[i] = true;
          button_Released_Entry();
        }
        break;
    }
  }
}


// --- BUTTON_STATE_RELEASED -----------
void button_Released_Entry() {
}
void button_Released_Do() {
}
void button_Released_Exit() {
}

// --- BUTTON_STATE_CHECK_PRESSED -----------
void button_Check_Pressed_Entry(int i ) { // meegeven welke button hier.
  button_Previous[i] = millis();
  Serial.print("Pressed Entry Dit is button: ");
  Serial.println(i);
}
void button_Check_Pressed_Do() {
}
void button_Check_Pressed_Exit() {
}

// --- BUTTON_STATE_PRESSED -----------
void button_Pressed_Entry() {
}
void button_Pressed_Do() {
}
void button_Pressed_Exit() {
}


// --- BUTTON_STATE_CHECK_RELEASED -----------
void button_Check_Released_Entry(int i) {
  button_Previous[i] = millis();
    Serial.print("Released Entry Dit is button: ");
  Serial.println(i);
}
void button_Check_Released_Do() {
}
void button_Check_Released_Exit() {
}
