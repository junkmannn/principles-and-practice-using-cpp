#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string& s, const string& w);
bool is_user_defined_whitespace(char c, const string &w);
void keep_window_open();

int main() {
	string s;
	string w = ",.;";
	while (getline(cin, s)) {
		vector<string> v = split(s, w);
		for (int i = 0, size = v.size(); i < size; ++i) {
			cout << v[i] << '\n';
		}
	}

	cin.clear();

	keep_window_open();

	return 0;
}

vector<string> split(const string& s, const string& w) {
	vector<string> words;
	string word;

	for (int i = 0, size = s.size(); i < size; ++i) {
		char c = s[i];
		if (isspace(c) || is_user_defined_whitespace(c, w)) {
			if (!word.empty()) {
				words.push_back(word);
				word.clear();
			}
		}
		else {
			word += c;
		}
	}

	if (!word.empty()) words.push_back(word);

	return words;
}

bool is_user_defined_whitespace(char c, const string &w) {
	for (int i = 0, size = w.size(); i < size; ++i) {
		if (c == w[i]) return true;
	}
	return false;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}