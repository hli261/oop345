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
  operator const char*() {
    return name;
  }
  int getsize()const {
    return size;
  }
  virtual ~Employee() {
    delete[] name;
  }
};
ostream& operator<<(ostream& os, const Employee& E) {
  return E.print(os);
}

int main() {
  vector<Employee> E = {
    {12345.67,10235,"Homer Simpson"},
    {23456.89,11236,"Ned Flanders"},
    {34567.9,12495,"Waylon Smithers"},
    {45678,13795,"Lenny Leonard"},
    {56789.1,14236,"Edna Krabappel"},
    {97453.25,15888,"Barry Mackleberry"},
    {512526.32,16852,"Charles Montgomery Burns"},
    {25364.25,17526,"Larry Burns"},
    {12365.32,18369,"Carl Carlson"},
    {12586.25,19485,"Chip Davis"},
    {12893.25,20159,"Joey Crusher"},
    {12369.33,21478,"Jack Marley"},
    {48963.55,22458,"Robert Marlow"},
    {78952.33,23584,"Eugene Fisk"},
    {19379.44,24896,"Mindy Simmons"},
    {12369.55,25789,"Frank Grimes"},
    {79356.33,26741,"Wayne Slater"},
    {82269.55,27596,"Herbert Powell"},
    {16982.22,28456,"Hans Moleman"},
  };
  ofstream file("employeeDMA.dat", ios::binary);
  ofstream datafile("employeeName.dat", ios::binary);
  ios::streampos pos;
  for (auto i: E) {
    file.write((const char*)&i, sizeof(Employee));
    pos = datafile.tellp();
    file.write((const char*)&pos, sizeof(ios::streampos));
    datafile.write((const char*)i, i.getsize() + 1);
  }
  return 0;
}