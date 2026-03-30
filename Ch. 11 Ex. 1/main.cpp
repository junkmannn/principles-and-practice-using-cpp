#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void keep_window_open();

int main() {
	ifstream ist("uppercase.txt");
	if (!ist) {
		cerr << "Can't open uppercase.txt for reading.\n";
		keep_window_open();
		return 0;
	}

	ofstream ost("lowercase.txt");
	if (!ost) {
		cerr << "Can't open lowercase.txt for writing.\n";
		keep_window_open();
		return 0;
	}

	ist.exceptions(ist.exceptions() | ios::badbit);
	ost.exceptions(ost.exceptions() | ios::badbit);

	try {
		char c;
		while (ist.get(c)) {
			c = tolower(c);
			ost << c;
		}
	}
	catch (ios::failure &e) {
		cerr << "An unexpected error occurred.\n";
	}

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}