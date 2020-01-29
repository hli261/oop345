#include <iostream>
using namespace std;
#include "Deque.h"
using namespace std;
std::ostream& operator<<(std::ostream& os, const Deque& Q) {
  for (unsigned int i = 0; i < Q.size(); i++) {
    os << Q[i] << " ";
  }
  return os;
}
int main() {
  Deque Q;
  double v;
  Q.push_back(0.0);
  for ( v = 1.2; v < 5.0; v += 1.0) {
    Q.push_back(v);
  }
  for (;v < 10.0; v += 1.0) {
    Q.push_front(v);
  }
  cout << Q << endl;
  cout << Q.front() << endl;
  cout << Q.back() << endl;
  Q.pop_back();
  cout << Q.front() << endl;
  cout << Q.back() << endl;
  Q.pop_front();
  cout << Q.front() << endl;
  cout << Q.back() << endl;
  cout << Q << endl;
  return 0;
}