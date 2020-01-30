Name: Honbin Li
Student Number£º119177178

#define _CRT_SECURE_NO_WARNING
#include<iostream>
#include"EvenNumber.h"
using namespace std;
namespace sdds {
   EvenNumber::EvenNumber():even(0) {}
   EvenNumber::EvenNumber(int n) {
      if (n % 2 == 0) {
         even = n.even;
      }
      else {
         even = 0;
      }
   }
   int EvenNumber::getValue() const{
      return even;
   }
   EvenNumber EvenNumber::getNext() {
      EvenNumber next;
      if (even % 2 == 0) {
         next.even = even + 2;
      }
      return next;
   }
   EvenNumber EvenNumber::getPrevious() {
      EvenNumber previous;
      if (even % 2 == 0) {
         previous.even = even - 2;
      }
      return previous;
   }
}