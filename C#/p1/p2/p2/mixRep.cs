using System;
using System.Collections.Generic;
using System.Text;

/*
The first type, mixReps, has 2 blurtReps objects (call them x and z), a preference and a mixCount and
Outputs as only ‘x’ when mixCount == 1 and preference is odd
Outputs as only ‘z’ when mixCount == 1 and preference is even
Outputs as ‘x’ followed by ‘z’ when mixCount ==2 and preference is odd
Outputs as ‘z’ followed by ‘x’ when mixCount ==2 and preference is even
*/
namespace p2
{
    class mixRep
    {
        private blurtRep x;
        private blurtRep z;
        private int mixCount;
        private int preference;
        private const string state = "plain";
        public mixRep()
        {
            x = new blurtRep("x");
            z = new blurtRep("z");
            mixCount = 0; // Cycles between 1 and 2 randomly 
            preference = 0; // set when called to be a random number 1 - 10

        }
        public void GetOutPut()
        {
            string str = OutPutString();

        }
        private string OutPutString()
        {
            string outPut = "";
            // set preference
            bool odd = isOdd(preference);
            if(mixCount == 1 && odd)
            {
                outPut += x.Ping(state);
            }
            else if (mixCount == 1 && !odd)
            {
                //outPut += 
            }
            return outPut;
        }
        private bool isOdd(int value)
        {
            if(value % 1 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
