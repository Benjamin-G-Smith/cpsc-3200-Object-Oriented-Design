// Ben Smith
// p4.cpp

// DESCRIPTION: Driver class that allows the user to implement blurtGen,
// blurtSkip, and blurtDub objects. The user can use the utilily of multiple
// parent class interfaces in the public interface of the three child classes.
// The program creates three hetrogeneous collections one of blurtGen, one of
// blurtDub, and one of blurtSkip. The program then proforms random manipulations
// on the contained objects to have a variety of data and state change for Each.
// The program then resets any invalid objects back to their original state.
// The program also allows the user to run it as many times as desired to see
// various varients of each object type.

// ASSUMPTIONS: user only wants to see output and provide input to run the
// driver. Only positive values are used in the creation of objects. There is
// a single string array containing words used for initalization.

// Design Descisions:
// 1. Each child class has a hetrogeneous collection
// 2. creation of each object type occurs within a helper function
// 3. The user may run the program as many times as they want

#include "blurtGen.h"
#include "blurtSkip.h"
#include "blurtDub.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// pre: none
// post: a hetrogeneous collection of blurtGens is in valid inital state
void createBlurtGens(blurtGen* collection[],string wordBank[], int size);
// pre: none
// post: a hetrogeneous collection of blurtSkips is in valid inital state
void createSkipGens(blurtSkip* collection[],string wordBank[],int size);
// pre: none
// post: a hetrogeneous collection of blurtDubs is in valid inital state
void createDubGens(blurtDub* collection[],string wordBank[],int size);
// pre: in a valid state or invalid state
// post: resets invalid to a valid state
void resetBlurtGens(blurtGen* collection[], int size);
// pre: in a valid state or invalid state
// post: resets invalid to a valid state
void resetDubGens(blurtDub* collection[],int size);
// pre: in a valid state or invalid state
// post: resets invalid to a valid state
void resetSkipGens(blurtSkip* collection[],int size);
// pre: none
// post: none
string stateString(int val);
// pre: none
// post: none
bool welcome();
// pre: none
// post: none
bool runAgain();

