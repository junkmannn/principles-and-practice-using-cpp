#include "../std_lib_facilities.h"

int main() {
	vector<string> disliked_words;
	disliked_words.push_back("rust");
	disliked_words.push_back("violence");
	disliked_words.push_back("pain");
	string word = "";
	while (cin >> word) {
		if (find(disliked_words.begin(), disliked_words.end(), word) != disliked_words.end()) {
			cout << "BLEEP\n";
		}
		else {
			cout << word << '\n';
		}
	}

	keep_window_open();

	return 0;
}