#include <iostream>
#include <iterator>

using namespace std;

int main()
{
  iterator<random_access_iterator_tag, int> ptr;
  int* ptr1  = new int[5];
  ptr1[0] = 5;
  ptr1[1] = 4;
  ptr1[2] = 3;
  ptr1[3] = 2;
  ptr1[4] = 1;

  ptr = Eptr1;
}