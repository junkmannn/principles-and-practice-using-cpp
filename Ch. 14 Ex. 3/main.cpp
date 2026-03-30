#include <iostream>

using namespace std;

class Abstract {
public:
	virtual void pvf() = 0;
private:

};

void keep_window_open();

int main() {
	// Error	1	error C2259: 'Abstract' : cannot instantiate abstract class	c:\users\adrian\documents\visual studio 2013\projects\principles and practice using c++\ch. 14 ex. 3\main.cpp	15	1	Ch. 14 Ex. 3
	// Abstract abstract;

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit\n";
	char c;
	cin >> c;
}
