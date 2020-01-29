#include <list>
#include <iostream>
using namespace std;
#include "Employee.h"
int main() {
  list<Employee> E;  // initially empty
  list<Employee>::iterator i;
  E.push_back({ "Larry Burns", 11234 });   // add 10.43
  E.push_back({ "Carl Carlson", 21234 });   // add 20.54
  E.push_back({ "Frank Grimes", 31234 });   // add 32.43
  E.insert(--E.end(), { "Homer Simpson", 123 });
  for (i = E.begin(); i != E.end(); i++)
    std::cout << *i << endl;
  E.erase(++E.begin());
  cout << "after erase" << endl;
  for (auto j = E.begin(); j != E.end(); j++)
    std::cout << *j << endl;
  std::cout << std::endl;
}