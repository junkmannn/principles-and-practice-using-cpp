#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void merge(ifstream &ist1, ifstream &ist2, ofstream &ost);
void open_read(const string &fname, ifstream &ist);
void open_write(const string &fname, ofstream &ost);
bool read_word(ifstream &ist, string &str);
void read_rest_into(ifstream &ist, ofstream &ost);
// inline bool is_really_eof(ifstream &ist);

int main() {
	cout << "This program will merge two files containing sorted white-separated words and preserve the order.\n";

	ifstream ist1, ist2;
	ofstream ost;

	// get file names from user
	cin.exceptions(cin.exceptions() | ios::eofbit);
	string ifname1, ifname2, ofname;
	try {
		cout << "Input file name 1: ";
		getline(cin, ifname1);
		cout << "Input file name 2: ";
		getline(cin, ifname2);
		cout << "Output file name: ";
		getline(cin, ofname);
	}
	// CTRL+Z
	catch (ios::failure &e) {
		cin.clear();
		goto over;
	}

	// all three files must be different
	if (ifname1 == ifname2 || ifname1 == ofname || ifname2 == ofname) {
		cerr << "All three files must be different.\n";
		goto over;
	}

	// open files
	try {
		open_read(ifname1, ist1);
		open_read(ifname2, ist2);
		open_write(ofname, ost);
	}
	// will throw if one of the files could not be opened and supplies error message in e.what().
	catch (runtime_error &e) {
		cerr << e.what() << '\n';
		goto over;
	}

	// merge
	try {
		merge(ist1, ist2, ost);
		cout << "Merge successful!\n";
	}
	// error message speaks for itself
	catch (ios::failure &e) {
		cerr << "An unexpected error occured while merging the files.\n";
		goto over; // just to keep it consistent
	}

	over:
	cout << "Please enter a character to exit\n";
	char c;
	cin >> c;

	return 0;
}

/*
void merge(ifstream &ist1, ifstream &ist2, ofstream &ost) { // v1
	class f1_eof { };
	class f2_eof { };

	string str1;
	string str2;
	int where = 0;

	try {
		while (1) {
			if (where != 1) {
				str1 = "";
				ist1 >> str1;
				if (str1.empty()) throw f1_eof();
			}
			if (where != 2) {
				str2 = "";
				ist2 >> str2;
				if (str2.empty()) throw f2_eof();
			}

			if (str1 == str2) {
				where = 0;
				ost << str1 << '\n' << str2 << '\n';
			}
			else if (str1 < str2) {
				where = 1;
				do {
					ost << str1 << '\n';
					str1 = "";
					ist1 >> str1;
					if (str1.empty()) {
						ost << str2 << '\n';
						throw f1_eof();
					}
				} while (str1 < str2);
				ost << str2 << '\n';
			}
			else {
				where = 2;
				do {
					ost << str2 << '\n';
					str2 = "";
					ist2 >> str2;
					if (str2.empty()) {
						ost << str1 << '\n';
						str1 = "";
						throw f2_eof();
					}
				} while (str2 < str1);
				ost << str1 << '\n';
			}
		}
	}
	catch (f1_eof) {
		str2 = "";
		ist2 >> str2;
		if (!str2.empty()) {
			do {
				ost << str2 << '\n';
				str2 = "";
				ist2 >> str2;
			} while (!str2.empty());
		}
	}
	catch (f2_eof) {
		if (!str1.empty()) {
			ost << str1 << '\n';
			str1 = "";
		}
		ist1 >> str1;
		if (!str1.empty()) {
			do {
				ost << str1 << '\n';
				str1 = "";
				ist1 >> str1;
			} while (!str1.empty());
		}
	}
}
*/

/*
void merge(ifstream &ist1, ifstream &ist2, ofstream &ost) { // v2
	string str1;
	string str2;
	int where = 0;
	bool b = false;

	while (1) {
		if (where != 1) {
			ist1 >> str1;
			if (is_really_eof(ist1)) goto f1_eof;
		}
		if (where != 2) {
			ist2 >> str2;
			if (is_really_eof(ist2)) goto f2_eof;
		}

		if (str1 == str2) {
			where = 0;
			ost << str1 << '\n' << str1 << '\n';
		}
		else if (str1 < str2) {
			where = 1;
			do {
				ost << str1 << '\n';
				ist1 >> str1;
				if (is_really_eof(ist1)) {
					ost << str2 << '\n';
					goto f1_eof;
				}
			} while (str1 < str2);
			ost << str2 << '\n';
		}
		else {
			where = 2;
			do {
				ost << str2 << '\n';
				ist2 >> str2;
				if (is_really_eof(ist2)) {
					ost << str1 << '\n';
					b = true;
					goto f2_eof;
				}
			} while (str2 < str1);
			ost << str1 << '\n';
		}
	}

	f1_eof:
	ist2 >> str2;
	if (!is_really_eof(ist2)) {
		do {
			ost << str2 << '\n';
			ist2 >> str2;
		} while (!is_really_eof(ist2));
	}
	return;

	f2_eof:
	if (!b) ost << str1 << '\n';
	ist1 >> str1;
	if (!is_really_eof(ist1)) {
		do {
			ost << str1 << '\n';
			ist1 >> str1;
		} while (!is_really_eof(ist1));
	}
	return;
}
*/

void merge(ifstream &ist1, ifstream &ist2, ofstream &ost) { // v3
	string str1;
	string str2;
	int where = 0;
	bool b = false;

	while (1) {
		if (where != 1 && !read_word(ist1, str1)) goto f1_eof;
		if (where != 2 && !read_word(ist2, str2)) goto f2_eof;

		if (str1 == str2) {
			where = 0;
			ost << str1 << '\n' << str1 << '\n';
		}
		else if (str1 < str2) {
			where = 1;
			do {
				ost << str1 << '\n';
				if (!read_word(ist1, str1)) {
					ost << str2 << '\n';
					goto f1_eof;
				}
			} while (str1 < str2);
			ost << str2 << '\n';
		}
		else {
			where = 2;
			do {
				ost << str2 << '\n';
				if (!read_word(ist2, str2)) {
					ost << str1 << '\n';
					b = true;
					goto f2_eof;
				}
			} while (str2 < str1);
			ost << str1 << '\n';
		}
	}

	f1_eof:
	read_rest_into(ist2, ost);
	return;

	f2_eof:
	if (!b) ost << str1 << '\n';
	read_rest_into(ist1, ost);
	return;
}

void open_read(const string &fname, ifstream &ist) {
	ist.open(fname);
	if (!ist) throw runtime_error("Could not open " + fname + " for reading.");
	ist.exceptions(ist.exceptions() | ios::badbit);
}

void open_write(const string &fname, ofstream &ost) {
	ost.open(fname);
	if (!ost) throw runtime_error("Could not open " + fname + " for writing.");
	ost.exceptions(ost.exceptions() | ios::badbit);
}

bool read_word(ifstream &ist, string &str) {
	ist >> str;
	int rdstate = ist.rdstate();
	// check if eof has been reached
	if (rdstate & ios::failbit) {
		if (rdstate & ios::eofbit) return false;
		// badbit set but not because it's an eof?
		throw ios::failure("");
	}
	return true;
}

void read_rest_into(ifstream &ist, ofstream &ost) {
	string str;
	if (read_word(ist, str)) {
		do {
			ost << str << '\n';
		} while (read_word(ist, str));
	}
}

/*
inline bool is_really_eof(ifstream &ist) {
	int rdstate = ist.rdstate();
	return (rdstate & ios::eofbit) && (rdstate & ios::failbit);
}
*/
