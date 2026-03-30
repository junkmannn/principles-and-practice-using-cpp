#include "../std_lib_facilities.h"

int main() {
	// lowercase letters
	cout << "lowercase letters\n";
	for (int i = 'a'; i <= 'z'; ++i) {
		cout << char(i) << '\t' << i << '\n';
	}

	cout << "\nuppercase letters\n";
	// uppercase letters
	for (int i = 'A'; i <= 'Z'; ++i) {
		cout << char(i) << '\t' << i << '\n';
	}

	cout << "\ndigits\n";
	// uppercase letters
	for (int i = '0'; i <= '9'; ++i) {
		cout << char(i) << '\t' << i << '\n';
	}

	keep_window_open();

	return 0;
}