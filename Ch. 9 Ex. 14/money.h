#ifndef MONEY_H
#define MONEY_H

#include <string>

class Money {
public:
	Money(int cents);
	Money(int dollars, int cents);
	Money(float amount);
	int get_total_in_cents() const;
	int get_dollars() const;
	int get_cents() const;
private:
	int total_in_cents;
};

std::string to_string(const Money& m);
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
