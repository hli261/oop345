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
bool showRec(int row, fstream& F) {
  Employee E;
  F.clear();
  F.seekg(ios::streampos((row - 1) * sizeof(Employee)));
  F.read((char*)&E, sizeof(Employee));
  if (F) cout << row << ": " << E << endl;
  return !F.fail();
}
void listEmployees(fstream& file) {
  for (int i = 1; showRec(i, file); i++);
  file.clear();
}
int main() {
  Employee E;
  Employee Freddie = { 92365.32,30369,"Freddie Soley" };
  int i = 0;
  fstream file("employee.dat", ios::in | ios::out | ios::binary);
  listEmployees(file);
  file.seekp(ios::streampos(17 * sizeof(Employee)));
  file.write((const char*)&Freddie, sizeof(Employee));
  listEmployees(file);
  return 0;
}