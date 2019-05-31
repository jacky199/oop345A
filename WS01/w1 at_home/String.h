
#ifndef SICT_STRING_H
#define SICT_STRING_H
#include <iostream>
#include <cstring>
#include "process.h"

namespace sict {
	class String {
		char *str;
	public:
		String(const char* Str);
		void display(std::ostream& os) const;
	};
	std::ostream& operator<<(std::ostream& os, const String& obj);
}
#endif 

