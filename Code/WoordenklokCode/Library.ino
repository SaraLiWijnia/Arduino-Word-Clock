
enum TimeSlot {
  AM,
  PM
};

const long locationIt         = 0;
const long locationIs         = 1;

// minute related locations
const long locationTwenty     = 2;
const long locationFive       = 3;
const long locationTenMinutes = 4;
const long locationAQuarter   = 5;
const long locationTo         = 6;
const long locationHalf       = 7;
const long locationPast       = 8;

// hour related locations
const long locationOne        = 9;
const long locationTwo        = 10;
const long locationThree      = 11;
const long locationFour       = 12;
const long locationFive       = 13;
const long locationSix        = 14;
const long locationSeven      = 15;
const long locationEight      = 16;
const long locationNine       = 17;
const long locationTen        = 18;
const long locationEleven     = 19;
const long locationTwelve     = 20;

// 'special' related states.
const long locationMidnight   = 21;
const long locationNoon       = 22;

/ timeslot related locations
const long locationDot        = 23;
const long locationOpenBrack  = 24;
const long locationAnte       = 25;
const long locationPast       = 26;
const long locationMeridiem   = 27;
const long locationCloseBrack = 28;


// parameters
// hours: we expect the regular hour number, from 1 to 24.
// minutes: we expect the regular minute number, from 0 to 59.
long ComputeClockState(int hours, int minutes) 
{
  // compute the correct internal state. 
  int internalHours;          // expected: 1 to 12.
  int internalMinutes;        // expected: 0 to 11.
  TimeSlot internalTimeSlot;  // expected: AM or PM.

  ComputeInternalTimeState(hours, minutes, &internalHours, &internalMinutes, &internalTimeSlot);

  // represents the empty state - no lights are lit.
  long bits = 0x0000000000000000;
  int error = 0;

  // in any state, these individual states need to be lit. (for example: the word 'it' or the '.')
  ComputeGenericState(&bits, &error);

  // a state is 'special' if it is close to midnight and / or noon.
  bool specialState = ComputeSpecialState(hours, minutes, slot, &bits, &error);
  if(!specialState)
  {
    // if a state is not special, then compute the individual states.
    ComputeHourState(hours, &bits, &error);
    ComputeMinuteState(minutes, &bits, &error);
    ComputeTimeSlotState(slot, &bits, &error);
  }

  return bits;
}

void ComputeInternalTimeState(int hours, int minutes, int* hoursOut, int* minutesOut, TimeSlot* slotOut)
{
  // compute the right hours. Expected format: 1 - 12.
  hoursOut = hours;
  if(hoursOut > 12)
  { hoursOut -= 12; }

  // compute the right minutes. Expected format: 0 - 11.
  // take note: 1 means that we're 5 minutes in. 2 means that we're 10 minutes in.
  minutesOut = minutes / 5;

  // compute the right time slot.
  slotOut = AM;
  if(hours > 12)
  { slotOut = PM;}
}

bool ComputeSpecialState(int hours, int minutes, TimeSlot slot, long* bits, int* error)
{
  // todo: determine if state is special.
  // todo: if state is special, set the special bits.
}

void ComputeHourState(int hours, long* bits, int* error)
{
  switch(hours)
  {
    case 1:
      bits += 1 << locationOne;
    break;

    case 2:
      bits += 1 << locationTwo;
    break;

    case 3:
      bits += 1 << locationThree;
    break;

    case 4:
      bits += 1 << locationFour;
    break;

    case 5:
      bits += 1 << locationFive;
    break;

    case 6:
      bits += 1 << locationSix;
    break;

    case 7:
      bits += 1 << locationSeven;
    break;

    case 8:
      bits += 1 << locationEight;
    break;

    case 9:
      bits += 1 << locationNine;
    break;
      
    case 10:
      bits += 1 << locationTen;
    break;
      
    case 11:
      bits += 1 << locationEleven;
    break;

    case 12:
      bits += 1 << locationTwelve;
    break;

    default:

    // something went wrong! Hellup!
    Serial.print("Invalid hour state given: ");
    Serial.print(hours);
    Serial.println(".");

    error += 1;

    break;
  }
}

void ComputeMinuteState(int minutes, long* bits)
{
  
  //const long locationTwenty     = 2;
  //const long locationFive       = 3;
  //const long locationTen        = 4;
  //const long locationAQuarter   = 5;
  //const long locationTo         = 6;
  //const long locationHalf       = 7;
  //const long locationPast       = 8;
  
  switch(minutes)
  {
    case 0:

    break;

    case 1:
      bits += 1 << locationFive;
    break;

    case 2:
      bits += 1 << locationTenMinutes;
    break;

    case 3:
      bits += 1 << locationAQuarter;
    break;

    case 4:
      bits += 1 << locationTwenty;
    break;

    case 5:
      bits += 1 << locationTwenty;
      bits += 1 << locationFive;
    break;

    case 6:
      bits += 1 << locationHalf;
    break;

    case 7:
      bits += 1 << locationTwenty;
      bits += 1 << locationFive;
      bits += 1 << locationPast;
    break;

    case 8:
      bits += 1 << locationTwenty;
      bits += 1 << locationPast;
    break;
      
    case 9:
      bits += 1 << locationAQuarter;
      bits += 1 << locationPast;  
    break;
      
    case 10:
      bits += 1 << locationTenMinutes;
      bits += 1 << locationPast;
    break;

    case 11:
      bits += 1 << locationFive;
      bits += 1 << locationPast;
    break;

    default:

    // something went wrong! Hellup!
    Serial.print("Invalid minute state given: ");
    Serial.print(minutes);
    Serial.println(".");

    // show something unexpecting.
    error += 1;

    break;
  }
}

void ComputeTimeSlotState(TimeSlot slot, long* bits, int* error)
{
  bits += 1 << locationOpenBrack;
  bits += 1 << locationCloseBrack;
  bits += 1 << locationMeridiem;
  
  switch(slot)
  {
    case AM:

      bits += 1 << locationAnte;
    
    break;

    case PM:

      bits += 1 << locationPost;

    break;

    default:
      Serial.print("Invalid time slot state given: ");
      Serial.print(slot);
      Serial.println(".");

      error += 1;
    break;
  }
}

void ComputeGenericState(long* bits)
{
  bits += 1 << locationIt;
  bits += 1 << locationIs;
  bits += 1 << locationDot;
}
