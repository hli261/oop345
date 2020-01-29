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
  Employee(double sal = 0, int emp = 0, const char *nm = "") {
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
  operator const char*() {
    return name;
  }
  int getsize()const {
    return size;
  }
  virtual ~Employee() {
    delete[] name;
  }
  bool setFromFile(ifstream& EmpFile, ifstream& EmpNameFile) {
    ios::streampos namePos;
    bool res = false;
    delete[] name;
    name = nullptr;
    if (EmpFile.read((char*)this, sizeof(Employee)) && EmpFile.read((char*)&namePos, sizeof(ios::streampos))) {
      EmpNameFile.seekg(namePos);
      name = new char[size + 1];
      if (!EmpNameFile.read(name, size + 1)) {
        delete[] name;
        name = nullptr;
      }
      else{
        res = true;
      }
    }
    return res;
  }
};
ostream& operator<<(ostream& os, const Employee& E) {
  return E.print(os);
}

int main() {
  Employee E;
  int i = 0;
  ifstream file("employeeDMA.dat",ios::binary);
  ifstream nfile("employeeName.dat", ios::binary);
  while (E.setFromFile(file, nfile)) {
    cout << E << endl;
  }
  return 0;
}