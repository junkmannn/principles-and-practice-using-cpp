#include "money.h"
#include <iostream>

Money::Money(int cents, Money::Currency cur) : total_in_cents(cents), currency(cur) { }

Money::Money(int dollars, int cents, Money::Currency cur) : total_in_cents(dollars * 100 + cents), currency(cur) { }

Money::Money(double amount, Money::Currency cur) : total_in_cents(amount * 100), currency(cur) { }

int Money::get_total_in_cents() const {
	return total_in_cents;
}

Money::Currency Money::get_currency() const {
	return currency;
}

void Money::dump() const {
	std::cout << "Dumping Money...\n";
	std::cout << "Currency: " << currency << ", Total in cents: " << total_in_cents << '\n';
}

double conversion_table(Money::Currency from, Money::Currency to) {
	static double conversions[Money::NUMBER_OF_CURRENCIES][Money::NUMBER_OF_CURRENCIES];
	static bool created = false;
	if (!created) {
		conversions[Money::USD][Money::USD] = 1.00000;
		conversions[Money::USD][Money::EUR] = 0.920180;
		conversions[Money::USD][Money::JPY] = 121.240;
		conversions[Money::USD][Money::GBP] = 0.671276;
		conversions[Money::USD][Money::CHF] = 0.992060;
		conversions[Money::USD][Money::CAD] = 1.39575;
		conversions[Money::USD][Money::DKK] = 6.86366;

		conversions[Money::EUR][Money::USD] = 1 / conversions[Money::USD][Money::EUR];
		conversions[Money::EUR][Money::EUR] = 1.00000;
		conversions[Money::EUR][Money::JPY] = 131.757;
		conversions[Money::EUR][Money::GBP] = 0.729505;
		conversions[Money::EUR][Money::CHF] = 1.07812;
		conversions[Money::EUR][Money::CAD] = 1.51682;
		conversions[Money::EUR][Money::DKK] = 7.45904;

		conversions[Money::JPY][Money::USD] = 1 / conversions[Money::USD][Money::JPY];
		conversions[Money::JPY][Money::EUR] = 1 / conversions[Money::EUR][Money::JPY];
		conversions[Money::JPY][Money::JPY] = 1.00000;
		conversions[Money::JPY][Money::GBP] = 0.00553675;
		conversions[Money::JPY][Money::CHF] = 0.00818261;
		conversions[Money::JPY][Money::CAD] = 0.0115123;
		conversions[Money::JPY][Money::DKK] = 0.0566122;

		conversions[Money::GBP][Money::USD] = 1 / conversions[Money::USD][Money::GBP];
		conversions[Money::GBP][Money::EUR] = 1 / conversions[Money::EUR][Money::GBP];
		conversions[Money::GBP][Money::JPY] = 1 / conversions[Money::JPY][Money::GBP];
		conversions[Money::GBP][Money::GBP] = 1.00000;
		conversions[Money::GBP][Money::CHF] = 1.47787;
		conversions[Money::GBP][Money::CAD] = 2.07925;
		conversions[Money::GBP][Money::DKK] = 10.2248;

		conversions[Money::CHF][Money::USD] = 1 / conversions[Money::USD][Money::CHF];
		conversions[Money::CHF][Money::EUR] = 1 / conversions[Money::EUR][Money::CHF];
		conversions[Money::CHF][Money::JPY] = 1 / conversions[Money::JPY][Money::CHF];
		conversions[Money::CHF][Money::GBP] = 1 / conversions[Money::GBP][Money::CHF];
		conversions[Money::CHF][Money::CHF] = 1.00000;
		conversions[Money::CHF][Money::CAD] = 1.40692;
		conversions[Money::CHF][Money::DKK] = 6.91859;

		conversions[Money::CAD][Money::USD] = 1 / conversions[Money::USD][Money::CAD];
		conversions[Money::CAD][Money::EUR] = 1 / conversions[Money::EUR][Money::CAD];
		conversions[Money::CAD][Money::JPY] = 1 / conversions[Money::JPY][Money::CAD];
		conversions[Money::CAD][Money::GBP] = 1 / conversions[Money::GBP][Money::CAD];
		conversions[Money::CAD][Money::CHF] = 1 / conversions[Money::CHF][Money::CAD];
		conversions[Money::CAD][Money::CAD] = 1.00000;
		conversions[Money::CAD][Money::DKK] = 4.91754;

		conversions[Money::DKK][Money::USD] = 1 / conversions[Money::USD][Money::DKK];
		conversions[Money::DKK][Money::EUR] = 1 / conversions[Money::EUR][Money::DKK];
		conversions[Money::DKK][Money::JPY] = 1 / conversions[Money::JPY][Money::DKK];
		conversions[Money::DKK][Money::GBP] = 1 / conversions[Money::GBP][Money::DKK];
		conversions[Money::DKK][Money::CHF] = 1 / conversions[Money::CHF][Money::DKK];
		conversions[Money::DKK][Money::CAD] = 1 / conversions[Money::CAD][Money::DKK];
		conversions[Money::DKK][Money::DKK] = 1.00000;

		created = true;
	}

	return conversions[from][to];
}