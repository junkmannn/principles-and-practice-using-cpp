#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
public:
	enum Kind { SYNTAX, NAME, ARG, KEYWORD, NUMBER, END };
	enum Keyword { DEF, REDEF, VAR, CONST, SQRT, POW, HELP, FROM, TO, NOT_A_KEYWORD };

	// eof token
	Token();
	// standard math syntax: e.g. +, -, *, /
	Token(char syntax);
	// 1. named variable or constant (e.g. x, pi, e).
	// 2. argument (e.g. file.txt).
	Token(const std::string& name_arg, bool is_arg);
	// keyword: e.g. def, redef, pow, sqrt
	Token(Keyword keyword);
	// plain number: e.g. 57, 1064, -4
	Token(double number);

	Kind get_kind() const;
	char get_syntax() const;
	const std::string& get_name() const;
	const std::string& get_argument() const;
	Keyword get_keyword() const;
	double get_number() const;

private:
	Kind kind;
	char syntax;          // when the token is syntax
	std::string name_arg; // when the token is a name or an argument
	Keyword keyword;      // when the token is a keyword
	double number;        // when the token is a number
};

#endif
