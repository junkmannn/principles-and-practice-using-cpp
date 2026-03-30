#include <iostream>
#include <iomanip>
#include "token_stream.h"
#include "name_value_table.h"
#include "expression.h"
#include "definition.h"
#include "roman_numeral.h"
#include "myexceptions.h"

using namespace std;

// function declarations
// ----------------------------------------
void statement(const string& input);

istream& prompt(istream& is, string& str);
void print(ostream& os, const string& str);
void print(ostream& os, double d);
void print_help();

void keep_window_open();
// ----------------------------------------

// global variables
// ----------------------------------------
Token_stream ts;
Name_value_table nvt;
Expression expr(ts, nvt);
Definition def(ts, nvt, expr);
// ----------------------------------------

int main() {
	cout << setprecision(10);

	cout << "Welcome to the calculator. Type help at any moment to get help.\n";

	string input;
	while (prompt(cin, input)) {
		try {
			statement(input);
		}
		catch (Syntax_error &e) {
			print(cerr, e.what());
		}
	}

	keep_window_open();

	return 0;
}

void statement(const string& input) {
	ts.set_input(input);
	const Token& token = ts.get();

	double result = 0.0;

	// check whether it's a definition or an expression
	if (token.get_kind() == Token::KEYWORD) {
		switch (token.get_keyword()) {
		case Token::DEF:
			result = def.define_name();
			break;
		case Token::REDEF:
			result = def.redefine_name();
			break;
		case Token::HELP:
			print_help();
			return; // <---------- not a break
		default:
			ts.unget();
			result = expr.solve();
		}
	}
	else {
		ts.unget();
		result = expr.solve();
	}

	print(cout, decimal_to_roman((int)result));
}

istream& prompt(istream& is, string& str) {
	cout << "> ";
	return getline(is, str);
}

void print(ostream& os, const string& str) {
	os << "= " << str << '\n';
}

void print(ostream& os, double d) {
	os << "= " << d << '\n';
}

void print_help() {
	static string str =
		"Supported operators: (), {}, +, -, *, /, !.\n"
		"  Supported functions: sqrt(x), pow(base,exponent).\n"
		"  Use the def keyword to define a name (e.g. def x=3, def const phi=1.618).\n"
		"  Use the redef keyword to redefine a non-const name (e.g. redef x=4).";
	print(cout, str);
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
