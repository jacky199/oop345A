
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "process.h"
using namespace std;
using namespace sict;
int INITIAL = 3;
int main(int argc, char* argv[]) {
	if (argc <= 1){
		cout << "***Insufficient number of arguments***" << endl;
		return 1;
	}
	else {
		cout << "Command Line : ";
		for (int i = 0; i < argc; i++){
			cout << argv[i] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i < argc; i++){
		process(argv[i]);
	}
	return 0;
}