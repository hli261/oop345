#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
class Employee {
  double salary;
  int empno;
  char* name;
  int size;
public:
  Employee(double sal=0, int emp=0, const char *nm="") {
    salary = sal;
    empno = emp;
    size = strlen(nm);
    name = new char[size + 1];
    strcpy(name, nm);
  }
  Employee(const Employee& E) :Employee(E.salary, E.empno, E.name) {}
  ostream& print(ostream& os)const {
    return os << name << "," << empno << "," << fixed << setprecision(2) << salary;
  }
  virtual ~Employee() {
    delete[] name;
  }
};

ostream& operator<<(ostream& os, const Employee& E) {
  return E.print(os);
}

int main() {
  Employee E;
  int i = 0;
  ifstream file("employeeDMA.dat",ios::binary);
  while (file.read((char*)&E, sizeof(Employee))) {
    cout << ++i << ": " << E << endl;
  }
  return 0;
}