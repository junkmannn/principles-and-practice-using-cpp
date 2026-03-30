#include "../std_lib_facilities.h"

int area(int length, int width) {
	if (length <= 0 || width <= 0) error("area() pre-condition");
	int a = length*width;
	if (a <= 0) error("area() post-condition");
	return a;
}

int main() {
	cout << "Area = " << area(2000000000, 2) << '\n';

	keep_window_open();

	return 0;
}
