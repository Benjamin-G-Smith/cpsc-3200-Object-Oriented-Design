// Ben Smith
// burtDub.h
// 2/22/1018
// version 1.0

// DESCRIPTION: The blurtDub class implements both a blurtRep and a
// DubGen object. The user can use all public functionality of the DubGen and
// blurtRep objests
// public interface
// {
//    calcSequence();
//    string statistics();
//    int calcSequence();
//    void reset();
//    bool isActive();
//    bool IsActive();
//    void Reset();
//    string Ping(int state);
//}

// Design Descisions:
// 1.The blurtDub class constructs with both a string and values
//  related to the gen object constructor
// 2. the default constructor and destructor call the base classes
// 3. The blurtDub combines the active state switching of the DubGen and blurtRep
//    in one class so that once the object is no longer in a valid state as either
//    a DubGen or a blurtRep it becomes inactive.
// 4. Does not use virtual inheritance
// 5. The blurtDub class uses a has a relationship with a blurtRep object,
//      echoing the functionality of the blurtRep to get desired functionality

namespace P6
{
    class blurtDub: Gen 
    {
        private blurtRep rep;
        private uint pingCount;
        public blurtDub()
        {
            // precondition all variables are valid
            rep = new blurtRep();
            active = true;
            calculatedValue = 0;
            activeCount = 0;
            pingCount = 0;

            firstTerm = 1;
            comondif = 3;
            numberOfTerms = 20;
        }
        public blurtDub(string blurtW, uint a1 = 1, uint d = 3, uint n = 20) : base(a1, d, n)
        {
            // precondition all variables are valid
            active = true;
            calculatedValue = 0;
            activeCount = 0;
            pingCount = 0;

            firstTerm = a1;
            comondif = d;
            numberOfTerms = n;
            rep = new blurtRep(blurtW);
        }
        // pre: none
        // post: none
        // des: a string containing information about the object is returned
        public string stats()
        {
            string blurtS = "| Rep Word : " + rep.getBlurtWord();
            string blurtA = "| Active : " + rep.IsActive().ToString();
            string blurtP = "| Ping count : " + pingCount.ToString();
            blurtS += " " + blurtA;
            blurtS += " " + blurtP;
            string genStats = statistics();
            return genStats + " " + blurtS;
        }
        // pre: none
        // post: object in either valid or invalid state
        // state must be 1,2, or 3 other values not excpted
        public string ping(string state)
        {
            pingCount++;
            return rep.Ping(state);
        }
        // pre: none
        // post: object put into invalid state
        public bool IsActive()
        {
            return rep.IsActive();
        }
        // pre: object is in an invalid state
        // post: object is placed back into inital state
        // def: chosing to support the ability to reset the Gen objects to give
        // the application programmer more flexibility
        public void Reset()
        {
            pingCount = 0;
            rep.Reset();
        }
        public string getBlurtWord()
        {
            return rep.getBlurtWord();
        }
    }
}
