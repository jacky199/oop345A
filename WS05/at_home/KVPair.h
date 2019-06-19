/**********************************************************
 * Name: jack
 * Student ID: 123456789
 * Seneca email:jack@myseneca.ca
 **********************************************************/
#ifndef SICT_KVPair_h
#define SICT_KVPair_h
#include <iostream>
extern int fieldWidth;
namespace sict{
	template<typename K, typename V>
	class KVPair{
		K key;
		V value;
	public:
		KVPair() : key(), value(){}
		KVPair(const K& k, const V& v){
			key = k;
			value = v;
		}
		template<typename F>
		void display(std::ostream& os, F f) const{
			os << std::left << std::setw(fieldWidth) << key << " : "
				<< std::right << std::setw(fieldWidth) << value 
				<< std::setw(fieldWidth)
				<< f(value) << std::endl;
		}
	};
}
#endif