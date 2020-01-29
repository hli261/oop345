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
  if (F) cout << row << ": " << E << endl;
  return !F.fail();
}
int main() {
  Employee E;
  int i = 0;
  ifstream file("employee.dat", ios::binary);
  while (showRec(++i, file));
  showRec(15, file);
  if (!showRec(30, file)) {
    cout << "out of bound!" << endl;
  }



  file.clear();
  file.seekg(0, ios::end);
  cout << "files size: " << file.tellg() << endl;
  cout << "number of recs: " << file.tellg() / sizeof(Employee) << endl;






  file.seekg(0);
  file.read((char*)&E, sizeof(Employee));
  cout << "First Emp rec: " << E << endl;
  file.seekg((std::streamoff) - 1 * sizeof(Employee), ios::end);
  if (file)
    file.read((char*)&E, sizeof(Employee));
  cout << "Last Emp rec: " << E << endl;
  return 0;
}