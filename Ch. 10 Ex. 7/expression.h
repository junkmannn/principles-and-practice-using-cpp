#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "token_stream.h"
#include "name_value_table.h"

class Expression {
public:
	Expression(Token_stream& ts, Name_value_table& nvt);

	double solve();

private:
	Token_stream& ts;
	Name_value_table& nvt;

	double expression(char exit = 0);
	double term();
	double primary();
	double solve_parentheses(char close_parenthesis);
	double solve_sqrt();
	double solve_pow();

	void char_expected(char c);
};

#endif
