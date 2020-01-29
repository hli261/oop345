#include <iostream>
#include <thread>
using namespace std;
void task1() {
  for (int i = 0; i < 25; i++) {
    cout.put('A' + i);
  }
}
void task2() {
  for (int i = 0; i < 25; i++) {
    cout.put('a' + i);
  }
}

int main() {
  // spawn a child thread
  std::thread t1(task1);
  // spawn another child
  std::thread t2(task2);
  // the main thread
  std::cout << "*******";

  // synchronize
  t2.join();
  t1.join();
}
