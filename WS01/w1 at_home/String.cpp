
#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;
extern int INITIAL;
namespace sict {
	String::String(const char* Str){
		if (Str != nullptr && strlen(Str) != '\0'){
			str = new char [strlen(Str)+1];
			strncpy(str,Str,(strlen(Str)+1));
		}
		else {
			str = nullptr;
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