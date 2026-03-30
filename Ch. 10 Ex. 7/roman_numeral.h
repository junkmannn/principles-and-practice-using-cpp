#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

#include <string>

class Invalid_roman_numeral : public std::runtime_error {
public:
	Invalid_roman_numeral(const std::string& what_arg);
	Invalid_roman_numeral(const char* what_arg);
};

class Roman_numeral {
public:
	Roman_numeral();
	Roman_numeral(const std::string& numeral);

	int get_value() const;
	const std::string& get_numeral() const;

private:
	int value;
	std::string numeral;
};

int roman_value_of(const std::string& roman_numeral);
int roman_value_of(char roman_symbol);

std::string decimal_to_roman(int decimal);

std::ostream& operator<<(std::ostream& os, const Roman_numeral& rn);
std::istream& operator>>(std::istream& is, Roman_numeral& rn);

#endif
