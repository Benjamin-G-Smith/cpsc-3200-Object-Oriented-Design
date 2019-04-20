// AUTHOR: Ben Smith
// FILENAME: Program.cs
// DATE: 2/22/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 2.0

// DESCRIPTION: Allows the application programmer to create a driver class using
//  the blurtRep class. The application programmer can create an array of
//  blurtRep object to which random word can be assigned from a given file.

// ASSUMPTIONS: User must provide a valid string to crate a new blurtRep Object.
//  The application programmer must input a valid state change string to alter
//  the state of an object. Count fields are handled internally.

// Design Descisions:
// 1. Upon creation of a 'blurtRep' object a word must be provided
//     in the constructor. If no word is given or the word is too
//     long then the 'DEFAULT_STR' is assigned as the 'blurtStrging'.
//     The 'repetitionCount' is determined by the length of the string
//     provided in the constructor.
// 2. Everytime the 'ping' function is called on a blurtRep object
//      the 'pingCount' is increased by '1'. Once the repetitionCount
//      reaches the 'MAX_PING_COUNT' (10) then the 'valid' state of the
//      object is false. The valid state remains the same until the object
//      is reset.
// 3. Resetting the blurtRep object puts the object back into it's inital
//      state.
// 4. Itteration of fields is handled internally.
// 5. The application programmer may also call the object to access
//      'statistcs' and call the 'IsActive' to learn the validity of the obj.
// 6. Ping count may still count up despite the fact that it is valid or not
// 7. User may all the 'getBlurtWord()' function to get the blurtstring.

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

#ifndef BLURTREP_H
#define BLURTREP_H

class blurtRep
{
  public:
    blurtRep();
    blurtRep(string initailString);
    virtual ~blurtRep(){};
    // pre: none
    // post: object put into invalid state
    bool IsActive();
    // pre: object is in an invalid state
    // post: object is placed back into inital state
    // def: chosing to support the ability to reset the Gen objects to give
    // the application programmer more flexibility
    void Reset();
    // pre: none
    // post: object in either valid or invalid state
    // state must be 1,2, or 3 other values not excpted
    string Ping(int state);
    // computed invariant: ping,repeat,terse
  protected:
    int pingCount;
    int repetitionCount;

    bool valid;
    string blurtString;
    const int MAX_PING_COUNT = 10;
    const int MAX_STRING_LENGTH = 5;
    const int MIN_STRING_LENGTH = 1;
    const string DEFAULT_STR = "bee";

    // pre: none
    // post: values of the object are modified
    void IterateCountFields();
  private:
    // supressing cpoying
    blurtRep(const blurtRep& lhs){};
    void operator=(const blurtRep& lhs);

};
#endif
