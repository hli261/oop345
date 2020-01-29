/*Name:Hongbin Li
  Student ID:119177178
  email:hli261@myseneca.ca
  Date:Jan 16,2020

  I confirm that the content of this file is created by me,
  with the exception of the parts provided to me by my professor.
*/
#ifndef EVENT
#define EVENT
extern unsigned int g_sysClock;

namespace sdds {
   //for lab part
   //const int MAX = 128;
   class Event {
      char* description;
      unsigned int clock;
   public:
      Event();
      Event(const Event& source);
      Event& operator=(const Event& source);
      void display() const;
      void setDescription(char*);
      ~Event();
   };
}
#endif
