#include "controller_derived1.h"
#include <iostream>

using namespace std;

void Controller_derived1::show() const {
	cout << "State: ";
	if (state == ON) cout << "on\n";
	else cout << "off\n";

	cout << "Level: " << level << '\n';
}
