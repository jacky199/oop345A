/**********************************************************
 * Name: Jack 
 * Student ID: 123456789
 * Seneca email:Jack@myseneca.ca
 **********************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"
#include "Timekeeper.h"
using namespace std;
namespace sict {
	Text::Text(){
		nameFile = nullptr;
		num = 0;
	}

	Text::Text(char* text) {
		ifstream is(text);
		if (is.is_open()) {
			std::string l;
			while (getline(is, l)) {
				num++;
			}
			nameFile = new string[num];
			is.clear();
			for (size_t i = 0; i < num; i++) {
				getline(is, nameFile[i]);
			}
			is.close();
		}
	                     else {
			*this = Text();
	}	
	}
	
	Text::Text(Text& text) {
		*this = text;
	} 
	
	Text& Text::operator=(const Text& text){
		if (this != &text){
			delete[] nameFile;
			num = text.num;
			nameFile = new string[num];
			for (size_t i = 0; i < num; i++){
				nameFile[i] = text.nameFile[i];
			}
		}
		return *this;
	}

	Text::~Text(){
		delete[] nameFile;
		nameFile = nullptr;
	}

	size_t Text::size() const{
		return num;
	}
}
