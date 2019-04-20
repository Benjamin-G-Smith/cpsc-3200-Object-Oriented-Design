// Ben Smith
// NOT USED IN p4 via design document specs

#include "cohortReps.h"

cohortReps::cohortReps()
{
}
cohortReps::cohortReps(blurtRep blurtReps[], unsigned size = 10)
{
  capacity = size * 2;
  top = -1;
  items = new blurtRep*[capacity];
  for(unsigned i = 0; i < size; i++){
    items[i] = &blurtReps[i];
    top++;
  }
}
cohortReps::cohortReps(const cohortReps& lhs)
{
  items = new blurtRep*[lhs.capacity];
  copy(lhs);
}
cohortReps& cohortReps::operator=(const cohortReps& lhs)
{
  if(this != &lhs){
    delete[] items;
    items = new blurtRep*[lhs.capacity];
    copy(lhs);
  }
  return *this;
}
cohortReps cohortReps::operator+(const cohortReps& lhs)
{
    cohortReps local(*this);
    local.capacity = capacity + lhs.capacity;
    return local;
}
cohortReps cohortReps::operator+(const blurtRep& lhs)
{
  blurtRep temp = lhs;
  cohortReps local(*this);
  local.addRep(temp);
  return local;
}
bool cohortReps::operator==(const cohortReps& lhs)
{
  return capacity == lhs.capacity;
}
bool cohortReps::operator!=(const cohortReps& lhs)
{
  return !(*this == lhs);
}
bool cohortReps::operator>(const cohortReps& lhs)
{
  return capacity > lhs.capacity;
}
bool cohortReps::operator<(const cohortReps& lhs)
{
  return capacity < lhs.capacity;
}
bool cohortReps::operator<=(const cohortReps& lhs)
{
  return (*this < lhs || *this == lhs);
}
bool cohortReps::operator>=(const cohortReps& lhs)
{
  return (*this > lhs || *this == lhs);
}
cohortReps::~cohortReps()
{
  delete[] items;
}
void cohortReps::copy(const cohortReps& lhs)
{
  capacity = lhs.capacity;
  top = lhs.top;
  for(unsigned i = 0; i < top; i++){
    items[i] = lhs.items[i];
  }
}
string cohortReps::getAllActive()
{
  string concatString = "";
  for(unsigned i = 0; i <= top; i++){
    if(items[i]->IsActive()){
      concatString += items[i]->getBlurtWord();
    }
  }
  return concatString;
}
bool cohortReps::addRep(blurtRep newRep)
{
  if(!isEmpty()){
    resize();
  }
  top++;
  blurtRep* ptr = &newRep;
  items[top] = ptr;
  return true;

}
bool cohortReps::removeRep()
{
    items[top] = nullptr;
    top--;
    return true;
}
bool cohortReps::isEmpty()
{
  return top != capacity;
}
void cohortReps::resize()
{
  blurtRep** old = items;
  unsigned oldCap = capacity;
  delete[] items;

  capacity = oldCap * 2;
  items = new blurtRep*[capacity];

  for(unsigned k = 0; k < top; k++){
    items[k] = old[k];
  }
  delete[] old;
}
