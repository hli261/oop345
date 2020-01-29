#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
class Employee {
  double salary;
  int empno;
  char name[31];
public:
  Employee(double sal = 0.0, int emp = 0, const char *nm = "") {
    salary = sal;
    empno = emp;
    strncpy(name, nm, 30);
    name[30] = '\0';
  }
  ostream& print(ostream& os)const {
    return os << name << "," << empno << "," << fixed << setprecision(2) << salary;
  }
  ifstream& read(ifstream& ifs) {
    ifs.get(name, 30, ',');
    ifs.ignore();
    ifs >> empno;
    ifs.ignore();
    ifs >> salary;
    ifs.ignore();
    return ifs;
  }
};
ostream& operator<<(ostream& os, const Employee& E) {
  return E.print(os);
}
ifstream& operator>>(ifstream& ifs, Employee& E) {
  return E.read(ifs);
}
bool showRec(int row, ifstream& F) {
  int i;
  Employee E;
  F.clear();
  F.seekg(0);
  for (i = 0; i < row; i++) {
    F >> E;
  }
  if (F) {
    cout << i << ": " << E << endl;
  }
  else {
    cout << "Record out of bound!" << endl;
  }
  return bool(F);
}
int main() {
  Employee E;
  int i = 0;
  ifstream file("employee.txt");
  while (file>>E) {
      cout << (++i) << ": " << E << endl;
  }
  showRec(12, file);
  showRec(200, file);
  return 0;
}