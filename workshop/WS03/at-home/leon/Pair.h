// Name:Xiaoqi Li
// Seneca Student ID:154921183
// Seneca email:xli399@myseneca.ca
// Date of completion:Jan 29,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//Pair.h

#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
#include <iostream>

namespace sdds {
	template <typename K,typename V>
	class Pair {
		K p_key;
		V p_value;
	public:
		Pair():p_key(), p_value() {}
		Pair(const K& key, const V& value) {
			p_key = key;
			p_value = value;
		}
		const K& key() const {
			return p_key;
		}
		const V& value() const {
			return p_value;
		}
		virtual void display(std::ostream& os) const {
			os << p_key << " : " << p_value << std::endl;
		}
	};
	template <typename K, typename V>
	std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif // !SDDS_PAIR_H

