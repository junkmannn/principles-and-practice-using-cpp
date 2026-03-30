#include "expression.h"
#include "myexceptions.h"

using namespace std;

Expression::Expression(Token_stream& ts, Name_value_table& nvt) : ts(ts), nvt(nvt) { }

double Expression::solve() {
	return expression();
}

double Expression::expression(char exit) {
	double expression = term();
	while (true) {
		const Token& token = ts.get();
		switch (token.get_syntax()) {
		case '+':
			expression += term();
			break;
		case '-':
			expression -= term();
			break;
		default:
			if (exit == 0) {
				if (token.get_kind() != Token::END) throw Calculator_error("unexpected token");
			}
			else {
				if (token.get_kind() == Token::END) char_expected(exit); // throws Calculator_error
				else if (token.get_syntax() != exit) throw Calculator_error("unexpected token");
			}

			// ts.unget();

			return expression;
		}
	}
}

double Expression::term() {
	double term = primary();
	while (true) {
		const Token& token = ts.get();
		switch (token.get_syntax()) {
		case '*':
		{
			term *= primary();
			break;
		}
		case '/':
		{
			double x = primary();
			if (x == 0) throw Calculator_error("divide by zero");
			term /= x;
			break;
		}
		default:
			ts.unget();
			return term;
		}
	}
}

double Expression::primary() {
	const Token& token = ts.get();

	switch (token.get_kind()) {
	case Token::SYNTAX:
	{
		switch (token.get_syntax()) {
		case '(': return solve_parentheses(')');
		case '{': return solve_parentheses('}');
		case '-': return -primary();
		}
		break;
	}
	case Token::KEYWORD:
	{
		switch (token.get_keyword()) {
		case Token::SQRT: return solve_sqrt();
		case Token::POW:  return solve_pow();
		}
		break;
	}
	case Token::NAME:
	{
		const string& name = token.get_name();
		Name_value* name_value = nullptr;
		if (!nvt.get(name, name_value)) throw Calculator_error(name + " undefined");
		return name_value->get_value();
	}
	case Token::NUMBER:
	{
		return token.get_number();
	}
	}

	throw Calculator_error("primary expected");
}

double Expression::solve_parentheses(char close_parenthesis) {
	return expression(close_parenthesis);
}

double Expression::solve_sqrt() {
	if (ts.get().get_syntax() != '(') throw Calculator_error("( expected");

	double x = expression(')');
	if (x < 0) throw Calculator_error("square root of a negative number");

	return sqrt(x);
}

double Expression::solve_pow() {
	if (ts.get().get_syntax() != '(') throw Calculator_error("( expected");

	double base = expression(',');
	double exponent = expression(')');

	// TODO: deal with error flags (http://www.cplusplus.com/reference/cmath/pow/)
	double result = pow(base, exponent);

	return result;
}

void Expression::char_expected(char c) {
	string msg = "x expected";
	msg[0] = c;
	throw Calculator_error(msg);
}
