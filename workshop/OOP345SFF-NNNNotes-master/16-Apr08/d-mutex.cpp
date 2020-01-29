#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

char ch{ 'A' };
mutex m;

void task(char* last) {
  int i;
  unique_lock<mutex> lck{ m };
  for (i = 0; i < 10; i++) {
    cout.put(ch);
  }
  *last = ch;
  ch++;
}

int main() {
  // spawn a child thread
  char ct1 = '!', ct2 = '!';
  std::thread t1(task, &ct1);
  // spawn another child thread
  std::thread t2(task, &ct2);
  // continue executing the main thread
  unique_lock<mutex> lck{ m };
  std::cout << "*******" << ch++;
 // lck.unlock();
  // synchronize - IMPORTANT!
  t2.join();
  t1.join();
  cout << endl << "t1 ret: " << ct1 << " t2 ret: " << ct2 << endl;

}