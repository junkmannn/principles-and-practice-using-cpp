#include <iostream>
#include <string>

using namespace std;

void punct_to_whitespace(string& s);
void keep_window_open();

int main() {
	string s = " - don't use the as-if rule.";
	punct_to_whitespace(s);
	cout << s << '\n';

	keep_window_open();

	return 0;
}

void punct_to_whitespace(string& s) {
	for (int i = 0, size = s.size(); i < size; ++i) {
		if (ispunct(s[i])) s[i] = ' ';
	}
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
