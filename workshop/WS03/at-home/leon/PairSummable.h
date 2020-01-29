 // Name:Xiaoqi Li
// Seneca Student ID:154921183
// Seneca email:xli399@myseneca.ca
// Date of completion:Jan 29,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//PairSummable.h

#ifndef SDDS_PAIRSUMMABLE_H_
#define SDDS_PAIRSUMMABLE_H_
#include <iostream>
#include <string>
#include "Pair.h"
using namespace std;

namespace sdds {
	template <typename K, typename V>
	class PairSummable : public Pair<K,V> {
		static V s_value;
		static size_t s_width;
	public:
		static const V& getInitialValue() {
			return s_value;
		}
		PairSummable():Pair<K, V>(){}
		PairSummable(const K& key, const V& value) :Pair<K,V>(key, value) {
			if (s_width < key.size()) {
				s_width = key.size();
			}
		}
		V sum(const K& key, const V& val) const {			
			return (this->key() == key)? (this->value()+val):val;
		}
		void display(ostream& os) const {
			os << left << setw(s_width);
			Pair<K, V>::display(os);
			os << right;
		}
	};

	template <typename K, typename V>
	size_t PairSummable<K, V>::s_width = 0u;

	template <typename K, typename V>
	V PairSummable<K, V>::s_value = 0u;

	template<>
	string PairSummable<string, string>::s_value = "";
	
	template<>
	int PairSummable<string, int>::s_value = 0;
	
	template<>
	string PairSummable<string, string>::sum(const string& key, const string& val) const {
      return (this->key() == key) ? (val == "" ? this->value() : val + ", " + this->value()) : val;
	}
}

#endif // !SDDS_PAIR_H_

