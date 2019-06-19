/**********************************************************
 * Name: Jack
 * Student ID: 123456789
 * Seneca email:Jack@myseneca.ca
 **********************************************************/
#ifndef LIST_SICT_H
#define LIST_SICT_H

#include <iostream>

namespace sict {
	template<class T, int N>
	class List {
		T datatype[N];
		size_t num = 0;
	public:
		size_t size() const { 
			return num;
		}
		const T& operator[](size_t i) const {
			return datatype[i];
		}
		void operator+=(const T& t) {
			if (num < N) {
				datatype[num] = t;
				num++;
			}
		}
	};
}
#endif
