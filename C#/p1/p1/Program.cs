// AUTHOR: Ben Smith
// FILENAME: Program.cs
// DATE: 1/16/2018
// PLATFORM ( visual studio, 2018 )


// DESCRIPTION: The user can provide an inputfile containing a list of words.
//  Which is then stored as blurtRep objects. The Blurt rep objects are called 
//  a number of times changing the state of the objects. After a certain itteration
//  is reached then the program stops, reports the status of each object and then
//  resets all objects back to inital state. 

// ASSUMPTIONS: The user provied a valid input.txt file to read the list of input
//  words from. Assumes that the user does want the state of each object to be reset.
//  User must hit enter to continue program. The user has the option to run the program
//  multiple times. 

// Description of processes:
//  1. A file is loaded which contains a list of words.
//  2. An array of blurtRep objects is initalized from the list of words
//  3. The user is then prompted to run the program
//  4. The blurtRep objects are then randomly 'pinged' until a counter 
//      reaches 500. 
//  5. The statistics of each object is displayed to the user. Statistics
//      conatin word, pingcount, and isActive.
//  6. The objects are then reset back to inital state. 
//  7. The Program exits.

using System;

namespace p1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Please provide an input file path: ");
            // User must enter a valid file to read from
            Console.WriteLine(@"Example: C:Users\USERNAME\Documents\INPUTFILE.txt");
            string userInput = Console.ReadLine();
            string FILE = userInput;
            string[] fileWords = System.IO.File.ReadAllLines(FILE);
            blurtRep[] blurtReps = new blurtRep[fileWords.Length];

            for (int i = 0; i < fileWords.Length; i++)
            {
                blurtReps[i] = new blurtRep(fileWords[i]);
            }

            Console.WriteLine("Would you like to run program [y/n]?");
            string run = Console.ReadLine();
            while (run == "y")
            {
                callBlurtRep(blurtReps, fileWords.Length);
                Console.WriteLine("Would you like to run program [y/n]?");
                run = Console.ReadLine();
            }
            printStatistics(blurtReps, fileWords.Length);
            resetObjects(blurtReps, fileWords.Length);
            printStatistics(blurtReps, fileWords.Length);
        }

        // Precondition: There must be a valid obj and filesize
        // Postconditions: Resets the state of the objects back to inital state
        static void resetObjects(blurtRep[] obj, int fileSize)
        {
            for (int j = 0; j < fileSize; j++)
            {
                obj[j].Reset();
            }
            Console.WriteLine("Reset complete...");
            Console.ReadKey();
        }
        static void printStatistics(blurtRep[] obj, int fileSize)
        {
            for (int j = 0; j < fileSize; j++)
            {
                obj[j].Statistics();
            }
            Console.ReadKey();
        }

        // Precondition: There must be a valid obj and filesize
        // Postconditions: Changes the state of objects through function calls
        static void callBlurtRep(blurtRep[] obj, int fileWordCount)
        {
            const int itterationCount = 500;
            int count = 0;
            string[] stateCalls = { "plain", "repeat", "terse" };
            int numberOfStates = 3;
            Random stateNum = new Random();

            while (count < itterationCount)
            {
                string str = stateCalls[stateNum.Next(numberOfStates)];
                obj[stateNum.Next(fileWordCount)].Ping(str);
                count++;
            }
            Console.ReadKey();
        }
    }
}
