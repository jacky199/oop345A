
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;
extern int INITIAL;
namespace sict {
	String::String(const char* Str){
		if (str != nullptr && strlen[Str] != '\0'){
			strncpy(str, Str, MAX);
			str[MAX] = '\0';
		}
		else {
			str[0] = '\0';
		}
	}
	void String::display(std::ostream& os) const{
		os << str;
	}
	std::ostream& operator<<(std::ostream& os, const String& obj){
		static int itemNumber = INITIAL;
		os << itemNumber << ": ";
		obj.display(os);
		itemNumber++;
		return os;
	}
}