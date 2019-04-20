// AUTHOR: Ben Smith
// FILENAME: dubGen.cs
// DATE: 2/4/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 1.0

// DESCRIPTION: The dub Gen class acts just like a Gen object except it alters
//  some of the public interface of the Gen class. Inherits from the Gen class.

// ASSUMPTIONS: The user must provide starting value, comon difference, and 
//  number of items in the sequence when creating gen objects. 

// Design Descisions: 
// 1. Same descriptions apply from gen to dubGen
// 2. The calcSequence doubles every pth value in the calcSequence. The pth
//      value is the same as the commondifference.
// 3. The reset function 'restarts' the sequence from zero, however the 
//      previously calculated value is kept and added to.
using System;

namespace p3
{
    class dubGen:Gen
    {
        public dubGen(uint a1, uint d, uint n) : base(a1, d, n)
        {
        }
        public override string type()
        {
            return "dubGen";
        }
        public override int calcSequence()
        {
            uint doublesEvery = comondif;
            int value = 0;
            if (isActive())
            {
                activeCount++;
                for (int k = (int)numberOfTerms; k >= 1; k--)
                {
                    if (k % doublesEvery == 0)
                    {
                        value += (int)((firstTerm + comondif * (k - 1)) * 2);
                    }
                }
            }
            calculatedValue = value;
            return value;
        }
        public override void reset()
        {
            calculatedValue += calcSequence();
            active = true;
            activeCount = 0;            
        }
    }
}
