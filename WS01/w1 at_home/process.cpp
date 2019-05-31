// Workshop 1 - Linkage, Storage Duration, Namespaces, and OS Interface
// process.cpp
// Chris Szalwinski
// 2019/01/08
/**********************************************************
 * Name: JACK ZHAO
 * 
 * Seneca email:JACK ZHAO@myseneca.ca
 **********************************************************/
#include <iostream>
#include "String.h"

namespace sict {
	void process(const char* str) {
		String a = String(str);
		std::cout << a << std::endl;
	}
}
