#include "../std_lib_facilities.h"

int main() {
	const int digit_count = 4;
	vector<int> number(digit_count);
	number[0] = 1;
	number[1] = 2;
	number[2] = 3;
	number[3] = 4;
	vector<int> guess(digit_count);

	while (1) {
		int i = 0;
		while (i < digit_count) {
			cout << "Digit " << i+1 << " = ";
			cin >> guess[i];
			if (!cin.good()) {
				if (cin.eof() || cin.bad()) {
					goto done;
				}
				else {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cerr << "error: must be a digit (0-9)\n";
				}
			}
			else if (guess[i] >= 0 && guess[i] <= 9) {
				vector<int>::iterator first = guess.begin();
				vector<int>::iterator last  = first+i;
				if (find(first, last, guess[i]) != last) {
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
				if (guess[i] == number[j]) {
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
			if (play_again != 'y') goto done;
		}
	}

	done:

	keep_window_open();

	return 0;
}
