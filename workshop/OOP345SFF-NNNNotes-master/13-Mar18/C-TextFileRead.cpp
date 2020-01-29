#include <iostream>
#include <fstream>
#include "Employee.h"
using namespace std;
int main(void) {
  Employee E;
  ifstream file("Employee.txt");
  int i;
  while (file) {
    file >> E;
    if(file) cout << ((const char*)E) << endl;
  }
  return 0;
}
