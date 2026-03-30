#include "../std_lib_facilities.h"

int main() {
	int i = 97;
	while (i < 123) {
		cout << char(i) << '\t' << i << '\n';
		++i;
	}

	keep_window_open();

	return 0;
}