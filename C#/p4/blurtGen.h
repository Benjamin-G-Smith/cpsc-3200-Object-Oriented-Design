// Ben Smith
// burtGen.h
// 2/22/1018
// version 1.0

// DESCRIPTION: The blurtGen class implements both a blurtRep and a
// gen object. The user can use all public functionality of the gen and
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
// 1.The blurtGen class constructs with both a string and values
//  related to the gen object constructor
// 2. the default constructor and destructor call the base classes
// 3. The blurtGen combines the active state switching of the gen and blurtRep
//    in one class so that once the object is no longer in a valid state as either
//    a gen or a blurtRep it becomes inactive.
// 4. Does not use virtual inheritance
#include "gen.h"
#include "blurtReps.h"

#ifndef BLURTGEN_H
#define BLURTGEN_H

using namespace std;

class blurtGen:public blurtRep,public Gen
{
  public:
    blurtGen(){};
    // all nesessary values are declared
    blurtGen(string initailString,unsigned a1 = 1, unsigned d = 3, unsigned n = 20);
    // necessary values are assigned with the provided variables
    blurtGen& operator=(const blurtGen& lhs);
    ~blurtGen(){};
    // pre: none
    // post: none
    // des: a string containing information about the object is returned
    virtual string statistics();
};
#endif
