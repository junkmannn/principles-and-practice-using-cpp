#ifndef PATRON_H
#define PATRON_H

#include <string>

class Patron {

public:
	Patron(std::string p_username, std::string p_card_number);

	std::string get_username() const;
	std::string get_card_number() const;
	double get_owed_fees() const;

	void set_owed_fees(double d);

private:
	std::string username;
	std::string card_number;
	double owed_fees;

};

bool owes_fees(const Patron& p);

#endif
