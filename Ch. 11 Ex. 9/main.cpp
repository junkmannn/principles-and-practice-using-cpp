#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string& s);
void keep_window_open();

int main() {
	string s;
	while (getline(cin, s)) {
		vector<string> v = split(s);
		for (int i = 0, size = v.size(); i < size; ++i) {
			cout << v[i] << '\n';
		}
	}

	cin.clear();

	keep_window_open();

	return 0;
}

vector<string> split(const string& s) {
	vector<string> words;
	istringstream iss(s);
	string word;
	while (iss >> word) words.push_back(word);
	return words;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}