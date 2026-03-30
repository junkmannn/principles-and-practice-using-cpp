#include "controller_derived2.h"
#include <iostream>

using namespace Graph_lib;
using namespace std;

void Controller_derived2::on() {
	Color c = line->color();
	c.set_visibility(Color::Transparency::visible);
	line->set_color(c);
}

void Controller_derived2::off() {
	Color c = line->color();
	c.set_visibility(Color::Transparency::invisible);
	line->set_color(c);
}

void Controller_derived2::set_level(int i) {
	line->set_color(i);
}

void Controller_derived2::show() const {
	cout << "State: ";
	if (state == ON) cout << "on\n";
	else cout << "off\n";

	cout << "Level: " << level << '\n';
}
