//-----------------------------------------------------------------
// Name:    Hongbin Li
// Seneca Student ID:   119177178
// Seneca email:    hli261@myseneca.ca
// Date of completion:  Feb/01/2020
//
// I confirm that the content of this file is created by me, 
// with the exception of the parts provided to me by my professor.
//------------------------------------------------------------------
#ifndef PAIRSUMMABLE_H
#define PAIRSUMMABLE_H
#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;

namespace sdds {
   template<typename K, typename V>
   class PairSummable : public Pair<K, V> {
      static V summation;
      static size_t widthMin;
   public:
      static const V& getInitialValue() {
         return summation;
      }
      PairSummable():Pair<K, V>(){}
      PairSummable(const K& key, const V& value) :Pair<K, V>(key, value) {
         if (widthMin < key.length()) {
            widthMin = key.length();
         }
      }
      V sum(const K& key, const V& val) const {
         return(this->key() == key) ? this->value() + val : val;
      }
      void display(ostream& os) const {
         os << left << setw(widthMin);
         Pair<K, V>::display(os);
         os << right;
      }
   };
   template<typename K, typename V>
   size_t PairSummable<K, V>::widthMin = 0u;

   template<typename K, typename V>
   V PairSummable<K, V>::summation = 0u;

   template<>
   string PairSummable<string, string>::summation = "";

   template<>
   string PairSummable<string, string>::sum(const string& key, const string& value) const {
      string temp = "";
      if (PairSummable<string, string>::key() == key)
      {
         if (value == "") temp = this->value();
         else  temp = value + ", " + this->value();
      }
      else temp = value;
      return temp;  
   }
}
#endif
