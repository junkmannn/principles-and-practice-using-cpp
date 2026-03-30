#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "token_stream.h"
#include "name_value_table.h"

class Expression {
public:
	// Need the token stream to read the expression statement
	// Need the name value table to solve the names
	Expression(Token_stream& ts, Name_value_table& nvt);

	// Solve the mathematical expression
	double solve();

private:
	Token_stream& ts;
	Name_value_table& nvt;

	// Get expression value (deals with + and -)
	double expression(char exit = 0);
	// Get term value (deals with * and /)
	double term();
	// Get primary value (deals with unary operators (e.g. -, sqrt, pow), plain numbers and names).
	double primary();
	// Solve (expression) and {expression}
	double solve_parentheses(char close_parenthesis);
	// Solve sqrt(x)
	double solve_sqrt();
	// Solve pow(base,exp)
	double solve_pow();

	// Throw Calculator_error with the error message
	// "c expected" where c is the given character
	void char_expected(char c);
};

#endif
