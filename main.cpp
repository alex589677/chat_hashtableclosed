// author А.С. Гадиатулин group CPLUS-1006 block Algorithms of C++ module Trie
#include <iostream>
#include "Utilites.h"
#include "Message.h"
#include "HandleGeneral.h"

using std::cout;
using std::endl;

int main() {
	setlocale(LC_ALL, "Russian");

	// call handler file HandleGeneral.h
	callHandleFunction();

	cout << "Game over" << endl;

	return 0;
}