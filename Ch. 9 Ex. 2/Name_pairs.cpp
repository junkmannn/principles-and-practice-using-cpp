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

void Name_pairs::print() {
	for (int i = 0, size = name.size(); i < size; ++i) {
		cout << name[i] << ", " << age[i] << "\n";
	}
}

void Name_pairs::sort() {
	int size = name.size();
	vector<string> name_unsorted = name;
	std::sort(name.begin(), name.end());
	// vector<double> age_sorted(size);
	vector<double> age_unsorted = age;

	for (int i = 0; i < size; ++i) {
		for (int i2 = 0; i2 < size; ++i2) {
			if (name[i] == name_unsorted[i2]) {
				// age_sorted[i] = age[i2];
				age[i] = age_unsorted[i2];
				break;
			}
		}
	}

	// age = age_sorted;
}