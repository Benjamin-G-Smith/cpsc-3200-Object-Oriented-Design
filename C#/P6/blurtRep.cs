// AUTHOR: Ben Smith
// FILENAME: Program.cs
// DATE: 3/15/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 3.0

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
// 7. User may all the 'getBlurtWord()' function to get the blurtstring.

namespace P6
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

        public blurtRep()
        {
            blurtString = DEFAULT_STR;
            pingCount = 0;
            repetitionCount = blurtString.Length;
            valid = true;
        }

        public blurtRep(string initailString)
        {
            blurtString = initailString;
            pingCount = 0;
            int strLength = initailString.Length;
            if (strLength > MAX_STRING_LENGTH || strLength < MIN_STRING_LENGTH)
            {
                blurtString = DEFAULT_STR;
            }
            repetitionCount = blurtString.Length;

            valid = true;
        }
        public blurtRep(blurtRep cpyRep)
        {
            blurtString = cpyRep.blurtString;
            repetitionCount = cpyRep.repetitionCount;
            valid = cpyRep.valid;
            pingCount = cpyRep.pingCount;          
        }
        // pre: none
        // post: object put into invalid state
        public bool IsActive()
        {
            return valid;            
        }
        // pre: object is in an invalid state
        // post: object is placed back into inital state
        // def: chosing to support the ability to reset the Gen objects to give
        // the application programmer more flexibility
        public void Reset()
        {
            valid = true;
            pingCount = 0;
        }
        // Pre: None
        // Post: None
        public string getBlurtWord()
        {
            return blurtString;
        }
        // pre: none
        // post: object in either valid or invalid state
        // state must be 1,2, or 3 other values not excpted
        public string Ping(string state)
        {
            const string plain = "plain";
            const string repeat = "repeat";
            const string terse = "terse";

            IterateCountFields();
            if (valid)
            {
                switch (state)
                {
                    case plain:
                        return blurtString;
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
                    default:
                        return "Invalid string...";
                }
            }
            else
            {
                return blurtString;
            }
        }
        // pre: none
        // post: values of the object are modified
        private void IterateCountFields()
        {
            pingCount++;
            if (pingCount >= MAX_PING_COUNT)
            {
                valid = false;
            }

        }

    }
}
