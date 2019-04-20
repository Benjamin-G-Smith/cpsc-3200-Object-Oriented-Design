// Ben Smith
// skipGen.cpp

#include "skipGen.h"

int skipGen::calcSequence()
{
  int value = 0;
  if (isActive())
  {
      activeCount++;
      for (int k = (int)numberOfTerms; k >= 1; k--)
      {
          if (validValue(k))
          {
              value += (int)(firstTerm + comondif * (k - 1));
          }
      }
  }
  calculatedValue = value;
  return value;
}
bool skipGen::isActive()
{
  if (activeCount > numberOfTerms)
  {
      active = false;
  }
  return active;

}
bool skipGen::validValue(unsigned value)
{
  if(value == 0)
  {
      return false;
  }
  else if (value == 1)
  {
      return false;
  }
  else if (value == numberOfTerms)
  {
      return false;
  }
  else
  {
      return true;
  }
}
