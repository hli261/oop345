
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m;

void show(int& v, int calledBy) {
  unique_lock<mutex> lck{ m };
  std::cout << v << " at " << &v << "called by: t" << calledBy << std::endl;
  v += 10;
}

void task(int no) {
  static int num = 10;
  for (int i = 0; i < 3; i++) {
    show(num, no);
  }
}

int main() {
  std::thread t1(task,1);
  std::thread t2(task,2);
  t1.join();
  t2.join();
}