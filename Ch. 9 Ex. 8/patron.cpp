#include <string>
#include "patron.h"

using namespace std;

Patron::Patron(string p_username, string p_card_number):
username(p_username), card_number(p_card_number) { }

string Patron::get_username() const {
	return username;
}

string Patron::get_card_number() const {
	return card_number;
}

double Patron::get_owed_fees() const {
	return owed_fees;
}

void Patron::set_owed_fees(double d) {
	owed_fees = d;
}

bool owes_fees(const Patron& p) {
	return (p.get_owed_fees() > 0);
}