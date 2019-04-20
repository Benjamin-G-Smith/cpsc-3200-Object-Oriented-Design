// Ben Smith
// BlurtRep.cs
// Implementation file

#include "blurtReps.h"

blurtRep::blurtRep()
{
  blurtString = DEFAULT_STR;
  pingCount = 0;
  repetitionCount = blurtString.length();
  valid = true;
}
blurtRep::blurtRep(string initailString)
{
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
blurtRep::blurtRep(const blurtRep& lhs)
{
  blurtString = lhs.blurtString;
  pingCount = lhs.pingCount;
  repetitionCount = lhs.repetitionCount;
  valid = lhs.valid;
}
blurtRep& blurtRep::operator=(const blurtRep& lhs)
{
  if(this != &lhs){
    blurtString = lhs.blurtString;
    pingCount = lhs.pingCount;
    repetitionCount = lhs.repetitionCount;
    valid = lhs.valid;
  }
  return *this;
}
blurtRep blurtRep::operator+(const blurtRep& lhs)
{
  blurtRep local(lhs);
  local.blurtString += blurtString;
  local.repetitionCount = 0;
  local.pingCount = 0;
  return local;
}
bool blurtRep::operator==(const blurtRep& lhs)
{
  return blurtString == lhs.blurtString;
}
bool blurtRep::operator!=(const blurtRep& lhs)
{
  return !(*this == lhs);
}
bool blurtRep::operator>(const blurtRep& lhs)
{
  return repetitionCount > lhs.repetitionCount;
}
bool blurtRep::operator<(const blurtRep& lhs)
{
  return repetitionCount < lhs.repetitionCount;
}
bool blurtRep::operator<=(const blurtRep& lhs)
{
  return (*this < lhs || *this == lhs);
}
bool blurtRep::operator>=(const blurtRep& lhs)
{
  return (*this > lhs || *this == lhs);
}
//blurtRep operator+(const cohortReps& lhs);
//blurtRep operator+(const mixReps& lhs);
string blurtRep::getBlurtWord()
{
  return blurtString;
}

string blurtRep::Ping(int state)
{
  string tempRep = "";
  string temp = "";

  IterateCountFields();
    if (valid){
      switch (state){
        case 1:
         return blurtString;
         break;
        case 2:
         for (int i = 0; i < repetitionCount; i++){
           tempRep += blurtString;
          }
          return tempRep;
          break;
        case 3:
         for (int i = 0; i < MAX_STRING_LENGTH; i++){
           temp += blurtString;
          }
           temp = temp.substr(0, MAX_STRING_LENGTH);
           return temp;
           break;
        default:
           return "Invalid string...";
         }
       }
       else{
         return blurtString;
       }
}
void blurtRep::IterateCountFields()
{
  pingCount++;
  if (pingCount >= MAX_PING_COUNT){
    valid = false;
  }
}
bool blurtRep::IsActive()
{
  return valid;
}
void blurtRep::Reset()
{
  valid = true;
  pingCount = 0;
}
