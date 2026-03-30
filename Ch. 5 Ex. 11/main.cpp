#include "../std_lib_facilities.h"

int main() {
	int n = 1;
	int m = 2;

	while (n<m) {
			cout << n << '\n';
			int x = n+m;
			n = m;	// drop the lowest number
			m = x;	// add a new highest number
	}

	cout << "the largest Fibonacci number that fits in an int is " << n << '\n';

	keep_window_open("~");

	return 0;
}
