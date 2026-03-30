#include "Name_pairs.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void Name_pairs::read_names() {
	cout << "Enter a series of names\n";
	while (1) {
		string s;
		cin >> s;
		if (!cin.good()) {
			cin.clear();
			return;
		}
		name.push_back(s);
		age.push_back(Name_pairs::UNDEFINED_AGE);
	}
}

void Name_pairs::read_ages() {
	cout << "Enter an age for the following names\n";
	for (int i = 0, size = name.size(); i < size; ++i) {
		cout << name[i] << " = ";
		cin >> age[i];
	}
}

void Name_pairs::sort() {
	int size = name.size();
	vector<string> name_unsorted = name;
	std::sort(name.begin(), name.end());
	vector<double> age_unsorted = age;

	for (int i = 0; i < size; ++i) {
		for (int i2 = 0; i2 < size; ++i2) {
			if (name[i] == name_unsorted[i2]) {
				age[i] = age_unsorted[i2];
				break;
			}
		}
	}
}

vector<string> Name_pairs::get_name() const {
	return name;
}

vector<double> Name_pairs::get_age() const {
	return age;
}

bool operator==(const Name_pairs& a, const Name_pairs& b) {
	vector<string> a_name = a.get_name();
	vector<string> b_name = b.get_name();
	int size = a_name.size();
	if (size != b_name.size()) return false;
	vector<double> a_age = a.get_age();
	vector<double> b_age = b.get_age();
	for (int i = 0; i < size; ++i) {
		if (a_name[i] != b_name[i] || a_age[i] != b_age[i]) return false;
	}
	return true;
}

bool operator!=(const Name_pairs& a, const Name_pairs& b) {
	return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Name_pairs& a) {
	vector<string> name = a.get_name();
	vector<double> age = a.get_age();
	int size = name.size();
	for (int i = 0; i < size; ++i) {
		os << name[i] << ", " << age[i] << "\n";
	}
	return os;
}
