#include "../std_lib_facilities.h"

int main() {
	cout << "Enter an integer value\n";
	int val;
	cin >> val;

	if (val % 2 == 0) {
		cout << "The value " << val << " is an even number\n";
	}
	else {
		cout << "The value " << val << " is an odd number\n";
	}

	keep_window_open();
	return 0;
}