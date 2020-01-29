//a = a * b;
//type*  p;
//
//a = a * * b;

#include <iostream>
#include <iomanip>

using namespace std;
void goNext(int** ptr) {
  (*ptr)++;
}

void goNext(int*& r) {
  r++;
}

void addOne(int* valPtr) {
  (*valPtr)++;
}

void strCpy(char *d, const char *s) {
  while (*d++ = *s++);
}
int main(void) {
  int ar[3] = { 2, 4, 6 };
  int*    a = ar;
  cout << *a << endl;
  addOne(a);
  cout << *a << endl;
  goNext(a);
  cout << *a << endl;
  goNext(&a);
  cout << *a << endl;
  return 0;
}