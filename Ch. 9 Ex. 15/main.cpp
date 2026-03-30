#include "monies.h"
#include <iostream>

void test_monies();

int main() {
	test_monies();

	char c;
	std::cin >> c;

	return 0;
}

void test_monies() {
	Monies m;

	m.plus(Money(27, 45, Money::USD));
	m.plus(Money(59, 22, Money::EUR));
	m.plus(Money(5, 84, Money::JPY));
	m.plus(Money(6, 00, Money::GBP));
	m.plus(Money(103, 75, Money::CHF));
	m.plus(Money(22, 99, Money::CAD));
	m.plus(Money(33, 06, Money::DKK));
	m.dump();
	m.convert_all(Money::USD).dump();
}
