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

#include <cstdlib>
#include "gen.h"

using namespace std;

#ifndef DUBGEN_H
#define DUBGEN_H

class dubGen:public Gen
{
  public:
    dubGen(){};
    dubGen(unsigned a1, unsigned d, unsigned n):Gen(a1,d,n){};
    ~dubGen(){};
    // pre: object is in a valid inital state
    // post: object is in a valid or invalid state
    virtual int calcSequence();
    // pre: object is in a invalid state
    // post: object is in a valid state
    virtual void reset();
  protected:
  private:
    // pre: two valid dubGen objects
    // post: both have the same data values
    void copy(const dubGen& lhs);
};
#endif
