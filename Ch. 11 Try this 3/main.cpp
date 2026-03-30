#include <iostream>

using namespace std;

void keep_window_open();

int main() {
	double d = 1234567.89;
	cout << d << '\n';
	cout << fixed << d << '\n';
	cout << scientific << d << '\n';

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
