#ifndef MONIES_H
#define MONIES_H

#include <unordered_map>
#include "money.h"

class Monies {
public:
	Monies();
	Monies(Money& m);
	void plus(Money& m);
	void minus(Money& m);
	Money convert_all(Money::Currency to) const;
	void dump() const; // debug only
private:
	std::unordered_map<Money::Currency, int> monies;
};

#endif
