/*Name:Hongbin Li
  Student ID:119177178
  email:hli261@myseneca.ca
  Date:Jan 16,2020

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
      //for lab part
      //description[0] = '\0';
      description = nullptr;
      clock = 0;
   }
   void Event::display() const {
      COUNTER++;
      if (description != nullptr) {        
         cout << setw(3) << setfill(' ') << COUNTER << ". ";
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
         delete[] description;//setDescription function - introduces memory leak
         //- not deleting the old resources owned by this object
         description = new char[strlen(string) + 1];
         strcpy(description, string); 
         clock = g_sysClock;
      }
      else
      {
         clock = 0;
         description = nullptr;
      }
   }
   Event::Event(const Event& source) {
      clock = source.clock;
      if (source.description != nullptr) {
         description = new char[strlen(source.description) + 1];
         strcpy(description, source.description);
      }
      else {
         clock = 0;
         description = nullptr;
      }
   }
   Event& Event::operator=(const Event& source) {
      if (this != &source) {
         clock = source.clock;
         //copy assignment function - introduces memory leak 
         //- not deleting the old resources owned by this object
         delete[] description;
         if (source.description != nullptr) {
            description = new char[strlen(source.description) + 1];
            strcpy(description, source.description);
         }
         else {
            clock = 0;
            description = nullptr;
         }
      }
      return *this;
   }
   Event::~Event() {
      delete[] description;
   }
};
