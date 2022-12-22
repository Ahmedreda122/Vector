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
  cout << *it3 << endl ;
  cout << vec6.Capacity() << '\n';
  cout << vec6.Size()<<'\n';
}