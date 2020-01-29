//-----------------------------------------------------------------
// Name:    Hongbin Li
// Seneca Student ID:   119177178
// Seneca email:    hli261@myseneca.ca
// Date of completion:  1/29/2020
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor.
//------------------------------------------------------------------
#ifndef PAIR_H
#define PAIR_H
#include<iostream>

namespace sdds{
   template <typename K, typename V>
   class Pair {
      K m_key;
      V m_value;
   public:
      Pair(){}
      Pair(const K& key, const V& value){
         m_key = key;
         m_value = value;     
      }
      const K& key() const {
         return m_key;
      }
      const V& value() const {
         return m_value;
      }
      void display(std::ostream& os) const {
         os << m_key << " : " << m_value << std::endl;
      }
   };
   template <typename K, typename V>
   std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
      pair.display(os);
      return os;
   }
}
#endif
