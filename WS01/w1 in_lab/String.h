
#ifndef SICT_STRING_H
#define SICT_STRING_H
#include <iostream>
#include <cstring>
#include "process.h"

namespace sict {
	const int MAX = 9;
	class String {
		char str[MAX + 1];
	public:
		String(const char* Str);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const String& obj);
}
#endif 
