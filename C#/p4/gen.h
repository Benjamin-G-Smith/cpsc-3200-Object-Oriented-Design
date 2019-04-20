// AUTHOR: Ben Smith
// FILENAME: Gen.cs
// DATE: 2/22/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 1.0

// DESCRIPTION: The Gen class allows the application programmer to create
//  gen objects. The Gen class has the following public interface constructor,
//  calcSequence(), statistics(), reset(),and isActive(). With the implemented
//  public interface the application programmer can create gen objects that retrun
//  a calculated integer from the internalized arithmetic sequence generator.

// ASSUMPTIONS: The user must provide starting value, comon difference, and
//  number of items in the sequence when creating gen objects. 1-10 are not
// considered hardcoded values.

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

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef GEN_H
#define GEN_H

class Gen
{
  public:
    Gen();
    Gen(unsigned a1, unsigned d, unsigned n);
    virtual ~Gen(){};
    // pre: none
    // post: none
    // def: returns into about the object
    virtual string statistics();
    // pre: Gen is in a valid state
    // post: Gen might not be in a valid state based on the number of times the
    //  object is called
    virtual int calcSequence();
    // pre: object is in an invalid state
    // post: object is placed back into inital state
    // def: chosing to support the ability to reset the Gen objects to give
    // the application programmer more flexibility
    virtual void reset();
    // pre: none
    // post: object put into invalid state
    virtual bool isActive();

  protected:
    bool active;
    unsigned activeCount;
    unsigned firstTerm;
    unsigned comondif;
    unsigned numberOfTerms;
    int calculatedValue;
    const unsigned MAX_COUNT = 10;
};
#endif
