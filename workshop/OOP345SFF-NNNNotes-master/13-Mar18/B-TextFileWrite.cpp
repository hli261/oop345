#include <iostream>
#include <fstream>
#include "Employee.h"
using namespace std;
int main(void) {
  Employee E[4] = { { "Larry Burns", 11234 } ,
                    { "Carl Carlson", 21234 } ,
                    {"Frank Grimes", 31234 },
                    { "Homer Simpson", 123 }};
  ofstream file("Employee.txt");
  int i;
  for (i = 0; i < 4; i++) {
    file << E[i] << endl;
  }

  return 0;
}
