#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Line {
	int number;
	string content;
	Line(int num, string cont) : number(num), content(cont) { };
};

/**
 * Returns all lines and lines number in the file that contains the given word.
 * Throws std::ios_base::failure if an unrecoverable occurred while reading the file.
 */
vector<Line> lines_containing_word(ifstream& ist, string &word);

int main() {
	cout << "Please enter input file name and the word to search for: ";
	string name, word;
	cin >> name >> word;

	ifstream ist(name.c_str());
	if (!ist) {
		cerr << "Error: can't open input file " << name << '\n';
	}
	else {
		try {
			vector<Line> lines = lines_containing_word(ist, word);
			cout << "Lines that contain the word " << word << ".\n";
			for (Line line : lines) {
				cout << line.number << ". " << line.content << '\n';
			}
		}
		catch (ios_base::failure &e) {
			cerr << "Error: exception opening/reading/closing file.\n";
		}
	}

	char c;
	cin >> c;

	return 0;
}

vector<Line> lines_containing_word(ifstream& ist, string &word) {
	ist.exceptions(ist.exceptions() | ios_base::badbit);

	vector<Line> lines;
	int i = 1;
	while (!ist.eof()) {
		string s;
		getline(ist, s);
		if (s.find(word) != string::npos) {
			lines.push_back(Line(i, s));
		}
		++i;
	}

	return lines;
}