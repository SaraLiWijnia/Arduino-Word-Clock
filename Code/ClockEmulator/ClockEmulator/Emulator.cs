using System;
using System.Collections.Generic;
using System.Text;

namespace ClockEmulator
{
    public class Emulator
    {

        Library lib = new Library();
        public int hours = 11, minutes = 25;
        
        public void Run()
        {
            while (true)
            {
                this.Visualize();
                this.GetInput();
            }
        }

        private void GetInput()
        {
            char c = Console.ReadKey().KeyChar;

            switch (c)
            {
                case 'q':
                    hours += 1;
                    if (hours >= 24)
                        hours -= 24;

                    break;

                case 'a':
                    hours -= 1;
                    if (hours < 0)
                        hours += 24;

                    break;

                case 'e':
                    minutes += 1;
                    if (minutes >= 60)
                        minutes -= 60;

                    break;

                case 'd':
                    minutes -= 1;
                    if (minutes < 0)
                        minutes += 60;
                    break;

            }
        }

        public void Visualize()
        {
            int bits = lib.ComputeClockState(hours, minutes);

            Console.Clear();
            Console.SetCursorPosition(0, 0);
            Console.WriteLine("Clock emulator v. a324.");

            Console.SetCursorPosition(0, 1);
            Console.Write($"Time to emulate: {hours.ToString("00")}:{minutes.ToString("00")}");

            Console.SetCursorPosition(0, 3);
            Console.Write("Visualisation of emulation");

            Console.SetCursorPosition(0, 4);
            for(int j = 0; j < 32; j++)
            {
                if (IsBitSet(bits, j))
                    Console.Write("1");
                else
                    Console.Write("0");
            }

            Console.SetCursorPosition(0, 5);

            if (IsBitSet(bits, Library.locationIt))
            { Console.Write("It "); }

            if (IsBitSet(bits, Library.locationIs))
            { Console.Write("is "); }

            if (IsBitSet(bits, Library.locationTwenty))
            { Console.Write("twenty "); }

            if (IsBitSet(bits, Library.locationFiveMinutes))
            { Console.Write("five "); }

            if (IsBitSet(bits, Library.locationTenMinutes))
            { Console.Write("ten "); }

            if (IsBitSet(bits, Library.locationAQuarter))
            { Console.Write("a quarter "); }

            if (IsBitSet(bits, Library.locationTo))
            { Console.Write("to "); }

            if (IsBitSet(bits, Library.locationHalf))
            { Console.Write("half "); }

            if (IsBitSet(bits, Library.locationPastMinutes))
            { Console.Write("past "); }

            if (IsBitSet(bits, Library.locationOne))
            { Console.Write("one "); }

            if (IsBitSet(bits, Library.locationTwo))
            { Console.Write("two "); }

            if (IsBitSet(bits, Library.locationThree))
            { Console.Write("three "); }

            if (IsBitSet(bits, Library.locationFour))
            { Console.Write("four "); }

            if (IsBitSet(bits, Library.locationFive))
            { Console.Write("five "); }

            if (IsBitSet(bits, Library.locationSix))
            { Console.Write("six "); }

            if (IsBitSet(bits, Library.locationSeven))
            { Console.Write("seven "); }

            if (IsBitSet(bits, Library.locationEight))
            { Console.Write("eight "); }

            if (IsBitSet(bits, Library.locationNine))
            { Console.Write("nine "); }

            if (IsBitSet(bits, Library.locationTen))
            { Console.Write("ten "); }

            if (IsBitSet(bits, Library.locationEleven))
            { Console.Write("eleven "); }

            if (IsBitSet(bits, Library.locationTwelve))
            { Console.Write("twelve "); }

            if (IsBitSet(bits, Library.locationMidnight))
            { Console.Write("midnight "); }

            if (IsBitSet(bits, Library.locationNoon))
            { Console.Write("noon "); }

            if (IsBitSet(bits, Library.locationDot))
            { Console.Write("o' clock. "); }

            if (IsBitSet(bits, Library.locationOpenBrack))
            { Console.Write("(  "); }

            if (IsBitSet(bits, Library.locationAnte))
            { Console.Write("ante  "); }

            if (IsBitSet(bits, Library.locationPast))
            { Console.Write("post  "); }

            if (IsBitSet(bits, Library.locationMeridiem))
            { Console.Write("meridiem  "); }

            if (IsBitSet(bits, Library.locationCloseBrack))
            { Console.Write(") "); }

        }

        private bool IsBitSet(int bits, int set)
        {
            int bit = bits & (1 << set);
            return bit == (1 << set);
        }



    }
}
