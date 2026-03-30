#ifndef TOKEN_H
#define TOKEN_H

#include <string>

class Token {
public:
	enum Kind { SYNTAX, NAME, KEYWORD, NUMBER, END };
	enum Keyword { DEF, REDEF, VAR, CONST, SQRT, POW, HELP, NOT_A_KEYWORD };

	Token();                        // eof token
	Token(char syntax);             // standard math syntax: e.g. +, -, *, /
	Token(const std::string& name); // named variable or constant: e.g. x, pi, e
	Token(Keyword keyword);         // keyword: e.g. def, redef, pow, sqrt
	Token(double number);           // plain number: e.g. 57, 1064, -4

	Kind get_kind() const;
	char get_syntax() const;
	const std::string& get_name() const;
	Keyword get_keyword() const;
	double get_number() const;

private:
	Kind kind;
	char syntax;      // when the token is syntax
	std::string name; // when the token is a name
	Keyword keyword;  // when the token is a keyword
	double number;    // when the token is a number
};

#endif
