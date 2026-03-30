#include "money.h"

using namespace std;

Money::Money(int cents) : total_in_cents(cents) { }

Money::Money(int dollars, int cents) : total_in_cents(dollars * 100 + cents) { }

Money::Money(float amount) : total_in_cents(round(amount * 100)) { }

int Money::get_total_in_cents() const {
	return total_in_cents;
}

int Money::get_dollars() const {
	return total_in_cents / 100;
}

int Money::get_cents() const {
	return total_in_cents % 100;
}

string to_string(const Money& m) {
	string s;
	if (m.get_total_in_cents() < 0) s += '-';
	int dollars = abs(m.get_dollars());
	int cents = abs(m.get_cents());
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