/**********************************************************
 * Name: Jack 
 * Student ID: 123456789
 * Seneca email:Jack@myseneca.ca
 **********************************************************/
#ifndef SICT_TEXT_H
#define SICT_TEXT_H
#include <iostream>
#include <string>
using namespace std;
namespace sict {
	class Text {
		string* nameFile;
		size_t num;
	public:
		Text();
		Text(char* text);
		Text(Text& text);
		Text& operator=(const Text& text);
		~Text();
		size_t size() const;
	};
}
#endif 
