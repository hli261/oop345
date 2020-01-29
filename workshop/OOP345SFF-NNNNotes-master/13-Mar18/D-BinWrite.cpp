#include <iostream>
#include <fstream>
#include "Employee.h"
using namespace std;
int main(void) {
  double d = 1.23454444444444444444444444;
  ofstream file("doubles.bin", ios::binary);
  int i;
  for (i = 1; i <= 10; i++) {
    d = d + i;
    file.write((const char*)&d, sizeof(double));
  }
  return 0;
}
