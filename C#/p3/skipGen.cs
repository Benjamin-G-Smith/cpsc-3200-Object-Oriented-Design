// AUTHOR: Ben Smith
// FILENAME: skipGen.cs
// DATE: 2/4/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 1.0

// DESCRIPTION: The skipGen class acts just like a Gen object except it alters
//  some of the public interface of the Gen class. Inherits from the Gen class.

// ASSUMPTIONS: The user must provide starting value, comon difference, and 
//  number of items in the sequence when creating gen objects. xasdd

// Design Descisions: 
// 1. Same descriptions apply from gen to dubGen
// 2. The calcSequence skips every pth value in the calcSequence. The pth
//      value is either 0,1, or numberofTerms. When calculating, the sequence
//      skips the zero value, first value, and pth value from the total.
// 3. The isActive function prevents the object from cyclying through 'on'/'off'
//      more than k times. K is the same as the numberOfItems.
// 4. When a skipGen object is reset the active count is not reset howeve, the 
//      calculated value is set to zero.

using System;

namespace p3
{
    class skipGen : Gen
    {
        public skipGen(uint a1, uint d, uint n) : base(a1, d, n)
        {
        }
        public override int calcSequence()
        {
            int value = 0;
            if (isActive())
            {
                activeCount++;
                for (int k = (int)numberOfTerms; k >= 1; k--)
                {
                    if (validValue(k))
                    {
                        value += (int)(firstTerm + comondif * (k - 1));
                    }
                }
            }
            calculatedValue = value;
            return value;
        }
        public override string type()
        {
            return "skipGen";
        }
        public override bool isActive()
        {
            if (activeCount > numberOfTerms)
            {
                active = false;       
            }
            return active;            
        }
        private bool validValue(int value)
        {
            if(value == 0)
            {
                return false;
            }
            else if (value == 1)
            {
                return false;
            }
            else if (value == numberOfTerms)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}
