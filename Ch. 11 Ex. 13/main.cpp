#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void char_class_count(int stats[], ifstream& ist);
void keep_window_open();

const int NUM_CLASS = 11;

const int SPACE  = 0;
const int ALPHA  = 1;
const int DIGIT  = 2;
const int XDIGIT = 3;
const int UPPER  = 4;
const int LOWER  = 5;
const int ALNUM  = 6;
const int CNTRL  = 7;
const int PUNCT  = 8;
const int PRINT  = 9;
const int GRAPH  = 10;

int main() {
	string filename = "filetoanalyse.txt";
	ifstream ist(filename);
	if (!ist) {
		cerr << "Can't open input file " << filename << ".\n";
		keep_window_open();
		return 0;
	}

	int stats[NUM_CLASS] = { };
	// analyse file
	char_class_count(stats, ist);

	cout << "Count for each character classification: \n";
	cout << "Whitespaces: "                  << stats[SPACE] << '\n';
	cout << "Letters: "                      << stats[ALPHA] << '\n';
	cout << "Decimal digits: "               << stats[DIGIT] << '\n';
	cout << "Hexadecimal digits: "           << stats[XDIGIT] << '\n';
	cout << "Uppercase letters: "            << stats[UPPER] << '\n';
	cout << "Lowercase letters: "            << stats[LOWER] << '\n';
	cout << "Letters or decimal digits: "    << stats[ALNUM] << '\n';
	cout << "Control characters: "           << stats[CNTRL] << '\n';
	cout << "Punctuations: "                 << stats[PUNCT] << '\n';
	cout << "Printable characters: "         << stats[PRINT] << '\n';
	cout << "Has graphical representation: " << stats[GRAPH] << '\n';

	keep_window_open();

	return 0;
}

void char_class_count(int stats[], ifstream& ist) {
	char c = 0;
	while (ist.get(c)) {
		if (isspace(c))  ++stats[SPACE];
		if (isalpha(c))  ++stats[ALPHA];
		if (isdigit(c))  ++stats[DIGIT];
		if (isxdigit(c)) ++stats[XDIGIT];
		if (isupper(c))  ++stats[UPPER];
		if (islower(c))  ++stats[LOWER];
		if (isalnum(c))  ++stats[ALNUM];
		if (iscntrl(c))  ++stats[CNTRL];
		if (ispunct(c))  ++stats[PUNCT];
		if (isprint(c))  ++stats[PRINT];
		if (isgraph(c))  ++stats[GRAPH];
	}
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
