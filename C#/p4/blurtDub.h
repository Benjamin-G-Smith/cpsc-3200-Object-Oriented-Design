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
#include "dubGen.h"
#include "blurtReps.h"

using namespace std;

#ifndef BLURTDUB_H
#define BLURTDUB_H

class blurtDub:public blurtRep,public dubGen
{
  public:
    // all nesessary values are declared
    blurtDub();
    // necessary values are assigned with the provided variables
    blurtDub(string initailString, unsigned a1 = 1, unsigned d = 3, unsigned n = 20);
    // Supports the operator overloading function
    blurtDub& operator=(const blurtDub& lhs);
    // pre: none
    // post: none
    // des: a string containing information about the object is returned
    virtual string statistics();
  protected:
  private:
    // parameter copying suppressed
    blurtDub(const blurtDub& lhs);
};
#endif
