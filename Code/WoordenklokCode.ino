//Sara Li Wijnia - Eindopdracht
// 16 maart 2019

#include <DS3231.h>

// Init the DS3231 using the hardware interface
DS3231  rtc(SDA, SCL);

// Init a Time-data structure
Time  t;
unsigned long vorigeTijd;

unsigned long vorigeTijd2;

void setup() {
  // hardware setups -----
  serial_Input_Setup();
  buttonHardware_Setup();
  button_Setup();
  shiftRegister_Setup();
  ledSetup();

  vorigeTijd = millis();
  vorigeTijd2 = millis();
  clock_Setup();
  //rtc.setTime(13, 57, 00);
  // rtc.setDate(28, 4, 2019);

}

void loop() {
  button_Loop();
    t = rtc.getTime();
for (int i = 0; i < 4; i++ ) { 
  button_Clicked(i);
}
  
  if (millis() - vorigeTijd2 >= 1000) {
      Serial.print(t.hour, DEC);
    Serial.print(":");
    Serial.print(t.min, DEC);
    Serial.print(":");
    Serial.println(t.sec, DEC);
    vorigeTijd2 = millis();
  }
  
  
    if (millis() - vorigeTijd >= 5000) {
      setTime5MinutesForward();
      vorigeTijd = millis();
    }

}
