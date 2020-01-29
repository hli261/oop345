






#include <iostream>
#include <iomanip>

using namespace std;

using namespace std;
class Employee {
  double salary;
  int empno;
  char name[31];
public:
  Employee(double sal=0.0, int emp=0, const char *nm="No name") {
    salary = sal;
    empno = emp;
    strncpy(name, nm, 30);
    name[30] = '\0';
  }
  operator const char*() {
    return name;
  }
  ostream& print(ostream& os)const {
    return os << name << "," << empno << "," << fixed << setprecision(2) << salary;
  }
};
ostream& operator<<(ostream& os, const Employee& E) {
  return E.print(os);
}

void SayHello(shared_ptr<Employee> E) {
  cout << "Hello, I am " << (const char*)(*E) << ". How are you? " << endl;
}



int main(void) {
  int ar[3] = { 2, 4, 6 };
  int*    a = ar;
  Employee* e = new Employee[3];

  cout << int(a) << " next is at "<<  int(a+1) << endl;
  cout << int(e) << " next is at " << int(e+1) << endl;
  cout << a[0] << "     " << *(a + 0) << endl;


  delete[] e;
  return 0;
}