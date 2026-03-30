#include <iostream>
#include "Graph.h"

using namespace std;
using namespace Graph_lib;

void keep_window_open();

int main() {
	Circle c1(Point(100,100), 30);
	Circle c2(Point(200,200), 60);
	// Error	1	error C2280:
	// 'Graph_lib::Shape &Graph_lib::Shape::operator =(const Graph_lib::Shape &)' :
	// attempting to reference a deleted function
	// c:\users\adrian\documents\visual studio 2013\projects\principles and practice using c++\ch. 14 ex. 2\main.cpp	17	1	Ch. 14 Ex. 2
	// c1 = c2;

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit\n";
	char c;
	cin >> c;
}
