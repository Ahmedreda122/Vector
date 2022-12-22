#include <iostream>
#include <iterator>
#include <vector>
#include "AAVector.imp"
using namespace std;

int main()
{
  AAVector<int> vec(15);
  cout << vec.push_back(122) << endl;
  cout << vec.push_back(5) << endl;
  cout << vec.push_back(2) << endl;
  vec.erase(++vec.begin());
  cout << vec[1] << endl;
  vec.erase(++vec.end());

  AAVector<int> vec2(10);
  cout << vec2.push_back(122) << endl;
  cout << vec2.push_back(8) << endl;
  cout << vec2.push_back(9) << endl;
  cout << vec2.push_back(4) << endl;
  cout << vec2.push_back(333) << endl;
  cout << vec2.push_back(344) << endl;
  cout << vec2.push_back(888) << endl;
  AAVector<int>::Iterator it1 = vec2.begin();
  advance(it1, 2);

  AAVector<int>::Iterator it2 = vec.end();
  cout << vec2;
  vec2.erase(it1, it2);
  cout << vec2;

  // -------------------------------------------------------
  AAVector<int> vec5(6);
  vec5.push_back(1);
  AAVector<int> vec6(vec5);
  AAVector<int>::Iterator it3 = vec6.begin();
  cout << *it3 << endl;
  cout << vec6.Capacity() << '\n';
  cout << vec6.Size() << '\n';

  AAVector<int> vec7(6);
  vec7.push_back(4);
  AAVector<int>::Iterator it4 = vec7.begin();
  AAVector<int> vec8(9);
  AAVector<int>::Iterator it5 = vec8.begin();
  vec8 = vec7 = vec6;
  vec8.push_back(7);
  cout << *it4 << endl;
  cout << *(it5 + 1) << endl;
  cout << vec8.Capacity() << '\n';

  int *arr;
  int sz = 5;
  arr = new int[sz];
  *arr = 3;
  *(arr + 1) = 2;
  *(arr + 2) = 4;
  AAVector<int> vec9(arr, 5);
  AAVector<int>::Iterator it6 = vec9.begin();
  cout << *(it6 + 2) << endl;
  cout << vec9.Capacity() << endl;
  cout << vec9.Size() << endl;

  AAVector<int> vec10(7);
  vec10.push_back(4);
  vec10.push_back(5);
  AAVector<int> vec11(6);
  vec11.push_back(5);
  vec11.push_back(5);
  if (vec10 < vec11)
  {
    cout << "YES" << endl;
  }
  cout << "-------------\n";
  AAVector<int> vec12(7);
  vec12.push_back(2);
  vec12.push_back(3);
  vec12.push_back(5);
  vec12.push_back(6);
  vec12.push_back(7);
  vec12.insert(vec12.begin()+2,4);
  for (auto i = vec12.begin(); i != ++vec12.end(); i++)
  {
    cout << *i << " ";
  }
  
}