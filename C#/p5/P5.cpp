// AUTHOR: Ben Smith
// FILENAME: p5.cpp
// DATE: 3/6/2018
// PLATFORM ( visual studio, 2018 )
// VERSION: 1.0

// DESCRIPTION: Driver class for blurtRep, cohortRep, and mixRep objects.
//  The user can access the interface of all objects to preform various
//  actions involving the overloaded operators as well as the original
//  functionality of the classes. P5 is a test driver showing the
//  implementation of overloaded operators on blurtRep, cohortRep, and mixRep
//  objects. The driver tests all overloaded operators in each class.

// ASSUMPTIONS: user only wants to see output and provide input to run the
// driver. Only positive values are used in the creation of objects. There is
// a single string array containing words used for initalization.

// Design Descisions:
// 1. To demonstrate overloaded operator implementation the program uses
//  multiple arrays containint blurtReps and mixReps with random values. two
//  cohortReps have been defined to hold two blurtRep arrays. An array of
//  cohortReps is not necssary in the testing of the overloaded operators.
// 2. Each overloaed operation is demonstrated through random calls to each
//  array ant then the subsequent operator calls are envoked.
// 3. The results of each operation are displayed to the user via confromation
//  messages for ease of reading.
// 4. Not all operators have been overloaded and as a result only valid
//  operations are allowed.

#include "cohortReps.h"
#include "mixReps.h"
#include "blurtReps.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// pre: There must be valid blurtRep, cohortRep, and Mixrep objects initalized
//  to a valid state.
// post: The states of the objects could be in either a valid or invalid state
// Invariant: uses the public interface only
void testAddidion(blurtRep bRep[], cohortReps cRep,cohortReps cRep2, mixReps mRep[], int size);
// pre: There must be valid blurtRep, cohortRep, and Mixrep objects initalized
//  to a valid state.
// post: The states of the objects do not change
// Invariant: uses the public interface only
void testEquality(blurtRep bRep[], cohortReps cRep,cohortReps cRep2, mixReps mRep[], int size);
// pre: There must be valid blurtRep, cohortRep, and Mixrep objects initalized
//  to a valid state.
// post: The states of the objects do not change
// Invariant: uses the public interface only
void testComparisonOperators(blurtRep bRep[], cohortReps cReps,cohortReps cReps2, mixReps mRep[], int size);
// pre: none
// post: a  collection of blurtReps is in valid inital state
// Invariant: uses the public interface only
void createBlurtReps(blurtRep collection[],string wordBank[], int size);
// pre: none
// post: a  collection of mixReps is in valid inital state
// Invariant: uses the public interface only
void createMixReps(mixReps collection[],blurtRep reps[], int size);

