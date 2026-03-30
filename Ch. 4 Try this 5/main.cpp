#include "../std_lib_facilities.h"

int square(int x) {
	int result = 0;
	for (int i = 0; i < x; ++i) result += x;
	return result;
}

int main() {
	int i = 0;
	while (i < 100) {
		cout << i << '\t' << square(i) << '\n';
		++i;
	}

	keep_window_open();

	return 0;
}