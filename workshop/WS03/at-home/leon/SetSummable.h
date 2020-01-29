// Name:Xiaoqi Li
// Seneca Student ID:154921183
// Seneca email:xli399@myseneca.ca
// Date of completion:Jan 29,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//SetSummable.h

#ifndef SDDS_SETSUMMABLE_H_
#define SDDS_SETSUMMABLE_H_
#include "Set.h"

namespace sdds {
	template <typename T, unsigned int N,typename K, typename V>
	class SetSummable :public Set<T,N> {
	public:
		V accumulate(const K& key) const {
			V temp;
			temp = this->operator[](0).getInitialValue();
			for (size_t i = 0; i < this->size(); i++) {
				temp = (this->operator[](i)).sum(key, temp);
			}
			return temp;
		}
	};
}

#endif // !1

