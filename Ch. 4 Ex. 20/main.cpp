#include "../std_lib_facilities.h"

vector<string*> names_with_score(int score, vector<string> &names, vector<int> &scores);
int name_exists(string &name, vector<string> &names);

int main() {
	cout << "Enter a set of name-and-value pairs (i.e. Joe 17, Barbara 22, etc.).\n";

	string name = "";
	int score = 0;
	vector<string> names;
	vector<int> scores;
	bool add_score = false;

	while (1) {
		// try to read the input as an int
		cin >> score;
		if (cin.good()) {
			// add name-and-value pair
			if (add_score) {
				add_score = false;
				names.push_back(name);
				scores.push_back(score);
				cout << name << ' ' << score << " added\n";
			}
			// show all the names with that score
			else {
				vector<string*> names_found = names_with_score(score, names, scores);
				if (names_found.size() > 0) {
					cout << "Names with " << score << " score:\n";
					int i = 0;
					do {
						cout << *names_found[i] << '\n';
						++i;
					}
					while (i < names_found.size());
				}
				else {
					cout << "score not found\n";
				}
			}
		}
		else {
			// eof input, terminate input
			if (cin.eof()) break;

			cin.clear();

			// user didn't input the score correctly when
			// trying to add a new name-and-value pair
			/*
			if (add_score) {
				add_score = false;
				cout << "invalid score\n";
				continue;
			}
			*/

			// try to read input as a string this time
			cin >> name;
			if (cin.good()) {
				// does this name already exists?
				int i = name_exists(name, names);
				// yes: show what score is associated to this name
				if (i != -1) {
					cout << name << ' ' << scores[i] << '\n';
				}
				// no: if next input we read is an int,
				// add the name-and-value pair to the set
				else {
					add_score = true;
				}
			}
			// failed to read input into a string...
			// eof input most likely thus terminate input
			else {
				break;
			}
		}
	}

	keep_window_open();

	return 0;
}

vector<string*> names_with_score(int score, vector<string> &names, vector<int> &scores) {
	vector<string*> result;
	for (int i = 0; i < scores.size(); ++i) {
		if (score == scores[i]) result.push_back(&names[i]);
	}
	return result;
}

int name_exists(string &name, vector<string> &names) {
	for (int i = 0; i < names.size(); ++i) {
		if (name == names[i]) return i;
	}
	return -1;
}