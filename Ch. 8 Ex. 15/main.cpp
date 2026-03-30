#include "../std_lib_facilities.h"

void f(const int i) {
	cout << i << "\n";
}

int main() {
	int i = 3;
	f(i);

	keep_window_open();

	return 0;
}