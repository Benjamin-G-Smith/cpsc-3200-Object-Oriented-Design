// Ben Smith
// gen.cpp

#include "gen.h"

// Big 4
Gen::Gen()
{
  active = true;
  calculatedValue = 0;
  activeCount = 0;

  firstTerm = 1;
  comondif = 3;
  numberOfTerms = 20;

}
Gen::Gen(unsigned a1 = 1, unsigned d = 3, unsigned n = 20)
{
  active = true;
  calculatedValue = 0;
  activeCount = 0;

  firstTerm = a1;
  comondif = d;
  numberOfTerms = n;
}
int Gen::calcSequence()
{
  int value = 0;
  if (isActive()){
    activeCount++;
    for (int k = (int)numberOfTerms; k >= 1; k--)
    {
        value += (int)(firstTerm + comondif * (k - 1));
    }
  }
  calculatedValue = value;
  return value;
}
string Gen::statistics()
{
  string acount = to_string(activeCount);
  string cvalue = to_string(calculatedValue);
  string activestr = to_string(active);
  string stats = "Active: " + activestr + "| active count: " + acount + "| calculated value: " + cvalue;
  return stats;
}
void Gen::reset()
{
  calculatedValue = 0;
  active = true;
  activeCount = 0;
}
bool Gen::isActive()
{
  if (activeCount > MAX_COUNT){
    active = false;
    activeCount = 0;
  }
  return active;
}
