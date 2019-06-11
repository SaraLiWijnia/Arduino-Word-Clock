const int timeSlotAnte = 0;
const int timeSlotPost = 1;

const int locationIt = 0;
const int locationIs = 1;

// minute related locations
const int locationTwenty = 2;
const int locationFiveMinutes = 3;
const int locationTenMinutes = 4;
const int locationAQuarter = 5;
const int locationTo = 6;
const int locationHalf = 7;
const int locationPastMinutes = 8;

// hour related locations
const int locationOne = 9;
const int locationTwo = 10;
const int locationThree = 11;
const int locationFour = 12;
const int locationFive = 13;
const int locationSix = 14;
const int locationSeven = 15;
const int locationEight = 16;
const int locationNine = 17;
const int locationTen = 18;
const int locationEleven = 19;
const int locationTwelve = 20;

// 'special' related states.
const int locationMidnight = 21;
const int locationNoon = 22;

// timeslot related locations
const int locationDot = 23;
const int locationOpenBrack = 24;
const int locationAnte = 25;
const int locationPast = 26;
const int locationMeridiem = 27;
const int locationCloseBrack = 28;

// parameters
// hours: we expect the regular hour number, from 1 to 24.
// minutes: we expect the regular minute number, from 0 to 59.
long ComputeClockState(int hours, int minutes)
{
    // compute the correct internal state. 
    int hoursInternal;
    int minutesInternal;
    int slotInternal;
    ComputeInternalTimeState(hours, minutes,  hoursInternal, minutesInternal, slotInternal);

    // represents the empty state - no lights are lit.
    long bits = 0x00000000;
    int error = 0;

    // in any state, these individual states need to be lit. (for example: the word 'it' or the '.')
    ComputeGenericState(bits);

    // a state is 'special' if it is close to midnight and / or noon.
    bool specialState = ComputeSpecialState(hoursInternal, minutesInternal, bits, error);
    if (!specialState)
    {
        // if a state is not special, then compute the individual states.
        ComputeHourState(hoursInternal, bits, error);
        ComputeMinuteState(minutesInternal, bits, error);
        ComputeTimeSlotState(slotInternal, bits, error);
    }

    // if we had an error, we better show something funny.
    // the console contains the error.
    if(error != 0)
    { ComputeErrorState(bits); }

    return bits;
}

void ComputeErrorState(long &bits)
{
    bits = B00000000;

    // eyes
    bits += (long)1 << locationIt;
    bits += (long)1 << locationTo;

    // mouth
    bits += (long)1 << locationTwelve;
    bits += (long)1 << locationMidnight;
    bits += (long)1 << locationNoon;
    bits += (long)1 << locationEleven;
    bits += (long)1 << locationSix;
}

void ComputeInternalTimeState(int hours, int minutes, int &hoursInternal, int &minutesInternal, int &slotInternal)
{
    // default values.
    int minutesInFunction = minutes;
    int hoursInFunction = hours;
    int slotInFunction = timeSlotAnte;

    // compute the right minutes. Expected format: 0 - 11.
    // take note: 1 means that we're 5 minutes in. 2 means that we're 10 minutes in.
    minutesInFunction = (minutes + 2) / 5;
    if(minutesInFunction > 11)
    {
        minutesInFunction -= 12;
        hours += 1;
    }

    // compute the right hours. Expected format: 0 - 12.
    // add in a the minute offset, for when we are past half the clock (past eleven -> to twelve).
    // compute whether we're past half a clock.
    hoursInFunction = hours;
    if (minutesInFunction > 6)
    {
        hoursInFunction += 1;
    }

    // compute the right time slot.
    slotInFunction = timeSlotAnte;
    if (hoursInFunction >= 12 && hoursInFunction <= 24) 
    { slotInFunction = timeSlotPost; }

    while(hoursInFunction > 12)
    { hoursInFunction -= 12; }

    minutesInternal = minutesInFunction;
    hoursInternal = hoursInFunction;
    slotInternal = slotInFunction;
}

bool ComputeSpecialState(int hours, int minutes, long &bits, int &error)
{
    return false;
    // todo: determine if state is special.
    // todo: if state is special, set the special bits.
}

void ComputeHourState(int hours, long &bits, int &error)
{
    switch (hours)
    {
        case 0:
            bits += (long)1 << locationTwelve;
            break;

        case 1:
            bits += (long)1 << locationOne;
            break;

        case 2:
            bits += (long)1 << locationTwo;
            break;

        case 3:
            bits += (long)1 << locationThree;
            break;

        case 4:
            bits += (long)1 << locationFour;
            break;

        case 5:
            bits += (long)1 << locationFive;
            break;

        case 6:
            bits += (long)1 << locationSix;
            break;

        case 7:
            bits += (long)1 << locationSeven;
            break;

        case 8:
            bits += (long)1 << locationEight;
            break;

        case 9:
            bits += (long)1 << locationNine;
            break;

        case 10:
            bits += (long)1 << locationTen;
            break;

        case 11:
            bits += (long)1 << locationEleven;
            break;

        case 12:
            bits += (long)1 << locationTwelve;
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

void ComputeMinuteState(int minutes, long &bits, int &error)
{

    //const long locationTwenty     = 2;
    //const long locationFive       = 3;
    //const long locationTen        = 4;
    //const long locationAQuarter   = 5;
    //const long locationTo         = 6;
    //const long locationHalf       = 7;
    //const long locationPast       = 8;

    switch (minutes)
    {
        case 0:

            break;

        case 1:
            bits += (long)1 << locationFiveMinutes;
            bits += (long)1 << locationPastMinutes;
            break;

        case 2:
            bits += (long)1 << locationTenMinutes;
            bits += (long)1 << locationPastMinutes;
            break;

        case 3:
            bits += (long)1 << locationAQuarter;
            bits += (long)1 << locationPastMinutes;
            break;

        case 4:
            bits += (long)1 << locationTwenty;
            bits += (long)1 << locationPastMinutes;
            break;

        case 5:
            bits += (long)1 << locationTwenty;
            bits += (long)1 << locationFiveMinutes;
            bits += (long)1 << locationPastMinutes;
            break;

        case 6:
            bits += (long)1 << locationHalf;
            bits += (long)1 << locationPastMinutes;
            break;

        case 7:
            bits += (long)1 << locationTwenty;
            bits += (long)1 << locationFiveMinutes;
            bits += (long)1 << locationTo;
            break;

        case 8:
            bits += (long)1 << locationTwenty;
            bits += (long)1 << locationTo;
            break;

        case 9:
            bits += (long)1 << locationAQuarter;
            bits += (long)1 << locationTo;
            break;

        case 10:
            bits += (long)1 << locationTenMinutes;
            bits += (long)1 << locationTo;
            break;

        case 11:
            bits += (long)1 << locationFiveMinutes;
            bits += (long)1 << locationTo;
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

void ComputeTimeSlotState(int slot, long &bits, int &error)
{
    bits += (long)1 << locationOpenBrack;
    bits += (long)1 << locationCloseBrack;
    bits += (long)1 << locationMeridiem;

    switch (slot)
    {
        case timeSlotAnte:

            bits += (long)1 << locationAnte;

            break;

        case timeSlotPost:

            bits += (long)1 << locationPast;

            break;

        default:
            Serial.print("Invalid time slot state given: ");
            Serial.print(slot);
            Serial.println(".");

            error += 1;
            break;
    }
}

void ComputeGenericState(long &bits)
{
    bits += (long)1 << locationIt;
    bits += (long)1 << locationIs;
    bits += (long)1 << locationDot;
}
