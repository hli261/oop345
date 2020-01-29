#include <iostream>
#include <thread>
using namespace std;
void task(char ch) {
  for (int i = 0; i < 25; i++) {
    cout.put(ch + i);
  }
}

int main() {
  // spawn a child thread
  std::thread t1(task, 'A');
  // spawn another child thread
  std::thread t2(task, 'a');
  // continue executing the main thread
  std::cout << "*******";

  // synchronize - IMPORTANT!
  t2.join();
  t1.join();
}