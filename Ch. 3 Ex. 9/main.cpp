#include "../std_lib_facilities.h"

int main() {
	cout << "Enter a spelled-out number (e.g. one). It will then be converted into its digit form.\n";
	string number;
	cin >> number;

	if (number == "zero") {
		cout << "0\n";
	}
	else if (number == "one") {
		cout << "1\n";
	}
	else if (number == "two") {
		cout << "2\n";
	}
	else if (number == "three") {
		cout << "3\n";
	}
	else if (number == "four") {
		cout << "4\n";
	}
	else {
		cout << "Not a number I know\n";
	}

	keep_window_open();
	return 0;
}