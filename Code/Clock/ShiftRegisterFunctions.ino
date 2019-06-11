
//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 8;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 12;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 11;

unsigned long updateShiftRegisters = 0;
const unsigned long updateShiftRegistersThreshold = 100;

void InitShiftRegisterFunctions()
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void LoopShiftRegisterFunctions(unsigned long mil, unsigned long dt)
{
  updateShiftRegisters += dt;
  if(updateShiftRegisters > updateShiftRegistersThreshold)
  {
    // reset the timer.
    updateShiftRegisters = 0;

    // retrieve the time from the time module.
    int hours;
    int minutes;
    ExtractTime(hours, minutes);

    long l = ComputeClockState(hours, minutes);
    VisualizeLong(l);
  }
}

void VisualizeLong(long l)
{
  // turn off the leds, prepare the register.
  digitalWrite(latchPin, LOW);

  // https://www.arduino.cc/reference/en/language/functions/advanced-io/shiftout/
  shiftOut(dataPin, clockPin, MSBFIRST, l >> 24);  
  shiftOut(dataPin, clockPin, MSBFIRST, l >> 16);  
  shiftOut(dataPin, clockPin, MSBFIRST, l >> 8);  
  shiftOut(dataPin, clockPin, MSBFIRST, l);

  // turn on the leds, tell the register we're done.
  digitalWrite(latchPin, HIGH);
}
