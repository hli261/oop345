//-----------------------------------------------------------------
// Name:    Hongbin Li
// Seneca Student ID:   119177178
// Seneca email:    hli261@myseneca.ca
// Date of completion:  1/29/2020
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor.
//------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

#ifndef _SDDS_SET_HEADER_
#define _SDDS_SET_HEADER_


namespace sdds {
   template<class T, size_t N>
   class Set {
      T m_setArray[N]{ {} };
      size_t m_index{};

   public:

      size_t size() const {
         return m_index;
      }

      void operator+=(const T& pair) {
         T temp(pair.Key(), pair.Value());
         if (m_index < N) {
            (m_setArray[m_index++]) = temp;
         }
      }

      const T& operator[](size_t idx) const {

         return m_setArray[idx];
      }

   };

}
#endif