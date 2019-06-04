/**********************************************************
 * Name: Jack ZHAO
 * Student ID: 123456789
 * Seneca email:Jack ZHAO@myseneca.ca
 **********************************************************/
#ifndef LIST_SICT_H
#define LIST_SICT_H

#include <iostream>
#include "LVPair.h"
namespace sict {
	template <typename T, size_t N>
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
	 template<typename T, typename L, typename V, size_t N>
    class LVList : public List<T, N> {
		
    public:
        V accumulate(const L& label) const {
            V v = SummableLVPair<L, V>::getInitialValue();
            for(size_t i=0; i<((List<T, N>&)*this).size(); i++)
                v =(*this)[i].sum(label, v);
            return v;
        }
    };
}
#endif