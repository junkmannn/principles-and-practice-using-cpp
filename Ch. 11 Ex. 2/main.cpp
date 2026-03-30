#include <fstream>
#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char c);
void keep_window_open();

int main() {
	string filename = "vowels.txt";
	ifstream ist(filename);
	if (!ist) {
		cerr << "Can't open " << filename << " for reading.\n";
		keep_window_open();
		return 0;
	}

	filename = "novowels.txt";
	ofstream ost(filename);
	if (!ost) {
		cerr << "Can't open " << filename << " for writing.\n";
		keep_window_open();
		return 0;
	}

	ist.exceptions(ist.exceptions() | ios::badbit);
	ost.exceptions(ost.exceptions() | ios::badbit);

	try {
		string s;
		while (ist >> s) {
			int s_size = s.size();
			int removed = 0;
			for (int i = 0; i < s_size; ++i) {
				char c = s[i];
				if (!is_vowel(c)) ost << c;
				else ++removed;
			}
			if (removed != s_size) ost << ' ';
		}
	}
	catch (ios::failure &e) {
		cerr << "An unexpected error occurred.\n";
	}

	keep_window_open();

	return 0;
}

bool is_vowel(char c) {
	c = tolower(c);
	switch (c) {
	case 'a': case 'e': case 'i': case 'o': case 'u':
		return true;
	}
	return false;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
