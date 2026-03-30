#include "../std_lib_facilities.h"

int main() {
	cout << "Enter a set of name-and-value pairs (i.e. Joe 17, Barbara 22, etc.).\nEnter the pair NoName and 0 to exit.\n";

	string name = "";
	int score = 0;
	vector<string> names;
	vector<int> scores;
	while (cin >> name >> score) {
		if (name == "NoName" && score == 0) break;

		if (find(names.begin(), names.end(), name) == names.end()) {
			names.push_back(name);
			scores.push_back(score);
		}
		else {
			cout << "error: same name entered twice\n";
			break;
		}
	}

	if (names.size() > 0) {
		cout << "Name\tScore\n";
		for (int i = 0; i < names.size(); ++i) {
			cout << names[i] << '\t' << scores[i] << '\n';
		}
	}

	keep_window_open();

	return 0;
}