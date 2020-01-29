#include <iostream>
#include <fstream>
#include "Employee.h"
using namespace std;
int main(void) {
  double d;
  ifstream file("doubles.bin", ios::binary);
  int i;
  for (i = 1; i <= 10; i++) {
    file.read((char*)&d, sizeof(double));
    cout << d << endl;
  }
  return 0;
}