int main()
{
  const int bankSize = 20;
  string userInput = "";
  srand(time(0));
  string wordBank[bankSize] = {"dress","hip","bless","acute","chest","count","thin",
  "thick","belt","drive","trace","bell","roar","clear","sip","mess","hover",
  "ego","zero", "steep"};

  cout << "Testing operator overloading on blurtReps, cohortReps, and mixReps..." << endl;
  cout << "Would you like to run the program [y/n]?" << endl;
  cin >> userInput;
  while(userInput == "y"){
    // initalization of objects into valid states
    blurtRep reps[bankSize];
    blurtRep reps2[bankSize];
    createBlurtReps(reps,wordBank,bankSize);
    createBlurtReps(reps2,wordBank,bankSize);

    cohortReps cReps(reps,bankSize);
    cohortReps cReps2(reps2,bankSize);

    mixReps mReps[bankSize];
    createMixReps(mReps,reps,bankSize);

    // Testing of operator functionality
    testAddidion(reps,cReps,cReps2,mReps,bankSize);
    cout << "Press Enter to continue:"<<endl;
    cin.get();
    cin.get();
    testEquality(reps,cReps,cReps2,mReps,bankSize);
    cout << "Press Enter to continue:"<<endl;
    cin.get();
    testComparisonOperators(reps,cReps,cReps2,mReps,bankSize);
    cout << "Press Enter to continue:"<<endl;
    cin.get();
    cout <<"Would you like to run the program again [y/n]?"<<endl;
    cin >> userInput;
  }
  cout << "Goodbye..." << endl;

  return 0;
}
void createBlurtReps(blurtRep collection[],string wordBank[], int size)
{
  for(int i = 0; i < size; i++){
    int randomWordIndex = rand() % size;
    collection[i] = blurtRep(wordBank[randomWordIndex]);
  }
}
void createMixReps(mixReps collection[],blurtRep reps[], int size)
{
  for(int i = 0; i < size; i++){
    int blurtA = rand() % size;
    int blurtB = rand() % size;
    collection[i] = mixReps(reps[blurtA],reps[blurtB]);
  }
}
void testAddidion(blurtRep bRep[], cohortReps cRep, cohortReps cRep2, mixReps mRep[], int size)
{
  int blurtRep = rand() % size;
  int mixRep = rand() % size;

  cout << "blurtRep + blurtRep: complete" << endl;
  bRep[blurtRep] + bRep[mixRep];
  cout << endl;

  cout << "cohortRep + blurtRep: complete" << endl;
  blurtRep = rand() % size;
  cRep + bRep[blurtRep];
  cout << endl;

  cout << "cohortRep + cohortRep: complete" << endl;
  cRep + cRep2;
  cout << endl;

  cout << "mixRep + mixRep: complete" << endl;
  blurtRep = rand() % size;
  mixRep = rand() % size;
  mRep[blurtRep] + mRep[mixRep];
  cout << endl;

  cout << "mixRep + blurtRep: complete" << endl;
  blurtRep = rand() % size;
  mixRep = rand() % size;
  mRep[mixRep] + bRep[blurtRep];
  cout << endl;

}
void testEquality(blurtRep bRep[], cohortReps cRep,cohortReps cRep2, mixReps mRep[], int size)
{
  int b1 = rand() % size;
  int b2 = rand() % size;

  cout <<"blurtRep == blurtRep: complete" << endl;
  if(bRep[b1] == bRep[b2]){
    cout << "blurtReps are equal" << endl;
  }
  else{
    cout << "blurtReps not equal" << endl;
  }
  cout << endl;
  cout <<"cohortRep == cohortRep: complete"<< endl;
  if(cRep == cRep2){
    cout << "cohortReps are equal" << endl;
  }
  else{
    cout <<"cohortReps are not equal"<< endl;
  }
  cout << endl;
  cout <<"mixRep == mixRep: complete"<< endl;
  b1 = rand() % size;
  b2 = rand() % size;
  if(mRep[b1] == mRep[b2]){
    cout << "mixReps are equal"<<endl;
  }
  else{
    cout << "mixReps are not equal"<<endl;
  }
  cout << endl;
}
void testComparisonOperators(blurtRep bRep[], cohortReps cReps,cohortReps cReps2, mixReps mRep[], int size)
{
  int b1 = rand() % size;
  int b2 = rand() % size;

  cout << "blurtRep a > blurtRep b: [complete]" << endl;
  if(bRep[b1] > bRep[b2]){
    cout << "blurtRep a is greater than b" << endl;
  }
  else{
    cout << "b is greater than blurtRep a"<<endl;
  }
  cout << endl;
  cout << "blurtRep a < blurtRep b: [complete]" << endl;
  b1 = rand() % size;
  b2 = rand() % size;
  if(bRep[b1] < bRep[b2]){
    cout << "blurtRep a is less than b" << endl;
  }
  else{
    cout << "b is less than blurtRep a"<<endl;
  }
  cout << endl;
  cout << "blurtRep a <= blurtRep b: [complete]" << endl;
  b1 = rand() % size;
  b2 = rand() % size;
  if(bRep[b1] <= bRep[b2]){
    cout << "blurtRep a is less than or equal to b" << endl;
  }
  else{
    cout << "b is less than or equal to blurtRep a"<<endl;
  }
  cout << endl;
  cout << "blurtRep a >= blurtRep b: [complete]" << endl;
  b1 = rand() % size;
  b2 = rand() % size;
  if(bRep[b1] >= bRep[b2]){
    cout << "blurtRep a is greater than or equal to b" << endl;
  }
  else{
    cout << "b is greater than or equal to blurtRep a"<<endl;
  }
  cout << endl;
  cout << "cohortRep a > cohortRep b: [complete]" << endl;
  if(cReps > cReps2){
    cout << "cohortRep a is greater than b" << endl;
  }
  else{
    cout << "b is greater than cohortRep a"<<endl;
  }
  cout << endl;
  cout << "cohortRep a < cohortRep b: [complete]" << endl;
  if(cReps < cReps2){
    cout << "cohortReps a is less than b" << endl;
  }
  else{
    cout << "b is less than cohortReps a"<<endl;
  }
  cout << endl;
  cout << "cohortRep a <= cohortRep b: [complete]" << endl;
  if(cReps <= cReps2){
    cout << "cohortRep a is less than or equal to b" << endl;
  }
  else{
    cout << "b is less than or equal to cohortRep a"<<endl;
  }
  cout << endl;
  cout << "cohortRep a >= cohortRep b: [complete]" << endl;
  if(cReps >= cReps2){
    cout << "cohortRep a is greater than or equal to b" << endl;
  }
  else{
    cout << "b is greater than or equal to cohortRep a"<<endl;
  }
  cout << endl;

  cout << "mixRep a > mixRep b: [complete]" << endl;
  if(mRep[b1] > mRep[b2]){
    cout << "mixRep a is greater than b" << endl;
  }
  else{
    cout << "b is greater than mixRep a"<<endl;
  }
  cout << endl;
  cout << "mixRep a < mixRep b: [complete]" << endl;
  b1 = rand() % size;
  b2 = rand() % size;
  if(mRep[b1] < mRep[b2]){
    cout << "mixRep a is less than b" << endl;
  }
  else{
    cout << "b is less than mixRep a"<<endl;
  }
  cout << endl;
  cout << "mixRep a <= mixRep b: [complete]" << endl;
  b1 = rand() % size;
  b2 = rand() % size;
  if(mRep[b1] <= mRep[b2]){
    cout << "mixRep a is less than or equal to b" << endl;
  }
  else{
    cout << "b is less than or equal to mixRep a"<<endl;
  }
  cout << endl;
  cout << "mixRep a >= mixRep b: [complete]" << endl;
  b1 = rand() % size;
  b2 = rand() % size;
  if(mRep[b1] >= mRep[b2]){
    cout << "mixRep a is greater than or equal to b" << endl;
  }
  else{
    cout << "b is greater than or equal to mixRep a"<<endl;
  }
  cout << endl;
}
