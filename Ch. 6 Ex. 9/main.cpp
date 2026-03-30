#include "../std_lib_facilities.h"

string spell_out(const char digit, const string & base_10) {
	string output = digit + (' ' + base_10);
	if (digit > '1') {
		output += 's';
	}
	return output;
}

bool is_digit_only(string & digits) {
	for (int i = 0, length = digits.length(); i < length; ++i) {
		if (digits[i] < '0' || digits[i] > '9') {
			return false;
		}
	}
	return true;
}

int main() {
	const int max_digits = 4;
	const vector<string> base_10 = {"thousand", "hundred", "ten", "one"};

	cout << "This program reads an integer value (" << max_digits << " digits max) and spells it out.\n";

	string digits = ""; // input variable
	while (cin >> digits) { // while input is not EOF
		bool overflow = false;
		int length = digits.length();
		// if the number of digits exceeds the max, ignore the rest
		if (length > max_digits) {
			overflow = true;
			length = max_digits;
		}

		// check if input contains digit only
		if (!is_digit_only(digits)) {
			cerr << "Input must be all digits.\n";
			continue;
		}

		// warning
		if (overflow) {
			cout << "Max number of digits (" << max_digits << ") has been exceeded.\nThe rest of the input will be ignored.\n";
		}

		int i = 0; // input string iterator
		int i2 = max_digits-length; // base_10 vector iterator
		int exponent = length-1; // exponent
		int digits_to_int = (digits[i]-'0') * pow(10, exponent); // builds int from string
		string output = spell_out(digits[i], base_10[i2]); // output string

		for (++i, ++i2, --exponent; i < length; ++i, ++i2, --exponent) {
			digits_to_int += (digits[i]-'0') * pow(10, exponent);
			output += " and " + spell_out(digits[i], base_10[i2]);
		}

		cout << digits_to_int << " is " << output << ".\n";
	}

	keep_window_open();

	return 0;
}