

#include <iostream>
#include <thread>
#include <functional>
#include <future>
using namespace std;

void taskA(promise<char>& p) {
  int i;
  char ch = 'A';
  for (i = 0; i < 10; i++) {
    cout.put(ch);
  }
  p.set_value(++ch);
}
void taskB(future<char>& f) {
  int i;
  char ch = f.get();
  for (i = 0; i < 10; i++) {
    cout.put(ch);
  }
}

int main() {
  promise<char> prom;
  future<char> fut = prom.get_future();
  std::thread t1(taskA, ref(prom));
  // spawn another child thread
  std::thread t2(taskB, ref(fut));
  // continue executing the main thread
  std::cout << "*******";
  // synchronize - IMPORTANT!
  t2.join();
  t1.join();

}