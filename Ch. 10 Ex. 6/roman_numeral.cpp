#include "roman_numeral.h"

using namespace std;

Invalid_roman_numeral::Invalid_roman_numeral(const std::string& what_arg) :
	std::runtime_error(what_arg) { }

Invalid_roman_numeral::Invalid_roman_numeral(const char* what_arg) :
	std::runtime_error(what_arg) { }

Roman_numeral::Roman_numeral() : value(0), numeral() { }

Roman_numeral::Roman_numeral(const std::string& numeral) :
	value(roman_value_of(numeral)), numeral(numeral) {
	if (this->value == 0) throw Invalid_roman_numeral("invalid roman numeral");
}

int Roman_numeral::get_value() const { return value; }

const std::string& Roman_numeral::get_numeral() const { return numeral; }

int roman_value_of(const std::string& roman_numeral) {
	int int_val = 0; // decimal value of roman numerals
	bool is_negative = false;

	int cur_sym_val = 0; // current symbol value
	int prev_sym_val = 1001; // previous symbol value
	int prev_prev_sym_val = 1001; // before previous symbol value

	int repeated_sym_count = 0; // same symbol in a row counter (starts at 0)


	size_t i = 0;
	size_t size = roman_numeral.size();
	if (size > 0) {
		if (roman_numeral[0] == '-') {
			i = 1;
			is_negative = true;
		}
	}
	else {
		return 0;
	}

	for (; i < size; ++i) {
		cur_sym_val = roman_value_of(roman_numeral[i]);

		// check if symbol is valid
		if (cur_sym_val == 0) return 0;

		if (cur_sym_val == prev_sym_val) {
			// never repeat V, L and D
			if (cur_sym_val == 5 || cur_sym_val == 50 || cur_sym_val == 500)
				return 0;

			// i.e. IXX is not allowed
			if (prev_prev_sym_val < cur_sym_val) return 0;

			++repeated_sym_count;
			// can't have more than 3 of the same symbol in a row
			// note that repeated_sym_count starts at 0
			if (repeated_sym_count == 3) return 0;

			int_val += cur_sym_val;
		}
		else if (cur_sym_val < prev_sym_val) {
			// i.e. IXI or IXV is not allowed
			if (cur_sym_val >= prev_prev_sym_val) return 0;

			repeated_sym_count = 0;

			int_val += cur_sym_val;
		}
		else {
			// can only substract powers of 10 (I, X, C)
			// can't subtract a number from one that is more than 10 times greater
			if ((prev_sym_val != 1 && prev_sym_val != 10 && prev_sym_val != 100) ||
				prev_sym_val * 10 < cur_sym_val) return 0;

			// i.e. IXL or IXC is not allowed
			if (cur_sym_val > prev_prev_sym_val) return 0;

			repeated_sym_count = 0;

			int_val -= prev_sym_val * 2;
			int_val += cur_sym_val;
		}

		prev_prev_sym_val = prev_sym_val;
		prev_sym_val = cur_sym_val;
	}


	return (is_negative ? -int_val : int_val);
}

int roman_value_of(char roman_symbol) {
	switch (roman_symbol) {
	case 'I':
		return 1;
	case 'V':
		return 5;
	case 'X':
		return 10;
	case 'L':
		return 50;
	case 'C':
		return 100;
	case 'D':
		return 500;
	case 'M':
		return 1000;
	default:
		return 0; // not a valid symbol
	}
}

string decimal_to_roman(int decimal) {
	struct Symbol_value {
		Symbol_value(char symbol, int value, bool repeatable) :
		symbol(symbol), value(value), repeatable(repeatable) { }
		char symbol;
		int value;
		bool repeatable;
	};
	static Symbol_value svt[] = {
		Symbol_value('I', 1, true), Symbol_value('V', 5, false),
		Symbol_value('X', 10, true), Symbol_value('L', 50, false),
		Symbol_value('C', 100, true), Symbol_value('D', 500, false),
		Symbol_value('M', 1000, true)
	};

	string roman;
	if (decimal < 0) {
		roman += '-';
		decimal = -decimal;
	}

	for (int i = 6; i >= 0; --i) {
		Symbol_value& sv = svt[i];

		int consecutive = decimal / sv.value;
		roman += string(consecutive, sv.symbol);
		decimal -= consecutive * sv.value;

		if (decimal == 0) break;

		Symbol_value& sv2 = svt[i - (sv.repeatable ? 2 : 1)];
		int val = sv.value - sv2.value;
		if (decimal >= val) {
			roman += sv2.symbol;
			roman += sv.symbol;
			decimal -= val;
		}
	}

	return roman;
}

std::ostream& operator<<(std::ostream& os, const Roman_numeral& rn) {
	return os << rn.get_value();
}

std::istream& operator>>(std::istream& is, Roman_numeral& rn) {
	string numeral;

	char symbol = 0;
	while (is.get(symbol)) {
		int value = roman_value_of(symbol);
		if (value != 0) numeral += symbol;
		else break;
	}

	if (is.eof())
		is.clear(is.rdstate() & ~ios_base::failbit);
	else
		is.unget();

	try {
		rn = Roman_numeral(numeral);
	}
	catch (Invalid_roman_numeral &e) {
		is.clear(is.rdstate() | ios_base::failbit);
	}

	return is;
}
