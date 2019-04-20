// AUTHOR: Ben Smith
// FILENAME: Program.cs
// DATE: 2/4/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 1.0

// DESCRIPTION: The driver for Gen objects, skipGen objects, and dubGen objects.
//  The driver initalizes an array of gen objects. This array is treated as a 
//  hetrogeneous collection of objects. The driver initalizes the array of objects
//  then cycles through altering states of each object. The program prompts the user
//  to continue until the program exits. 

// ASSUMPTIONS: The user does not input anything except for the enter key to continue the
//  program. The getObject function provides the initalizaion of each new object.

// Design Descisions: 
// 1. The user only provides continuation input.
// 2. Every time an object is 'pinged' the user does not see a print conformation. Only
//      when the statistic are displayed does the user see the state of the objects.
// 3. The values used to initalize objects are randomized. If there is an issue initalizing
//      default values will be used.

using System;

namespace p3
{
    class Program
    {
        static void Main(string[] args)
        {
            uint a1 = 1;
            uint d = 10;
            uint n = 100;
            int type = 0;
            int count = 0;
            const int SIZE = 20;
            const int A1_MAX = 11;
            const int N_MAX = 51;
            const int MIN_TYPE = 1;
            const int MAX_TYPE = 4;
            const int ITERATION_COUNT = 900;

            Console.WriteLine("Press Enter to run program");
            Console.ReadLine();

            Gen[] genArray = new Gen[SIZE];
            Random rnd = new Random();

            Console.WriteLine("Initalizing objects...");
            for (int i = 0; i < SIZE; i++)
            {
                a1 = (uint) rnd.Next(A1_MAX);
                d = (uint)rnd.Next(SIZE);
                n = (uint)rnd.Next(SIZE, N_MAX);

                type = rnd.Next(MIN_TYPE, MAX_TYPE);
                genArray[i] = getObj(type, a1, d, n);
                Console.WriteLine("A " + genArray[i].type() + " object initalized");
            }
            Console.WriteLine("Initalization complete...");
            Console.WriteLine("Press Enter to continue...");
            Console.ReadKey();

            Console.WriteLine("Distributing values...");
            while(count < ITERATION_COUNT)
            {
                int obj = rnd.Next(0, SIZE);
                genArray[obj].calcSequence();
                int v = rnd.Next(0, SIZE);
                if (!genArray[v].isActive() && genArray[v].type() != "skipGen")
                {
                    genArray[v].reset();
                }
                if(genArray[v].type() == "dubGen")
                {
                    genArray[v].reset();
                }
                count++;
            }
            Console.WriteLine("Distribution complete...");
            Console.WriteLine("Press Enter to continue...");
            Console.ReadKey();

            Console.WriteLine("Press enter to display object statistics");
            Console.ReadKey();
            for (int k = 0; k < SIZE; k++)
            {
                string str = genArray[k].statistics();
                Console.WriteLine("Sub-type: " + genArray[k].type() +" "+ str);
            }
            Console.ReadKey();
            Console.WriteLine("Press enter to exit program");
            Console.ReadKey();
            Console.WriteLine("Goodbye...");
        }
        private enum subType
        {
            Gen = 1,
            skipGen = 2,
            dubGen = 3
        }
        static Gen getObj(int type, uint a1, uint d, uint n)
        {
            switch ((subType)type)
            {
                case subType.Gen:
                    return new Gen(a1, d, n);
                case subType.skipGen:
                    return new skipGen(a1, d, n);
                case subType.dubGen:
                    return new dubGen(a1, d, n);
                default:
                    throw new IndexOutOfRangeException("Bad condition");
            }
        }
    }
}