int main()
{
  const int bankSize = 20;
  const int collectionSize = 5;
  const int loopCount = 40;
  srand(time(0));
  string wordBank[bankSize] = {"dress","hip","bless","acute","chest","count","thin",
  "thick","belt","drive","trace","bell","roar","clear","sip","mess","hover",
  "ego","zero", "steep"};

  blurtGen* bGenCollection[collectionSize];
  blurtSkip* bSkipCollection[collectionSize];
  blurtDub* bDubCollection[collectionSize];

  bool run = welcome();
  while(run){

  createBlurtGens(bGenCollection,wordBank,collectionSize);
  createSkipGens(bSkipCollection,wordBank,collectionSize);
  createDubGens(bDubCollection,wordBank,collectionSize);

  cout << "Calling ping and calculate sequence on objects..." << endl;
  cout << "Press Enter to continue...";
  cin.get();
  cin.get();

  int count = 0;
  while(count < loopCount){
    int gindex = rand() % collectionSize;
    int sindex = rand() % collectionSize;
    int dindex = rand() % collectionSize;

    if(bGenCollection[gindex]->IsActive()){
      int state = rand() % 3 + 1; // do not need const values
       cout <<"[blurtGen] "<<stateString(state)<< bGenCollection[gindex]->Ping(state) <<
       " |Sequence calculation of "<<stateString(state)<<": "<< bGenCollection[gindex]->calcSequence() << endl;
       cout << endl;
    }
    if(bSkipCollection[sindex]->IsActive()){
       int state = rand() % 3 + 1; // do not need const values
       cout <<"[blurtSkip] "<<stateString(state)<< bSkipCollection[sindex]->Ping(state) <<
       " |Sequence calculation of "<<stateString(state)<<": "<< bSkipCollection[sindex]->calcSequence() << endl;
       cout << endl;
    }
    if(bDubCollection[dindex]->IsActive()){
      int state = rand() % 3 + 1;// do not need const values
      cout <<"[blurtDub] "<<stateString(state)<< bDubCollection[dindex]->Ping(state) <<
      " |Sequence calculation of "<<stateString(state)<<": "<< bDubCollection[dindex]->calcSequence() << endl;
      cout << endl;
    }
    count++;
  }
  cout << "Displaying statistics of each object: " << endl;
  cout << "Press enter to continue...";
  cin.get();
  for(int k = 0; k < collectionSize; k++){
    cout <<"blurtGen: "<< bGenCollection[k]->statistics() << endl;
    cout <<"blurtSkip: "<< bSkipCollection[k]->statistics() << endl;
    cout <<"blurtDub: "<< bDubCollection[k]->statistics() << endl;
  }
  cout << endl;
  cout << "Reseting invalid objects back to valid state: " << endl;
  cout << "Press enter to continue...";
  cin.get();
  resetBlurtGens(bGenCollection,collectionSize);
  resetSkipGens(bSkipCollection,collectionSize);
  resetDubGens(bDubCollection,collectionSize);

  run = runAgain();

  for(int l = 0; l < collectionSize; l++){
    delete bGenCollection[l];
    delete bSkipCollection[l];
    delete bDubCollection[l];
  }
}
cout << "goodbye..." << endl;
  return 0;
}
bool welcome(){
  string userInput = "";
  cout << "Welcome..." << endl;
  cout << "Program is implementing multiple inheritance using " <<
  "Gen, skipGen, and dubGen with blurtRep to create " <<
  "blurtGen, blurtSkip, and blurtDub" << endl;
  cout << "Would you like to run the program 'y'/'n'?: ";
  cin >> userInput;
  return userInput == "y";
}
bool runAgain()
{
  string userInput = "";
  cout << "Would you like to run the program again 'y'/'n'?: ";
  cin >> userInput;
  return userInput == "y";
}
string stateString(int val)
{
  // do not need const values
  if(val == 1){
    return "[ping] ";
  }
  else if(val == 2){
    return "[repeat] ";
  }
  else if (val == 3){
    return "[terse] ";
  }
  return "null";
}
void resetBlurtGens(blurtGen* collection[], int size)
{
  for(int i = 0; i < size; i++){
    if(!collection[i]->isActive() || !collection[i]->IsActive()){
      collection[i]->reset();
      collection[i]->Reset();
      cout << "Reset blurtGen: " << collection[i]->statistics() << endl;
    }
  }
}
void resetDubGens(blurtDub* collection[],int size)
{
  for(int i = 0; i < size; i++){
    if(!collection[i]->isActive() || !collection[i]->IsActive()){
      collection[i]->reset();
      collection[i]->Reset();
      cout << "Reset blurtSkip: " << collection[i]->statistics() << endl;
    }
  }

}
void resetSkipGens(blurtSkip* collection[],int size)
{
  for(int i = 0; i < size; i++){
    if(!collection[i]->isActive() || !collection[i]->IsActive()){
      collection[i]->reset();
      collection[i]->Reset();
      cout << "Reset blurtDub: " << collection[i]->statistics() << endl;
    }
  }

}
void createBlurtGens(blurtGen* collection[],string wordBank[], int size)
{
  int start = 5;
  int dif = 10;
  int num = 100;
  int nStart = 20;
  for(int i = 0; i < size; i++){
    unsigned a = rand() % start + 1;
    unsigned d = rand() % dif + 1;
    unsigned n = rand() % num + nStart;
    int word = rand() % nStart;
    collection[i] = new blurtGen(wordBank[word],a,d,n);
  }
}
void createSkipGens(blurtSkip* collection[],string wordBank[],int size){
  int start = 5;
  int dif = 10;
  int num = 100;
  int nStart = 20;
  for(int i = 0; i < size; i++){
    unsigned a = rand() % start + 1;
    unsigned d = rand() % dif + 1;
    unsigned n = rand() % num + nStart;
    int word = rand() % nStart;
    collection[i] = new blurtSkip(wordBank[word],a,d,n);
  }
}
void createDubGens(blurtDub* collection[],string wordBank[],int size){
  int start = 5;
  int dif = 10;
  int num = 100;
  int nStart = 20;
  for(int i = 0; i < size; i++){
    unsigned a = rand() % start + 1;
    unsigned d = rand() % dif + 1;
    unsigned n = rand() % num + nStart;
    int word = rand() % nStart;
    collection[i] = new blurtDub(wordBank[word],a,d,n);
  }
}
