#include <iostream>

using namespace std;

void keep_window_open();

int main() {
	int a;
	int b;
	int c;
	int d;
	cin >> a >> hex >> b >> oct >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
