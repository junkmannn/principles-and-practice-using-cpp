#include "../std_lib_facilities.h"

bool is_unique(vector<int> &digits, int offset, int digit) {
	vector<int>::iterator first = digits.begin();
	vector<int>::iterator last  = first+offset;
	return find(first, last, digit) == last;
}

void random_digits(vector<int> &digits) {
	for (int i = 0; i < digits.size(); ++i) {
		do {
			digits[i] = randint(9);
		}
		while (!is_unique(digits, i, digits[i]));
	}
}

int main() {
	const int digit_count = 4;
	vector<int> digits_to_guess(digit_count);
	vector<int> digits_guessed(digit_count);

	random_digits(digits_to_guess);

	// cout << digits_to_guess[0] << ' ' << digits_to_guess[1] << ' ' << digits_to_guess[2] << ' ' << digits_to_guess[3] << '\n';

	while (1) {
		int i = 0;
		while (i < digit_count) {
			cout << "Digit " << i+1 << " = ";
			cin >> digits_guessed[i];
			if (!cin.good()) {
				if (cin.eof() || cin.bad()) {
					goto over;
				}
				else {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cerr << "error: must be a digit (0-9)\n";
				}
			}
			else if (digits_guessed[i] >= 0 && digits_guessed[i] <= 9) {
				if (!is_unique(digits_guessed, i, digits_guessed[i])) {
					cerr << "error: all " << digit_count << " digits must different\n";
				}
				else {
					++i;
				}
			}
			else {
				cerr << "error: must be a digit (0-9)\n";
			}
		}

		int bulls = 0;
		int cows = 0;
		for (int i = 0; i < digit_count; ++i) {
			for (int j = 0; j < digit_count; ++j) {
				if (digits_guessed[i] == digits_to_guess[j]) {
					if (i == j) ++bulls;
					else ++cows;
					break;
				}
			}
		}

		cout << "Bulls = " << bulls << ", Cows = " << cows << '\n';
		if (bulls == digit_count) {
			cout << "GG! Play again? Answer 'y' or 'n'.\n";
			char play_again = 'n';
			cin >> play_again;
			if (play_again == 'y') {
				random_digits(digits_to_guess);
			}
			else {
				goto over;
			}
		}
	}

	over:

	keep_window_open();

	return 0;
}
