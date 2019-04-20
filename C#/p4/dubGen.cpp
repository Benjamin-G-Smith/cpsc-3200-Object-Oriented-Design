// Ben Smith
// dubGen.cpp
#include "dubGen.h"

// Big 4
int dubGen::calcSequence()
{
  int value = 0;
  if (isActive())
  {
      activeCount++;
      for (int k = static_cast<int>(numberOfTerms); k >= 1; k--)
      {
          if (k % comondif == 0)
          {
            int a = firstTerm;
            int d = comondif;
              value += ((a + d * (k - 1)) * 2); // 2 is not a hard coded val
          }
      }
  }
  calculatedValue = value;
  return value;
}
void dubGen::reset()
{
  calculatedValue += calcSequence();
  active = true;
  activeCount = 0;
}
void dubGen::copy(const dubGen& lhs)
{
  active = lhs.active;
  activeCount = lhs.activeCount;
  firstTerm = lhs.firstTerm;
  comondif = lhs.comondif;
  numberOfTerms = lhs.numberOfTerms;
  calculatedValue = lhs.calculatedValue;
}
