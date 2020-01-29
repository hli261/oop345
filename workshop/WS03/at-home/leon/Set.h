// Name:Xiaoqi Li
// Seneca Student ID:154921183
// Seneca email:xli399@myseneca.ca
// Date of completion:Jan 29,2020
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
//Set.h
#ifndef SDDH_SET_H_
#define SDDH_SET_H_

namespace sdds {
	template <typename T, unsigned int N>
	class Set {
		T arr[N];
		size_t n=0;
	public:
		size_t size() const {
			return n;
		}
		const T& operator[](size_t idx) const {
			return arr[idx];
		}
		void operator+=(const T& item) {
			if (n < N) {				
				arr[n] = item;
				n++;
			}
		}
	};


}

#endif // !SDDH_SET_H
