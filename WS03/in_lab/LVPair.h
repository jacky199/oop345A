/**********************************************************
 * Name: Jack 
 * Student ID: 123456789
 * Seneca email:Jack@myseneca.ca
 **********************************************************/
#ifndef LVPair_SICT_H
#define LVPair_SICT_H

#include <iostream>
namespace sict {
	template<typename L, typename V>
	class LVPair {
		L label;
		V value;
	public:
		LVPair() : label(), value() {}
		LVPair(const L& Label, const V& Value) {
			label = Label;
			value = Value;
		}
		void display(std::ostream& os) const {
			os << label << " : " << value << std::endl;
		}
	};

	template<typename L, typename V>
	std::ostream& operator<< (std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}
}

#endif 
