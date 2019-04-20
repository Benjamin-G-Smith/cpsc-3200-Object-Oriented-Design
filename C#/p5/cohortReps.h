// AUTHOR: Ben Smith
// FILENAME: cohortReps.h
// DATE: 3/6/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 2.0

// DESCRIPTION: The cohortRep class enables the application programmer
//  to create cohortRep objects. The cohortRep class acts as a container
//  storing a number of blurtRep objects. The cohortRep class can modify
//  the number of blurtReps by adding and removing reps. The cohortRep class
//  implements a holds-a relationship with blurtRep objects. The application
//  programmer has access to the public interface which includes. constructors,
//  getAllActive, add, remove, overloading +,==,!=,=,<,>,<=,>=

// ASSUMPTIONS: The application programmer must construct a cohort object with
// a valid blurtRep array. capacity is also initalized in the construction of
// a cohort object. If the number of blurtRep objects in the data container
// exceeds capacity then an internal resize function is called.

// Design decisions:
//  1. A top variable is implemented to keep track of the current top of the
//      data container.
//  2. The application programmer may 'add' a word to the cohortRep
//  3. Removing a cohortRep only removes the most recent rep added to
//       the container. Look up and remove is not supported.
//  4. Private member functions such as resize and isEmpty handle internal
//      checks that impact how data is stored.

#include <iostream>
#include "blurtReps.h"

using namespace std;

#ifndef COHORTREPS_H
#define COHORTREPS_H

class cohortReps
{
  public:
    cohortReps();
    cohortReps(blurtRep blurtReps[], unsigned size);
    cohortReps(const cohortReps& lhs);
    ~cohortReps();

    string getAllActive();
    bool addRep(blurtRep newRep);
    bool removeRep();

    cohortReps& operator=(const cohortReps& lhs);
    // cohortRep + cohortRep
    // cohortRep + blurtRep
    // ----------------------------------------------------
    // - operator not allowed because subtracting does not make sense within
    // the context of this class
    // cohortRep + cohortRep
    // cohortRep + blurtRep
    // Adding two cohortReps is supported. Adding two cohortReps combines the
    // capacity of both objects.
    cohortReps operator+(const cohortReps& lhs);
    // Adding a blurtRep to a cohortRep is supported. becuse a cohort can add
    //  a blurtRep to the collection. Only adding blurtReps to a cohortRep is
    //  supported
    cohortReps operator+(const blurtRep& lhs);
    // Equality comparision is supported between to cohortReps. One capacity
    //  is compared against another and equality is based on the strings being
    //  an exact match. Does not support other types being added to a blurtRep
    //  becuase it does not make sence in the context of the other classes
    //  defiend. Increment and decrement operators not supported because they
    //  have no meaing in the context of a blurtRep. Because a user can ping
    //  a blurtRep to iterate fields.
    bool operator==(const cohortReps& lhs);
    // Since equality is supported it makes sense to support the ceck for in
    // equality.
    bool operator!=(const cohortReps& lhs);
    // cohortRep != cohortRep capacity comparison or item by item
    // cohort to cohort only
    // ++ increasing size not supported because of internal resizing
    // -- does not make sense for this object
    // not supported because internal resizing it handled and adding
    // to each item in the collection not allowed

    // Greater than opeation only supported between two cohortReps only.
    // Comparison based on the capacity of each cohortRep
    bool operator>(const cohortReps& lhs);
    // same as greater than but for less than
    bool operator<(const cohortReps& lhs);
    // Since equality and less than are supported then it makes sense to
    // supported. based on the resulted of < and ==.
    bool operator<=(const cohortReps& lhs);
    // Same reasons as less than or equal to as to why supported
    bool operator>=(const cohortReps& lhs);

  private:
    void resize();
    bool isEmpty();
    blurtRep** items; // holds the pointers to all 'blurtReps'
    unsigned capacity;
    unsigned top;
    void copy(const cohortReps& lhs);
};
#endif
