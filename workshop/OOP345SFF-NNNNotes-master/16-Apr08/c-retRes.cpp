#include <iostream>
#include <thread>
using namespace std;
void task(char ch, char* last) {
  int i;
  for (i = 0; i < 25; i++) {
    cout.put(ch + i);
  }
  *last = ch + i;
}

int main() {
  // spawn a child thread
  char ct1 = '!', ct2 = '!';
  std::thread t1(task, 'A', &ct1);
  // spawn another child thread
  std::thread t2(task, 'a', &ct2);
  // continue executing the main thread
  std::cout << "*******";
  t2.join();
  t1.join();
  cout << endl << "t1 ret: " << ct1 << " t2 ret: " << ct2 << endl;
}