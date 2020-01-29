
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m;

thread_local int v = 10; // static for separate tasks.

void show(int calledBy) {
  unique_lock<mutex> lck{ m };
  std::cout << v << " at " << &v << " called by: t" << calledBy << std::endl;
  v += 10;
}

void task(int no) {
  for (int i = 0; i < 3; i++) {
    show(no);
  }
}

int main() {
  std::thread t1(task, 1);
  std::thread t2(task, 2);
  t1.join();
  t2.join();
  show(0);
}