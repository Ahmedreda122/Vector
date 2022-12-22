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

  // vector<string> v(5);
  // cout << v.size() << endl;
  // v.resize(10);
  // cout << v.size() << endl;
  // cout << v[9];
  AAVector<int> vec2(10);
  cout << vec2.push_back(122) << endl;
  cout << vec2.push_back(8) << endl;
  cout << vec2.push_back(9) << endl;
  cout << vec2.push_back(4) << endl;
  cout << vec2.push_back(333) << endl;
  cout << vec2.push_back(344) << endl;
  cout << vec2.push_back(888) << endl;
  AAVector<int>::Iterator it3 = vec2.begin();
  advance(it1, 2);

  AAVector<int>::Iterator it3 = vec.end();
  cout << vec2;
  vec2.erase(it1, it2);
  cout << vec2;
  AAVector<int> vec3(6);
  vec3.push_back(5);
  vec3.push_back(7);
  AAVector<int> vec4(vec3);
  auto it3 = vec4.begin();
  cout << *it3 << " " << *(it3 + 1) << endl;
  cout << vec4.Capacity() << '\n';
  cout << vec4.Size() << '\n';
}

//..... ^_^ .........