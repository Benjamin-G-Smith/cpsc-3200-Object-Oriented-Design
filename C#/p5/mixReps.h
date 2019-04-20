// AUTHOR: Ben Smith
// FILENAME: mixReps.h
// DATE: 3/6/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 2.0

// DESCRIPTION: Allows the application programmer to create a mixRep object.
//  The mixRep class suports the following public interface constructor, getOutPut().
//  The mix rep class does not support full copying, only a bitwise copy. The mix
//  rep class also implements a has--a relationship with the blurtRep.cs class.
//  overloading +,-,==,!=,++,--,=,+=,-=


// ASSUMPTIONS: Assumes that the output for the mixRep class is returned from
//  internal function calls. Does not support copying.

// Design decisions:
//  1. The two blurtRep objects x and z are defined withing the class.
//  2. mixCount and preference are passed in as values.
//  3. the public member function getOutPut returns a string
//  4. Private member functions isOdd and OutPutString determing the output string
//      as well as checking the preference to see if it is odd or even.

// The first type, mixReps, has 2 blurtReps objects (call them x and z), a preference and a mixCount and
// Outputs as only ‘x’ when mixCount == 1 and preference is odd
// Outputs as only ‘z’ when mixCount == 1 and preference is even
// Outputs as ‘x’ followed by ‘z’ when mixCount ==2 and preference is odd
// Outputs as ‘z’ followed by ‘x’ when mixCount ==2 and preference is even

#include <iostream>
#include "blurtReps.h"

using namespace std;

#ifndef MIXREPS_H
#define MIXREPS_H

class mixReps
{
  public:
    mixReps();
    mixReps(blurtRep a, blurtRep b);
    mixReps(const mixReps& lhs);
    mixReps& operator=(const mixReps& lhs);
    ~mixReps();

    string getOutPut(int pref, int mix);
    // Adding two cohortReps is supported. Adding two mixReps combines the
    // capacity of both objects.
    mixReps operator+(const mixReps& lhs);
    // Adding a blurtRep to a mixRep is supported. becuse a mixRep can add
    //  a blurtRep to its collection. Only adding blurtReps to a mixRep is
    //  supported no other types can be added.
    mixReps operator+(const blurtRep& lhs);
    // Equality comparision is supported between to mixReps. One capacity
    //  is compared against another and equality is based on the strings being
    //  an exact match. Does not support other types being added to a blurtRep
    //  becuase it does not make sence in the context of the other classes
    //  defiend. Increment and decrement operators not supported because they
    //  have no meaing in the context of a blurtRep. Because a user can ping
    //  a blurtRep to iterate fields.
    bool operator==(const mixReps& lhs);
    // Since equality is supported it makes sense to support the ceck for in
    // equality.
    bool operator!=(const mixReps& lhs);
    // Greater than opeation only supported between two mixReps only.
    // Comparison based on the preference count of each mixReps.
    bool operator>(const mixReps& lhs);
    // same as greater than but for less than
    bool operator<(const mixReps& lhs);
    // Since equality and less than are supported then it makes sense to
    // supported. based on the resulted of < and ==.
    bool operator<=(const mixReps& lhs);
    // Same reasons as less than or equal to as to why supported
    bool operator>=(const mixReps& lhs);

  private:
    string outPutString(int pref, int mix);
    bool isOdd(int value);
    blurtRep firstRep;
    blurtRep secondRep;
    int mixCount;
    int preference;
};
#endif
