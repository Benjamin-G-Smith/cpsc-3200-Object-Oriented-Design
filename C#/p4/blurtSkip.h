// Ben Smith
// burtSkip.h
// 2/22/1018
// version 1.0

// DESCRIPTION: The blurtSkip class implements both a blurtRep and a
// skipGen object. The user can use all public functionality of the skipGen and
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
// 1.The blurtSkip class constructs with both a string and values
//  related to the gen object constructor
// 2. the default constructor and destructor call the base classes
// 3. The blurtSkip combines the active state switching of the SkipGen and blurtRep
//    in one class so that once the object is no longer in a valid state as either
//    a SkipGen or a blurtRep it becomes inactive.
// 4. Does not use virtual inheritance

#include "blurtReps.h"
#include "skipGen.h"

#ifndef BLURTSKIP_H
#define BLURTSKIP_H

class blurtSkip:public blurtRep,public skipGen
{
  public:
    // all nesessary values are declared
    blurtSkip();
    // necessary values are assigned with the provided variables
    blurtSkip(string initailString,unsigned a1 = 1, unsigned d = 3, unsigned n = 20);
    // Supports the operator overloading function
    blurtSkip& operator=(const blurtSkip& lhs);
    // pre: none
    // post: none
    // des: a string containing information about the object is returned
    virtual string statistics();
  protected:
  private:
    // parameter copying suppressed
    blurtSkip(const blurtSkip& lhs);
};
#endif
