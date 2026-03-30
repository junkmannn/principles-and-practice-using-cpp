#include "../std_lib_facilities.h"

class Name_value {
public:
	string name;
	int value;
	Name_value(string pName, int pValue): name(pName), value(pValue) {}
};

bool is_unique_name(vector<Name_value> &vec, string name) {
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i].name == name) return false;
	}
	return true;
}

int main() {
	cout << "Enter a set of name-and-value pairs (i.e. Joe 17, Barbara 22, etc.).\nEnter the pair NoName and 0 to exit.\n";

	string name = "";
	int score = 0;
	vector<Name_value> name_score_vec;
	while (cin >> name >> score) {
		if (name == "NoName" && score == 0) break;

		if (is_unique_name(name_score_vec, name)) {
			name_score_vec.push_back(Name_value(name, score));
		}
		else {
			cout << "error: same name entered twice\n";
			break;
		}
	}

	if (name_score_vec.size() > 0) {
		cout << "Name\tScore\n";
		for (int i = 0; i < name_score_vec.size(); ++i) {
			cout << name_score_vec[i].name << '\t' << name_score_vec[i].value << '\n';
		}
	}

	keep_window_open();

	return 0;
}