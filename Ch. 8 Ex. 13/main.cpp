#include "../std_lib_facilities.h"

void print_until_ss(const vector<string>& v, const string& quit) {
	int occ = 0;
	for (int i = 0, size = v.size(); i < size; ++i) {
		if (v[i] == quit) {
			++occ;
			if (occ == 2) return;
		}
		cout << v[i] << "\n";
	}
}


void print_until_s(const vector<string>& v, const string& quit) {
	for (int i = 0, size = v.size(); i < size; ++i) {
		if (v[i] == quit) return;
		cout << v[i] << "\n";
	}
}

int main() {
	vector<string> v = {"hey", "troll", "noob", "lel", "toaster", "junk", "tube", "dong", "kkk", "k", "fail", "dong"};
	string quit = "dong";

	print_until_ss(v, quit);

	keep_window_open();

	return 0;
}