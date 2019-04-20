// AUTHOR: Ben Smith
// FILENAME: Program.cs
// DATE: 1/16/2018
// PLATFORM ( visual studio, 2018 )

// DESCRIPTION: Allows the application programmer to create a driver class using
//  the blurtRep class. The application programmer can create an array of 
//  blurtRep object to which random word can be assigned from a given file.

// ASSUMPTIONS: User must provide a valid string to crate a new blurtRep Object. 
//  The application programmer must input a valid state change string to alter 
//  the state of an object. Count fields are handled internally.

// Design Descisions: 
// 1. Upon creation of a 'blurtRep' object a word must be provided
//     in the constructor. If no word is given or the word is too
//     long then the 'DEFAULT_STR' is assigned as the 'blurtStrging'.
//     The 'repetitionCount' is determined by the length of the string
//     provided in the constructor. 
// 2. Everytime the 'ping' function is called on a blurtRep object
//      the 'pingCount' is increased by '1'. Once the repetitionCount
//      reaches the 'MAX_PING_COUNT' (10) then the 'valid' state of the 
//      object is false. The valid state remains the same until the object
//      is reset. 
// 3. Resetting the blurtRep object puts the object back into it's inital
//      state. 
// 4. Itteration of fields is handled internally. 
// 5. The application programmer may also call the object to access
//      'statistcs' and call the 'IsActive' to learn the validity of the obj.
// 6. Ping count may still count up despite the fact that it is valid or not

using System;

namespace p1
{
    class blurtRep
    {
        private int pingCount;
        private int repetitionCount;

        private bool valid;
        private string blurtString;
        private const int MAX_PING_COUNT = 10;
        private const int MAX_STRING_LENGTH = 5;
        private const int MIN_STRING_LENGTH = 1;
        private const string DEFAULT_STR = "bee";

        public blurtRep(string initailString)
        {
            blurtString = initailString;
            int strLength = initailString.Length;
            if (strLength > MAX_STRING_LENGTH || strLength < MIN_STRING_LENGTH)
            {
                blurtString = DEFAULT_STR;
            }
            repetitionCount = blurtString.Length;
            pingCount = 0;
            valid = true;
        }
        public blurtRep(blurtRep cpyRep)
        {
            blurtString = cpyRep.blurtString;
            repetitionCount = cpyRep.repetitionCount;
            valid = cpyRep.valid;
            pingCount = cpyRep.pingCount;          
        }
        public bool IsActive()
        {
            return valid;            
        }
        public void Statistics()
        {
            if (valid)
            {
                if (5 - blurtString.Length == 2)
                {
                    Console.WriteLine("[Blurt String: " + blurtString + "  ] [Avtive: " + valid + " ] [Ping Count: " + pingCount + " ]");
                }
                else if (5 - blurtString.Length == 3)
                {
                    Console.WriteLine("[Blurt String: " + blurtString + "   ] [Avtive: " + valid + " ] [Ping Count: " + pingCount + " ]");
                }
                else if (5 - blurtString.Length == 1)
                {
                    Console.WriteLine("[Blurt String: " + blurtString + " ] [Avtive: " + valid + " ] [Ping Count: " + pingCount + " ]");
                }
                else
                {
                    Console.WriteLine("[Blurt String: " + blurtString + "] [Avtive: " + valid + " ] [Ping Count: " + pingCount + " ]");
                }
            }
            else
            {
                if (5 - blurtString.Length == 2)
                {
                    Console.WriteLine("[Blurt String: " + blurtString + "  ] [Avtive: " + valid + "] [Ping Count: " + pingCount + " ]");
                }
                else if (5 - blurtString.Length == 3)
                {
                    Console.WriteLine("[Blurt String: " + blurtString + "   ] [Avtive: " + valid + "] [Ping Count: " + pingCount + " ]");
                }
                else if (5 - blurtString.Length == 1)
                {
                    Console.WriteLine("[Blurt String: " + blurtString + " ] [Avtive: " + valid + "] [Ping Count: " + pingCount + " ]");
                }
                else
                {
                    Console.WriteLine("[Blurt String: " + blurtString + "] [Avtive: " + valid + "] [Ping Count: " + pingCount + " ]");
                }
            }

        }
        public void Reset()
        {
            valid = true;
            pingCount = 0;
        }

        public string Ping(string state)
        {
            const string plain = "plain";
            const string repeat = "repeat";
            const string terse = "terse";

            IterateCountFields();
            if (valid && pingCount < MAX_PING_COUNT)
            {
                switch (state)
                {
                    case plain:
                        return blurtString;
                        //break;
                    case repeat:
                        string tempRep = "";
                        for (int i = 0; i < repetitionCount; i++)
                        {
                            tempRep += blurtString;
                        }
                        return tempRep;
                    case terse:
                        string temp = "";
                        for (int i = 0; i < MAX_STRING_LENGTH; i++)
                        {
                            temp += blurtString;
                        }
                        temp = temp.Substring(0, MAX_STRING_LENGTH);
                        return temp;
                        //break;
                    default:
                        Console.WriteLine("Invalid state command...");
                        break;
                }
            }
            return null;

        }
        private void IterateCountFields()
        {
            pingCount++;
            if(pingCount == MAX_PING_COUNT)
            {
                valid = false;
            }

        }

    }
}
