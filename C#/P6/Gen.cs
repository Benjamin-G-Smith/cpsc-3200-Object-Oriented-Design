// AUTHOR: Ben Smith
// FILENAME: Gen.cs
// DATE: 3/15/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 3.0

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


namespace P6
{
    public class Gen
    {
        protected bool active;
        protected uint activeCount;
        protected uint firstTerm;
        protected uint comondif;
        protected uint numberOfTerms;
        protected int calculatedValue;
        protected const uint MAX_COUNT = 10;

        public Gen()
        {
            active = true;
            calculatedValue = 0;
            activeCount = 0;

            firstTerm = 1;
            comondif = 3;
            numberOfTerms = 20;
        }

        public Gen(uint a1 = 1, uint d = 1, uint n = 20)
        {
            active = true;
            calculatedValue = 0;
            activeCount = 0;

            firstTerm = a1;
            comondif = d;
            numberOfTerms = n;

        }
        // pre: none
        // post: none
        // def: returns into about the object
        public string statistics()
        {
            string acount = activeCount.ToString();
            string cvalue = calculatedValue.ToString();
            string activestr = active.ToString();
            string stats = "Active: " + activestr + "| active count: " + acount + "| calculated value: " + cvalue;
            return stats;
        }
        // pre: Gen is in a valid state
        // post: Gen might not be in a valid state based on the number of times the
        //  object is called
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
        // pre: object is in an invalid state
        // post: object is placed back into inital state
        // def: chosing to support the ability to reset the Gen objects to give
        // the application programmer more flexibility
        public virtual void reset()
        {
            calculatedValue = 0;
            active = true;
            activeCount = 0;
        }
        // pre: none
        // post: object put into invalid state
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
