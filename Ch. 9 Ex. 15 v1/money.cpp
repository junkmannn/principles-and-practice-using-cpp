#include "money.h"

using namespace std;

Money::Money(int cents, Money::Currency cur) : total_in_cents(cur_to_usd(cents, cur)) { }

Money::Money(int dollars, int cents, Money::Currency cur) : total_in_cents(cur_to_usd(dollars * 100 + cents, cur)) { }

Money::Money(float amount, Money::Currency cur) : total_in_cents(cur_to_usd(round(amount * 100), cur)) { }

int Money::get_total_in_cents() const {
	return total_in_cents;
}

int get_dollars(int total_in_cents) {
	return total_in_cents / 100;
}

int get_cents(int total_in_cents) {
	return total_in_cents % 100;
}

int cur_to_usd(int total_in_cents, Money::Currency cur) {
	switch (cur) {
	case Money::Currency::DKK:
		total_in_cents *= 0.145695;
		break;
	}
	return total_in_cents;
}

int usd_to_cur(int total_in_cents, Money::Currency cur) {
	switch (cur) {
	case Money::Currency::DKK:
		total_in_cents *= 6.86366;
		break;
	}
	return total_in_cents;
}

string to_string(const Money& m, Money::Currency cur) {
	string s;
	int total_in_cents = usd_to_cur(m.get_total_in_cents(), cur);
	if (total_in_cents < 0) s += '-';
	int dollars = abs(get_dollars(total_in_cents));
	int cents = abs(get_cents(total_in_cents));
	s += to_string(dollars);
	if (cents < 10) s += ".0";
	else s += '.';
	s += to_string(cents);
	return s;
}

float to_float(const Money& m) {
	return m.get_total_in_cents() / 100.0f;
}

Money operator+(const Money& m1, const Money& m2) {
	return Money(m1.get_total_in_cents() + m2.get_total_in_cents());
}

Money operator-(const Money& m1, const Money& m2) {
	return Money(m1.get_total_in_cents() - m2.get_total_in_cents());
}

Money operator*(const Money& m1, int i) {
	return Money(m1.get_total_in_cents() * i);
}

Money operator*(int i, const Money& m1) {
	return Money(m1.get_total_in_cents() * i);
}

Money operator/(const Money& m1, int i) {
	return Money(m1.get_total_in_cents() / i);
}

bool operator==(const Money& m1, const Money& m2) {
	return m1.get_total_in_cents() == m2.get_total_in_cents();
}

bool operator!=(const Money& m1, const Money& m2) {
	return m1.get_total_in_cents() != m2.get_total_in_cents();
}