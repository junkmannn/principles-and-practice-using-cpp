#include "monies.h"
#include <iostream>

Monies::Monies() { }

Monies::Monies(Money& m) {
	plus(m);
}

void Monies::plus(Money& m) {
	monies[m.get_currency()] += m.get_total_in_cents();
}

void Monies::minus(Money& m) {
	monies[m.get_currency()] -= m.get_total_in_cents();
}

Money Monies::convert_all(Money::Currency to) const {
	double total_in_cents = 0;
	for (auto& money : monies) {
		// std::cout << x.first << ": " << x.second << '\n';
		total_in_cents += money.second * conversion_table(money.first, to);
	}

	return Money((int)total_in_cents, to);
}

void Monies::dump() const {
	std::cout << "Dumping Monies...\n";
	for (auto& x : monies) {
		std::cout << "Currency: " << x.first << ", Total in cents: " << x.second << '\n';
	}
}