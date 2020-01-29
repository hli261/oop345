#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

char ch{ 'A' };
mutex m;

void put_ch(int x, char &ch) {
//  unique_lock<mutex> lck{ m };
  cout << x << ch;
  ch++;
}

void task(int x, char* last) {
  int i;
  for (i = 0; i < 10; i++) {
    put_ch(x, ch);
  }
  *last = ch;
}

int main() {
  // spawn a child thread
  char ct1 = '!', ct2 = '!';
  std::thread t1(task, 1, &ct1);
  // spawn another child thread
  std::thread t2(task, 2, &ct2);
  // continue executing the main thread
  std::cout << "*******";
  // synchronize
  t2.join();
  t1.join();
  cout << endl << "t1 ret: " << ct1 << " t2 ret: " << ct2 << endl;
}
