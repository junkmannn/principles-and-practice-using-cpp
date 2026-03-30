#ifndef MONEY_H
#define MONEY_H

#include <string>

class Money {
public:
	enum Currency {
		USD, DKK
	};

	Money(int cents, Currency cur = USD);
	Money(int dollars, int cents, Currency cur = USD);
	Money(float amount, Currency cur = USD);
	int get_total_in_cents() const;
private:
	int total_in_cents;
};

int get_dollars(int total_in_cents);
int get_cents(int total_in_cents);
int cur_to_usd(int total_in_cents, Money::Currency cur);
int usd_to_cur(int total_in_cents, Money::Currency cur);
std::string to_string(const Money& m, Money::Currency cur = Money::Currency::USD);
float to_float(const Money& m);
Money operator+(const Money& m1, const Money& m2);
Money operator-(const Money& m1, const Money& m2);
Money operator*(const Money& m1, int i);
Money operator*(int i, const Money& m1);
Money operator/(const Money& m1, int i);
// Money operator/(int i, const Money& m1);
bool operator==(const Money& m1, const Money& m2);
bool operator!=(const Money& m1, const Money& m2);

#endif
