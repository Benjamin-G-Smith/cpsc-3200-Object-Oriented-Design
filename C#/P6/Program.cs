// Ben Smith
// P6.cs
// 3/15/2016

// DESCRIPTION: Driver class that allows the user to implement blurtGen,
// blurtSkip, and blurtDub objects. The user can use the utilily of multiple
// parent class interfaces in the public interface of the three child classes.
// The program creates three hetrogeneous collections one of blurtGen, one of
// blurtDub, and one of blurtSkip. The program then proforms random manipulations
// on the contained objects to have a variety of data and state change for Each.
// The program then resets any invalid objects back to their original state.
// The program also allows the user to run it as many times as desired to see
// various varients of each object type.

// ASSUMPTIONS: user only wants to see output and provide input to run the
// driver. Only positive values are used in the creation of objects. There is
// a single string array containing words used for initalization.

// Design Descisions:
// 1. Each child class has a hetrogeneous collection
// 2. creation of each object type occurs within a helper function
// 3. The user may run the program as many times as they want

using System;

namespace P6
{
    class Program
    {
        static void Main(string[] args)
        {
            const int bankSize = 20;
            const int collectionSize = 5;
            const int loopCount = 40;
            string[] wordBank = new string[bankSize] {"dress","hip","bless","acute","chest","count","thin",
               "thick","belt","drive","trace","bell","roar","clear","sip","mess","hover","ego","zero"
               , "steep"};

            blurtGens[] bGenCollection = new blurtGens[collectionSize];
            blurtSkip[] bSkipCollection = new blurtSkip[collectionSize];
            blurtDub[] bDubCollection = new blurtDub[collectionSize];

            bool run = welcome();

            while(run)
            {
                createBlurtGens(bGenCollection, wordBank, collectionSize);
                createBlurtSkip(bSkipCollection, wordBank, collectionSize);
                createBlurtDub(bDubCollection, wordBank, collectionSize);
                int count = 0;
                Random rnd = new Random();

                while(count < loopCount)
                {
                    int i = rnd.Next(collectionSize);
                    printActiveBlurtGen(bGenCollection, i);
                    printActiveBlurtSkip(bSkipCollection, i);
                    printActiveBlurtDub(bDubCollection, i);
                    count++;
                }
                run = runAgain();
            }
            Console.WriteLine("Goodbye...");
        }
        // Pre: none
        // Post: none
        // Des: Returns a random string to call ping functionality
        private static string callBlurt()
        {
            Random rnd = new Random();
            int state = rnd.Next(1, 4);

            if (state == 1) return "ping";
            else if (state == 2) return "repeat";
            else return "terse";
        }
        // Pre: objects must be initalized 
        // Post: Objects will remain in an active state or be reset to inital state
        // Des: Prints the active stats of objects and resets inactive objects
        private static void printActiveBlurtGen(blurtGens[] collection, int index)
        {
            collection[index].ping(callBlurt());
            collection[index].calcSequence();
            if (!collection[index].isActive() || !collection[index].IsActive())
            {
                collection[index].reset();
                collection[index].Reset();
                Console.WriteLine("[Reset BlurtGen]:" + collection[index].stats());
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine("BlurtGen  | " + collection[index].stats());
            }
        }
        // Pre: objects must be initalized 
        // Post: Objects will remain in an active state or be reset to inital state
        // Des: Prints the active stats of objects and resets inactive objects
        private static void printActiveBlurtSkip(blurtSkip[] collection, int index)
        {
            collection[index].ping(callBlurt());
            collection[index].calcSequence();
            if (!collection[index].isActive() || !collection[index].IsActive())
            {
                collection[index].reset();
                collection[index].Reset();
                Console.WriteLine("[Reset BlurtSkip]:" + collection[index].stats());
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine("BlurtSkip  | " + collection[index].stats());
            }

        }
        // Pre: objects must be initalized 
        // Post: Objects will remain in an active state or be reset to inital state
        // Des: Prints the active stats of objects and resets inactive objects
        private static void printActiveBlurtDub(blurtDub[] collection, int index)
        {
            collection[index].ping(callBlurt());
            collection[index].calcSequence();
            if (!collection[index].isActive() || !collection[index].IsActive())
            {
                collection[index].reset();
                collection[index].Reset();
                Console.WriteLine("[Reset BlurtDub]:" + collection[index].stats());
                Console.WriteLine();
            }
            else
            {
                Console.WriteLine("BlurtDub  | " + collection[index].stats());
            }
        }
        // pre: none
        // post: none
        public static bool welcome()
        {
            string userInput = "";
            Console.WriteLine("Welcome...");
            Console.WriteLine("Program is simulating multiple inheritance using Gen, skipGen, and dubGen \n " +
                "with blurtRep to create blurtGen, blurtSkip, and blurtDub");
            Console.WriteLine("Would you like to run the program 'y'/'n'?: ");
            userInput = Console.ReadLine();
            return userInput == "y";
        }
        // pre: none
        // post: none
        public static bool runAgain()
        {
            string userInput = "";
            Console.WriteLine("Would you like to run the program again 'y'/'n'?:");
            userInput = Console.ReadLine();
            return userInput == "y";
        }
        // pre: none
        // post: a hetrogeneous collection of blurtGens is in valid inital state
        public static void createBlurtGens(blurtGens[] collection, string[] wordBank,int collectionSize)
        {
            Random rnd = new Random();
            int start = 5;
            int dif = 10;
            int num = 100;
            int nStart = 20;
            for (int i = 0; i < collectionSize; i++)
            {
                uint a = (uint) rnd.Next(start);
                uint d = (uint)rnd.Next(dif);
                uint n = (uint)rnd.Next(nStart,num); 
                int word = rnd.Next(nStart);
                collection[i] = new blurtGens(wordBank[word], a, d, n);
            }
        }
        // pre: none
        // post: a hetrogeneous collection of blurtSkips is in valid inital state
        public static void createBlurtSkip(blurtSkip[] collection, string[] wordBank, int collectionSize)
        {
            Random rnd = new Random();
            int start = 5;
            int dif = 10;
            int num = 100;
            int nStart = 20;
            for (int i = 0; i < collectionSize; i++)
            {
                uint a = (uint)rnd.Next(start);
                uint d = (uint)rnd.Next(dif);
                uint n = (uint)rnd.Next(nStart, num);
                int word = rnd.Next(nStart);
                collection[i] = new blurtSkip(wordBank[word], a, d, n);
            }
        }
        // pre: none
        // post: a hetrogeneous collection of blurtDubs is in valid inital state
        public static void createBlurtDub(blurtDub[] collection, string[] wordBank, int collectionSize)
        {
            Random rnd = new Random();
            int start = 5;
            int dif = 10;
            int num = 100;
            int nStart = 20;
            for (int i = 0; i < collectionSize; i++)
            {
                uint a = (uint)rnd.Next(start);
                uint d = (uint)rnd.Next(dif);
                uint n = (uint)rnd.Next(nStart, num);
                int word = rnd.Next(nStart);
                collection[i] = new blurtDub(wordBank[word], a, d, n);
            }
        }
    }
}
