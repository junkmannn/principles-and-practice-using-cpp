#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void reverse_words(ifstream& ist, ofstream& ost);
void keep_window_open();

int main() {
	string filename = "notreversed.txt";
	ifstream ist(filename);
	if (!ist) {
		cerr << "Can't open input file " << filename << ".\n";
		keep_window_open();
		return 0;
	}

	filename = "reversed.txt";
	ofstream ost(filename);
	if (!ost) {
		cerr << "Can't open output file " << filename << ".\n";
		keep_window_open();
		return 0;
	}

	reverse_words(ist, ost);

	keep_window_open();

	return 0;
}

void reverse_words(ifstream& ist, ofstream& ost) {
	vector<string> words;
	string word;

	while (ist >> word) {
		words.push_back(word);
	}

	for (int i = words.size() - 1; i >= 0; --i) {
		ost << words[i] << ' ';
	}
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
