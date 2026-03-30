#include "money.h"
#include "../std_lib_facilities.h"

void test_money();

int main() {
	test_money();

	keep_window_open();

	return 0;
}

void test_money() {
	cout << to_string(Money(100, 0)) << '\n';
	cout << to_string(Money(100, 9)) << '\n';
	cout << to_string(Money(100, 10)) << '\n';
	cout << to_string(Money(100, 99)) << '\n';
	cout << to_string(Money(100, 100)) << '\n';
	cout << to_string(Money(-100, -13)) << '\n';
	cout << to_string(Money(0, -13)) << '\n';

	cout << '\n';

	cout << to_string(Money(100, 03) + Money(53)) << '\n';
	cout << to_string(Money(100, 03) + Money(3, 2)) << '\n';

	cout << '\n';

	cout << to_string(Money(100, 03) - Money(53)) << '\n';
	cout << to_string(Money(100, 03) - Money(3, 2)) << '\n';
	cout << to_string(Money(100, 03) - Money(-3, -2)) << '\n';

	cout << '\n';

	cout << (Money(1, 0) == Money(1, 0)) << '\n';
	cout << (Money(1, 0) == Money(1, 1)) << '\n';
	cout << (Money(1, 0) != Money(1, 0)) << '\n';
	cout << (Money(1, 0) != Money(1, 1)) << '\n';

	cout << '\n';

	cout << to_string(Money(100.00f)) << '\n';
	cout << to_string(Money(100.09f)) << '\n';
	cout << to_string(Money(100.10f)) << '\n';
	cout << to_string(Money(100.99f)) << '\n';
	cout << to_string(Money(100.999f)) << '\n';
	cout << to_string(Money(-100.99f)) << '\n';
	cout << to_string(Money(100.005f)) << '\n';
	cout << to_string(Money(100.004f)) << '\n';
	cout << to_string(Money(16506.005f)) << '\n';

	cout << '\n';

	cout << to_float(Money(100.115f)) << '\n';
	cout << to_float(Money(-100.115f)) << '\n';
	cout << to_float(Money(1205.115f)) << '\n';
	cout << to_float(Money(16506.005f)) << '\n';

	cout << '\n';

	cout << to_string(Money(100, 0) / 2) << '\n';
	cout << to_string(Money(103, 25) / 2) << '\n';
	// cout << to_string(2 / Money(100, 0)) << '\n';
	cout << to_string(Money(100, 0) * 2) << '\n';
	cout << to_string(Money(103, 25) * 2) << '\n';
	cout << to_string(2 * Money(100, 0)) << '\n';
	cout << to_string(2 * Money(103, 25)) << '\n';

	cout << '\n';
}