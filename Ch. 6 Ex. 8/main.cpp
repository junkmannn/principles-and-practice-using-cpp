#include "../std_lib_facilities.h"

int main() {
	const int letters_count = 4;
	vector<char> letters(letters_count);
	letters[0] = 'a';
	letters[1] = 'b';
	letters[2] = 'c';
	letters[3] = 'd';
	vector<char> guess(letters_count);

	while (1) {
		int i = 0;
		while (i < letters_count) {
			cout << "Letter " << i+1 << " = ";
			cin >> guess[i];
			if (!cin.good()) {
				if (cin.eof() || cin.bad()) {
					goto done;
				}
				else {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cerr << "error: must be a letter (a-z)\n";
				}
			}
			else if (guess[i] >= 'a' && guess[i] <= 'z') {
				vector<char>::iterator first = guess.begin();
				vector<char>::iterator last  = first+i;
				if (find(first, last, guess[i]) != last) {
					cerr << "error: all " << letters_count << " letters must be different\n";
				}
				else {
					++i;
				}
			}
			else {
				cerr << "error: must be a letter (a-z)\n";
			}
		}

		int bulls = 0;
		int cows = 0;
		for (int i = 0; i < letters_count; ++i) {
			for (int j = 0; j < letters_count; ++j) {
				if (guess[i] == letters[j]) {
					if (i == j) ++bulls;
					else ++cows;
					break;
				}
			}
		}

		cout << "Bulls = " << bulls << ", Cows = " << cows << '\n';
		if (bulls == letters_count) {
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
