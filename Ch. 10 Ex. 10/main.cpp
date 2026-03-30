#include <iostream>
#include <iomanip>
#include "token_stream.h"
#include "name_value_table.h"
#include "expression.h"
#include "definition.h"
#include "io_management.h"
#include "myexceptions.h"

using namespace std;

// function declarations
// ----------------------------------------
void get_statement();
void exec_statement(const string& input);

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
IO_Management iom(ts);
// ----------------------------------------

int main() {
	cout << setprecision(10);

	cout << "Welcome to the calculator. Type help at any moment to get help.\n";

	while (cin) get_statement();

	keep_window_open();

	return 0;
}

void get_statement() {
	string input;
	while (prompt(iom.get_istream(), input)) {
		try {
			exec_statement(input);
		}
		catch (Calculator_error &e) {
			print(iom.get_ostream(), e.what());
		}
	}

	// in case we were getting our input from a file, reset input back to cin
	iom.reset_istream();
}

void exec_statement(const string& input) {
	ts.set_input(input);

	if (ts.is_empty()) return;

	const Token& token = ts.get();

	// check whether it's a definition, expression, or IO redirection
	if (token.get_kind() == Token::KEYWORD) {
		switch (token.get_keyword()) {
		case Token::DEF:
			print(iom.get_ostream(), def.define_name());
			break;
		case Token::REDEF:
			print(iom.get_ostream(), def.redefine_name());
			break;
		case Token::FROM:
			iom.set_istream();
			break;
		case Token::TO:
			iom.set_ostream();
			break;
		case Token::HELP:
			print_help();
			break;
		default:
			ts.unget();
			print(iom.get_ostream(), expr.solve());
		}
	}
	else {
		ts.unget();
		print(iom.get_ostream(), expr.solve());
	}
}

istream& prompt(istream& is, string& str) {
	if (&is == &cin) cout << "> ";
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
		"  Use the redef keyword to redefine a non-const name (e.g. redef x=4).\n"
		"  Use the from keyword to get input from a file (e.g. from \"filename.txt\").\n"
		"  Use the to keyword to set output to a file (e.g. to \"filename.txt\").\n"
		"  To reset the output back to the console use to \"console\".";
	print(iom.get_ostream(), str);
}

void keep_window_open() {
	cin.clear();
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
