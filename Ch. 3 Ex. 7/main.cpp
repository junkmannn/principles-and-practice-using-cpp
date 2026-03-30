#include "../std_lib_facilities.h"

int main() {
	cout << "Enter three string values\n";

	string val1 = "";
	string val2 = "";
	string val3 = "";
	cin >> val1 >> val2 >> val3;

	string first = "";
	string second = "";
	string third = "";
	if (val1 >= val2) {
		if (val1 > val3) {
			third = val1;
			if (val2 >= val3) {
				second = val2;
				first = val3;
			}
			else {
				second = val3;
				first = val2;
			}
		}
		else {
			third = val3;
			second = val1;
			first = val2;
		}
	}
	else {
		if (val1 < val3) {
			first = val1;
			if (val2 <= val3) {
				second = val2;
				third = val3;
			}
			else {
				second = val3;
				third = val2;
			}
		}
		else {
			first = val3;
			second = val1;
			third = val2;
		}
	}

	cout << first << ", " << second << ", " << third << '\n';

	keep_window_open();
	return 0;
}