#include <iostream>
#include <iterator>
#include "AAVector.imp"
using namespace std;


int main()
{
  AAVector<int> vec(5);
  cout << vec.push_back(122) << endl;
  cout << vec.push_back(5) << endl;
  cout << vec.push_back(2) << endl;
  cout << vec.push_back(4) << endl;
  cout << vec.push_back(8) << endl;
  cout << "Cap: " << vec.Capacity() << endl;
  cout << vec.push_back(12) << endl;
  cout << "Cap: " << vec.Capacity() << endl;
  vec[20];
  AAVector<int>::Iterator it = vec.begin();
  cout << *it << endl;
  ++it;
  cout << *it << endl;
  --it;
  cout << *it << endl;
  cout << "size: " << vec.Size() << endl;
  int n = vec.pop_back();
  cout << n << endl;
  cout << "size: " << vec.Size() << endl;
  vec.erase(++vec.begin());
  cout << vec[1] << endl;
  vec.erase(++vec.end());
  AAVector<int> vec1(6);
  vec1.push_back(1);
  AAVector<int> vec2(vec1);
  auto it1 = vec2.begin();
  cout << *it1 << endl ;
  cout << vec2.Capacity() << '\n';
  cout << vec2.Size()<<'\n';
}


//..... ^_^ .........