#include "../std_lib_facilities.h"

int main() {
	cout << "Enter three integer values\n";

	int val1 = 0;
	int val2 = 0;
	int val3 = 0;
	cin >> val1 >> val2 >> val3;

	int first = 0;
	int second = 0;
	int third = 0;
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