//-----------------------------------------------------------------
// Name:    Hongbin Li
// Seneca Student ID:   119177178
// Seneca email:    hli261@myseneca.ca
// Date of completion:  Feb/01/2020
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor.
//------------------------------------------------------------------
#ifndef SETSUMMABLE_H
#define SETSUMMABLE_H
#include "Set.h"

namespace sdds {
   template<typename T, size_t N, typename K, typename V>
   class SetSummable :public Set<T, N> {
   public:
      SetSummable():Set<T, N>(){}
      V accumulate(const K& key) const {
         V item;
         item = this->operator[](0).getInitialValue();
         for (size_t i = 0; i < this->size(); i++) {
            item = (this->operator[](i)).sum(key, item);
         }
         return item;
      }
   };
}
#endif