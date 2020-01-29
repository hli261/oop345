//-----------------------------------------------------------------
// Name:    Hongbin Li
// Seneca Student ID:   119177178
// Seneca email:    hli261@myseneca.ca
// Date of completion:  1/29/2020
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor.
//------------------------------------------------------------------
#ifndef SET_H
#define SET_H
#include<iostream>
namespace sdds {
   template <typename T, unsigned int N>
   class Set {
      T a[N];
      size_t count;
   public:     
      size_t size()const {
         return count;
      }
      const T& operator[](size_t idx) const {
            return a[idx];         
      }
      void operator+=(const T& item) {
         if (count < N) {
            a[count] = item;
            count++;
         }
      }
   };
}
#endif
