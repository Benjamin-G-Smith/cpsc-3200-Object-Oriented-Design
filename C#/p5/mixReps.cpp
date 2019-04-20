// Ben Smith
// NOT USED IN P4 via design document specs
#include "mixReps.h"

mixReps::mixReps()
{
  firstRep = blurtRep();
  secondRep = blurtRep();
  mixCount = 0;
  preference = 0;
}
mixReps::mixReps(blurtRep a, blurtRep b)
{
  firstRep = a;
  secondRep = b;
  mixCount = 0;
  preference = 0;
}
mixReps::mixReps(const mixReps& lhs)
{
  firstRep = lhs.firstRep;
  secondRep = lhs.secondRep;
  mixCount = lhs.mixCount;
  preference = lhs.preference;
}
mixReps& mixReps::operator=(const mixReps& lhs)
{
  if(this != &lhs){
    firstRep = lhs.firstRep;
    secondRep = lhs.secondRep;
    mixCount = lhs.mixCount;
    preference = lhs.preference;
  }
  return *this;
}
mixReps mixReps::operator+(const mixReps& lhs)
{
  mixReps local(lhs);
  local.secondRep = secondRep;
  local.mixCount = (mixCount + local.mixCount / 2);
  return local;
}
mixReps mixReps::operator+(const blurtRep& lhs)
{
  mixReps local(firstRep,lhs);
  return local;
}
//blurtRep operator+(const cohortReps& lhs);
//blurtRep operator+(const mixReps& lhs);

bool mixReps::operator==(const mixReps& lhs)
{
  return mixCount == lhs.mixCount;
}
bool mixReps::operator!=(const mixReps& lhs)
{
  return !(*this == lhs);
}
bool mixReps::operator>(const mixReps& lhs)
{
  return preference > lhs.preference;
}
bool mixReps::operator<(const mixReps& lhs)
{
  return preference < lhs.preference;
}
bool mixReps::operator<=(const mixReps& lhs)
{
  return (*this < lhs || *this == lhs);
}
bool mixReps::operator>=(const mixReps& lhs)
{
  return (*this > lhs || *this == lhs);
}
mixReps::~mixReps()
{

}

string mixReps::getOutPut(int pref, int mix)
{
  return outPutString(pref,mix);
}
string mixReps::outPutString(int pref, int mix)
{
  string outPut = "";
  preference = pref;
  mixCount = mix;

  bool odd = isOdd(preference);

  if (mixCount == 1 && odd)
  {
      string temp = "";
      temp += firstRep.getBlurtWord();
      outPut = temp;
      return outPut;
  }
  else if (mixCount == 1 && !odd)
  {
      string temp = "";
      temp += secondRep.getBlurtWord();
      outPut = temp;
      return outPut;
  }
  else if (mixCount == 2 && odd)
  {
      string temp = "";
      temp += firstRep.getBlurtWord();
      temp += secondRep.getBlurtWord();
      outPut = temp;
      return outPut;
  }
  else
  {
      string temp = "";
      temp += secondRep.getBlurtWord();
      temp += firstRep.getBlurtWord();
      outPut = temp;
      return outPut;
  }
}
bool mixReps::isOdd(int value)
{
  if(value % 2 != 0)
  {
      return true;
  }
  else
  {
      return false;
  }
}
