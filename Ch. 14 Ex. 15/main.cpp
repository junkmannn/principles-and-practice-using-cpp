#include <iostream>
#include <vector>
#include <list>
#include "vector_iterator.h"
#include "list_iterator.h"

using namespace std;

void print(Iterator& it);
void keep_window_open();

int main() {
	vector<double> vec;
	vec.push_back(4.0);
	vec.push_back(89.4);
	vec.push_back(-9.42);
	Vector_iterator vec_it(vec);
	print(vec_it);
	print(vec_it);
	print(vec_it);
	print(vec_it);

	cout << '\n';

	list<double> list;
	list.push_back(4.0);
	list.push_back(89.4);
	list.push_back(-9.42);
	List_iterator list_it(list);
	print(list_it);
	print(list_it);
	print(list_it);
	print(list_it);

	keep_window_open();

	return 0;
}

void print(Iterator& it) {
	double* d = it.next();
	if (d == nullptr) cout << "no value\n";
	else cout << *d << '\n';
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit\n";
	char c;
	cin >> c;
}
