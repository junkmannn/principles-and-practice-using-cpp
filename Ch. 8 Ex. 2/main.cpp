#include "../std_lib_facilities.h"

void print(const vector<int>& v, const string& lbl) {
	cout << lbl << '\n';
	for (int i = 0, size = v.size(); i < size; ++i) {
		cout << v[i] << '\n';
	}
}

int main() {
	vector<int> v;
	v.push_back(1337);
	v.push_back(33);
	v.push_back(7);
	v.push_back(801);
	v.push_back(13);

	print(v, "Content of the vector:");

	keep_window_open();

	return 0;
}