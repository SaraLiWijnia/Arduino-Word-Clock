using System;
using System.Collections.Generic;
using System.Text;

namespace ClockEmulator
{


    public class Library
    {

        enum TimeSlot
        {
            AM,
            PM
        };

        public const int locationIt = 0;
        public const int locationIs = 1;

        // minute related locations
        public const int locationTwenty = 2;
        public const int locationFiveMinutes = 3;
        public const int locationTenMinutes = 4;
        public const int locationAQuarter = 5;
        public const int locationTo = 6;
        public const int locationHalf = 7;
        public const int locationPastMinutes = 8;

        // hour related locations
        public const int locationOne = 9;
        public const int locationTwo = 10;
        public const int locationThree = 11;
        public const int locationFour = 12;
        public const int locationFive = 13;
        public const int locationSix = 14;
        public const int locationSeven = 15;
        public const int locationEight = 16;
        public const int locationNine = 17;
        public const int locationTen = 18;
        public const int locationEleven = 19;
        public const int locationTwelve = 20;

        // 'special' related states.
        public const int locationMidnight = 21;
        public const int locationNoon = 22;

        // timeslot related locations
        public const int locationDot = 23;
        public const int locationOpenBrack = 24;
        public const int locationAnte = 25;
        public const int locationPast = 26;
        public const int locationMeridiem = 27;
        public const int locationCloseBrack = 28;

        // parameters
        // hours: we expect the regular hour number, from 1 to 24.
        // minutes: we expect the regular minute number, from 0 to 59.
        public int ComputeClockState(int hours, int minutes)
        {
            // compute the correct internal state. 
            int hoursInternal;
            int minutesInternal;
            TimeSlot slotInternal;
            ComputeInternalTimeState(hours, minutes, out hoursInternal, out minutesInternal, out slotInternal);

            // represents the empty state - no lights are lit.
            int bits = 0x00000000;
            int error = 0;

            // in any state, these individual states need to be lit. (for example: the word 'it' or the '.')
            ComputeGenericState(ref bits);

            // a state is 'special' if it is close to midnight and / or noon.
            bool specialState = ComputeSpecialState(hoursInternal, minutesInternal, ref bits, ref error);
            if (!specialState)
            {
                // if a state is not special, then compute the individual states.
                ComputeHourState(hoursInternal, ref bits, ref error);
                ComputeMinuteState(minutesInternal, ref bits, ref error);
                ComputeTimeSlotState(slotInternal, ref bits, ref error);
            }

            // if we had an error, we better show something funny.
            // the console contains the error.
            if(error != 0)
            { ComputeErrorState(ref bits); }

            return bits;
        }

        void ComputeErrorState(ref int bits)
        {
            bits = 0x00000000;

            // eyes
            bits += 1 << locationIt;
            bits += 1 << locationTo;

            // mouth
            bits += 1 << locationTwelve;
            bits += 1 << locationMidnight;
            bits += 1 << locationNoon;
            bits += 1 << locationEleven;
            bits += 1 << locationSix;
        }

        void ComputeInternalTimeState(int hours, int minutes, out int hoursInternal, out int minutesInternal, out TimeSlot slotInternal)
        {
            // default values.
            minutesInternal = minutes;
            hoursInternal = hours;
            slotInternal = TimeSlot.AM;

            // compute the right minutes. Expected format: 0 - 11.
            // take note: 1 means that we're 5 minutes in. 2 means that we're 10 minutes in.
            minutesInternal = (minutes + 2) / 5;
            if(minutesInternal > 11)
            {
                minutesInternal -= 12;
                hours += 1;
            }

            // compute the right hours. Expected format: 0 - 12.
            // add in a the minute offset, for when we are past half the clock (past eleven -> to twelve).
            // compute whether we're past half a clock.
            hoursInternal = hours;
            if (minutesInternal > 6)
            {
                hoursInternal += 1;
            }

            // compute the right time slot.
            slotInternal = TimeSlot.AM;
            if (hoursInternal >= 12 && hoursInternal <= 24)
            { slotInternal = TimeSlot.PM; }

            while(hoursInternal > 12)
            { hoursInternal -= 12; }
        }

        bool ComputeSpecialState(int hours, int minutes, ref int bits, ref int error)
        {
            return false;
            // todo: determine if state is special.
            // todo: if state is special, set the special bits.
        }

        void ComputeHourState(int hours, ref int bits, ref int error)
        {
            switch (hours)
            {
                case 0:
                    bits += 1 << locationTwelve;
                    break;

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
                    Console.Write("Invalid hour state given: ");
                    Console.Write(hours);
                    Console.WriteLine(".");

                    error += 1;

                    break;
            }
        }

        void ComputeMinuteState(int minutes, ref int bits, ref int error)
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
                    bits += 1 << locationFiveMinutes;
                    bits += 1 << locationPastMinutes;
                    break;

                case 2:
                    bits += 1 << locationTenMinutes;
                    bits += 1 << locationPastMinutes;
                    break;

                case 3:
                    bits += 1 << locationAQuarter;
                    bits += 1 << locationPastMinutes;
                    break;

                case 4:
                    bits += 1 << locationTwenty;
                    bits += 1 << locationPastMinutes;
                    break;

                case 5:
                    bits += 1 << locationTwenty;
                    bits += 1 << locationFiveMinutes;
                    bits += 1 << locationPastMinutes;
                    break;

                case 6:
                    bits += 1 << locationHalf;
                    bits += 1 << locationPastMinutes;
                    break;

                case 7:
                    bits += 1 << locationTwenty;
                    bits += 1 << locationFiveMinutes;
                    bits += 1 << locationTo;
                    break;

                case 8:
                    bits += 1 << locationTwenty;
                    bits += 1 << locationTo;
                    break;

                case 9:
                    bits += 1 << locationAQuarter;
                    bits += 1 << locationTo;
                    break;

                case 10:
                    bits += 1 << locationTenMinutes;
                    bits += 1 << locationTo;
                    break;

                case 11:
                    bits += 1 << locationFiveMinutes;
                    bits += 1 << locationTo;
                    break;

                default:

                    // something went wrong! Hellup!
                    Console.Write("Invalid minute state given: ");
                    Console.Write(minutes);
                    Console.WriteLine(".");

                    // show something unexpecting.
                    error += 1;

                    break;
            }
        }

        void ComputeTimeSlotState(TimeSlot slot, ref int bits, ref int error)
        {
            bits += 1 << locationOpenBrack;
            bits += 1 << locationCloseBrack;
            bits += 1 << locationMeridiem;

            switch (slot)
            {
                case TimeSlot.AM:

                    bits += 1 << locationAnte;

                    break;

                case TimeSlot.PM:

                    bits += 1 << locationPast;

                    break;

                default:
                    Console.Write("Invalid time slot state given: ");
                    Console.Write(slot);
                    Console.WriteLine(".");

                    error += 1;
                    break;
            }
        }

        void ComputeGenericState(ref int bits)
        {
            bits += 1 << locationIt;
            bits += 1 << locationIs;
            bits += 1 << locationDot;
        }


    }
}
