/*Name:Hongbin Li
  Student ID:119177178
  email:hli261@myseneca.ca
  Date:Jan 15,2020

  I confirm that the content of this file is created by me,
  with the exception of the parts provided to me by my professor.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "event.h"

unsigned int g_sysClock = 0;
namespace sdds {
   static unsigned int COUNTER = 0;

   Event::Event() {
      strcpy(description,"");
      clock = 0;
   }
   void Event::display() const {
      COUNTER++;
      if (strlen(description) != 0) {        
         cout << setw(3) << setfill(' ') << COUNTER << ".";
         cout << setw(2) << setfill('0') << clock/3600 << ":";
         cout << setw(2) << setfill('0') << clock%3600/60 << ":";
         cout << setw(2) << setfill('0') << clock%60 << " -> ";
         cout << description << endl;
      }
      else {
         cout << setw(3) << setfill(' ') << COUNTER << ". [ No Event ]" << endl;
      }
   }
   void Event::setDescription(char* string) {
      if (string != nullptr) {         
         strcpy(description, string);                    
      }
      else         
         strcpy(description, "[ No Event ]");
      clock = g_sysClock;
   }
};
