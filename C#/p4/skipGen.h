// AUTHOR: Ben Smith
// FILENAME: skipGen.cpp
// DATE: 2/22/2018
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

#include <cstdlib>
#include "gen.h"

using namespace std;

#ifndef SKIPGEN_H
#define SKIPGEN_H

class skipGen:public Gen
{
  public:
    skipGen(){};
    skipGen(unsigned a1, unsigned d, unsigned n):Gen(a1,d,n){};
    ~skipGen(){};
    // pre: object is in a valid inital state
    // post: object is in a valid or invalid state
    virtual int calcSequence();
    // pre: none
    // post: object put into invalid state
    virtual bool isActive();
  private:
    // pre: none
    // post: none
    bool validValue(unsigned value);
};
#endif
