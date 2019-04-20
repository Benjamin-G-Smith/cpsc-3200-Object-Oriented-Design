// AUTHOR: Ben Smith
// FILENAME: Gen.cs
// DATE: 2/4/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 1.0

// DESCRIPTION: The Gen class allows the application programmer to create
//  gen objects. The Gen class has the following public interface constructor,
//  calcSequence(), statistics(), reset(),and isActive(). With the implemented
//  public interface the application programmer can create gen objects that retrun
//  a calculated integer from the internalized arithmetic sequence generator.

// ASSUMPTIONS: The user must provide starting value, comon difference, and 
//  number of items in the sequence when creating gen objects. 

// Design Descisions: 
// 1. Upon creation of a Gen object the user provides values for approprite 
//      inital state. However if the given parameters are not valid, default 
//      values are assigned to the internal data members.
// 2. To cycle from 'on' to 'off' states the calcSequence() has to be called
//      10 times to turn off. Once off the user may call the reset() function
//      to put the object back in inital state. The object does not cylce 'on'
//      and 'off' every time the calcSequence() is queried. This is meant to 
//      minimize too many state changes on the object that could result in issues.
// 3. Some of the functions listed in the class design have been made virtual 
//      in order to accomodate for sub-typing. ie. sub classes alter/modify the 
//      function signatues.
// 4. Resetting the object puts the active status back to true and calculated sequence
//      to inital state.
// 5. The object keeps track of the values calculated in the calcSequence. It also 
//      keeps an active count to swich the state from 'on' to 'off'

using System;

namespace p3
{
    class Gen
    {
        protected bool active;
        protected uint activeCount;
        protected uint firstTerm;
        protected uint comondif;
        protected uint numberOfTerms;
        protected int calculatedValue;
        protected const uint MAX_COUNT = 10;

        public Gen(uint a1, uint d, uint n)
        {
            active = true;
            calculatedValue = 0;
            activeCount = 0;

            if (a1 == 0)
            {
                firstTerm = 1;
            }
            else
            {
                firstTerm = a1;
            }
            if (d == 0)
            {
                comondif = 3;
            }
            else
            {
                comondif = d;
            }
            if (n == 0)
            {
                numberOfTerms = 20;
            }
            else
            {
                numberOfTerms = n;
            }
        }
        public virtual string type()
        {
            return "Gen";
        }
        public string statistics()
        {
            string stats = "| Active: " + active + "| active count: " + activeCount + "| calculated value: " + calculatedValue;
            return stats;
        }
        public virtual int calcSequence()
        {
            int value = 0;
            if (isActive())
            {
                activeCount++;
                for (int k = (int)numberOfTerms; k >= 1; k--)
                {
                    value += (int)(firstTerm + comondif * (k - 1));
                }
            }
            calculatedValue = value;
            return value;
        }
        public virtual void reset()
        {
            calculatedValue = 0;
            active = true;
            activeCount = 0;
        }
        public virtual bool isActive()
        {
            if (activeCount > MAX_COUNT)
            {
                active = false;
                activeCount = 0;
            }
            return active;
        }

    }
}
