#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include "Person.h"

using namespace std;

void keep_window_open();

int main() {
	Person p;
	vector<Person> vec_p;
	while (cin >> p) {
		vec_p.push_back(p);
	}

	for (int i = 0, size = vec_p.size(); i < size; ++i) {
		cout << vec_p[i] << '\n';
	}

	keep_window_open();

	return 0;
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit\n";
	char c;
	cin >> c;
}
