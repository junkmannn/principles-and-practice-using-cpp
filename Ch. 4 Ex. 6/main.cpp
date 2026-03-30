#include "../std_lib_facilities.h"

int main() {
	vector<string> numbers_spelled_out(10);
	numbers_spelled_out[0] = "zero";
	numbers_spelled_out[1] = "one";
	numbers_spelled_out[2] = "two";
	numbers_spelled_out[3] = "three";
	numbers_spelled_out[4] = "four";
	numbers_spelled_out[5] = "five";
	numbers_spelled_out[6] = "six";
	numbers_spelled_out[7] = "seven";
	numbers_spelled_out[8] = "eight";
	numbers_spelled_out[9] = "nine";
	vector<string> numbers_digit(10);
	numbers_digit[0] = "0";
	numbers_digit[1] = "1";
	numbers_digit[2] = "2";
	numbers_digit[3] = "3";
	numbers_digit[4] = "4";
	numbers_digit[5] = "5";
	numbers_digit[6] = "6";
	numbers_digit[7] = "7";
	numbers_digit[8] = "8";
	numbers_digit[9] = "9";


	string number = "";
	cin >> number;

	string converted = "";
	for (int i = 0; i < 10; ++i) {
		if (numbers_spelled_out[i] == number) {
			converted = numbers_digit[i];
			break;
		}
		else if (numbers_digit[i] == number) {
			converted = numbers_spelled_out[i];
			break;
		}
	}

	if (converted == "") {
		cout << "must be between 0 and 9 (spelled-out or digit form)\n";
	}
	else {
		cout << converted << '\n';
	}

	keep_window_open();
	return 0;
}