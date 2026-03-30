#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Num_occur {
	Num_occur(int num) : number(num), occurrences(1) { };
	int number;
	unsigned int occurrences;
};

vector<Num_occur> count_num_occur(ifstream& ist);
void keep_window_open();

int main() {
	string filename = "filetoanalyse.txt";
	ifstream ist(filename);
	if (!ist) {
		cerr << "Can't open input file " << filename << ".\n";
		keep_window_open();
		return 0;
	}

	vector<Num_occur> v = count_num_occur(ist);
	for (int i = 0, size = v.size(); i < size; ++i) {
		Num_occur& nc = v[i];
		cout << setw(5) << nc.number;
		if (nc.occurrences > 1) cout << setw(5) << nc.occurrences;
		cout << '\n';
	}

	keep_window_open();

	return 0;
}

vector<Num_occur> count_num_occur(ifstream& ist) {
	vector<Num_occur> num_occur_vec;

	vector<int> numbers; // all integers in file go here

	string s;
	while (ist >> s) {
		try {
			int i = stoi(s);
			numbers.push_back(i);
		}
		catch (...) {
			// not an integer; ignore
		}
	}

	sort(numbers.begin(), numbers.end());

	int size = numbers.size();
	if (size > 0) {
		int num_occur_vec_idx = 0;
		num_occur_vec.push_back(Num_occur(numbers[0]));

		for (int numbers_idx = 1; numbers_idx < size; ++numbers_idx) {
			int number = numbers[numbers_idx]; // current number
			Num_occur& nc = num_occur_vec[num_occur_vec_idx];

			if (number == nc.number /* previous number */) {
				++nc.occurrences;
			}
			else {
				num_occur_vec.push_back(Num_occur(number));
				++num_occur_vec_idx;
			}
		}
	}

	return num_occur_vec;
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
