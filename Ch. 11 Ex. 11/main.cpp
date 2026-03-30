#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

void reverse_bytes(ifstream& ist, ofstream& ost);
void keep_window_open();

int main() {
	string filename = "notreversed.txt";
	ifstream ist(filename, ios_base::in | ios_base::binary | ios_base::ate);
	if (!ist) {
		cerr << "Can't open input file " << filename << ".\n";
		keep_window_open();
		return 0;
	}

	filename = "reversed.txt";
	ofstream ost(filename, ios_base::out | ios_base::binary);
	if (!ost) {
		cerr << "Can't open output file " << filename << ".\n";
		keep_window_open();
		return 0;
	}

	reverse_bytes(ist, ost);

	keep_window_open();

	return 0;
}

void reverse_bytes(ifstream& ist, ofstream& ost) {
	int buf_sz = 8192;
	char* buf = new char[buf_sz];

	int cur_pos = ist.tellg(); // cursor position
	cur_pos -= buf_sz;

	while (cur_pos >= 0) {
		ist.seekg(cur_pos);
		ist.read(buf, buf_sz);
		reverse(buf, buf + buf_sz);
		ost.write(buf, buf_sz);
		cur_pos -= buf_sz;
	}

	cur_pos += buf_sz;
	ist.seekg(0, ios_base::beg);
	ist.read(buf, cur_pos);
	reverse(buf, buf + cur_pos);
	ost.write(buf, cur_pos);

	delete[] buf;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}