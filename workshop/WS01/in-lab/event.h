/*Name:Hongbin Li
  Student ID:119177178
  email:hli261@myseneca.ca
  Date:Jan 15,2020

  I confirm that the content of this file is created by me,
  with the exception of the parts provided to me by my professor.
*/
#ifndef EVENT
#define EVENT
#include <iostream>
extern unsigned int g_sysClock;

namespace sdds {
   const int MAX = 128;  
   class Event {
      char description[MAX];
      unsigned int clock;
   public:
      Event();
      void display() const;
      void setDescription(char*);
   };
}
#endif
