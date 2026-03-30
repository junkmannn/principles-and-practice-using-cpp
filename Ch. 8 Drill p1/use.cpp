#include "my.h"
#include <iostream>

using namespace std;

int foo = 7;

int main() {
	print_foo();
	print(99);

	int x = 7;
	int y = 9;
	swap_v(x, y);
	cout << "x=" << x << " y=" << y << '\n';
	swap_r(x, y);
	cout << "x=" << x << " y=" << y << '\n';

	swap_v(7, 9);
	// swap_r(7, 9); // doesn't work

	const int cx = 7;
	const int cy = 9;
	swap_v(cx, cy);
	cout << "cx=" << cx << " cy=" << cy << '\n';
	// swap_r(cx, cy); // doesn't work

	swap_v(7.7, 9.9);
	// swap_r(7.7, 9.9); // doesn't work

	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx, dy);
	cout << "dx=" << dx << " dy=" << dy << '\n';
	// swap_r(dx, dy); // doesn't work

	char c;
	cin >> c;
}