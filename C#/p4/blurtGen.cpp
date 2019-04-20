// Ben Smith
// blurtGen.cpp

#include "blurtGen.h"

blurtGen::blurtGen(string initailString, unsigned a1, unsigned d, unsigned n)
{
  // precondition all variables are valid
  active = true;
  calculatedValue = 0;
  activeCount = 0;

  firstTerm = a1;
  comondif = d;
  numberOfTerms = n;

  blurtString = initailString;
  pingCount = 0;
  int strLength = initailString.length();
  if (strLength > MAX_STRING_LENGTH || strLength < MIN_STRING_LENGTH)
  {
      blurtString = DEFAULT_STR;
  }
  repetitionCount = blurtString.length();
  valid = true;

}
blurtGen& blurtGen::operator=(const blurtGen& lhs)
{
  if(this != &lhs){
    active = lhs.active;
    activeCount = lhs.activeCount;
    firstTerm = lhs.firstTerm;
    comondif = lhs.comondif;
    numberOfTerms = lhs.numberOfTerms;
    calculatedValue = lhs.calculatedValue;
    blurtString = lhs.blurtString;
    repetitionCount = lhs.repetitionCount;
    valid = lhs.valid;
    pingCount = lhs.pingCount;
  }
  return *this;
}
string blurtGen::statistics()
{
  string acount = to_string(activeCount);
  string cvalue = to_string(calculatedValue);
  string activestr = to_string(active);

  string repstr = to_string(repetitionCount);
  string pingstr = to_string(pingCount);
  string validstr = to_string(valid);

  string stats = "Active: " + activestr + "| active count: " + acount + "| calculated value: " + cvalue
  + " Valid: " + validstr + "| pingCount: " + pingstr+ "| RepCount: " + repstr;
  return stats;
}
