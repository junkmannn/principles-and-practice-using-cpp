#ifndef MONEY_H
#define MONEY_H

class Money {
public:
	static const int NUMBER_OF_CURRENCIES = 7;
	enum Currency {
		USD, EUR, JPY, GBP, CHF, CAD, DKK
	};
	Money(int cents, Currency cur = USD);
	Money(int dollars, int cents, Currency cur = USD);
	Money(double amount, Currency cur = USD);
	int get_total_in_cents() const;
	Currency get_currency() const;
	void dump() const; // debug only
private:
	int total_in_cents;
	Currency currency;
};

double conversion_table(Money::Currency from, Money::Currency to);

#endif
