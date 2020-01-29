#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
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
    ifs.getline(name, 30, ',');
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
  Employee E;
  F.clear();
  F.seekg(ios::streampos((row - 1) * sizeof(Employee)));
  F.read((char*)&E, sizeof(Employee));
  if (F)
    cout << row << ": " << E << endl;
  else
    cout << "Record out of bound!" << endl;
  return !F.fail();

}
int main() {
  Employee E;
  int i = 0;
  ifstream file("employee.dat", ios::binary);
  while(!file.read((char*)&E, sizeof(Employee)).fail()){
    cout << ++i << ": " << E << endl;
  }
  showRec(12, file);
  showRec(22, file);
 
  return 0;
}