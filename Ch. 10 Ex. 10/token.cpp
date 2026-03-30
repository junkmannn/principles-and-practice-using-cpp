#include "token.h"

using namespace std;

Token::Token() : kind(END) { }

Token::Token(char syntax) : kind(SYNTAX), syntax(syntax),
	name_arg(), keyword(NOT_A_KEYWORD), number(0.0) { }

Token::Token(const std::string& name_arg, bool is_arg) :
	kind(is_arg ? ARG : NAME), name_arg(name_arg),
	syntax('\0'), keyword(NOT_A_KEYWORD), number(0.0) { }

Token::Token(Keyword keyword) : kind(KEYWORD), keyword(keyword),
	syntax('\0'), name_arg(), number(0.0) { }

Token::Token(double number) : kind(NUMBER), number(number),
	syntax('\0'), name_arg(), keyword(NOT_A_KEYWORD) { }

Token::Kind Token::get_kind() const {
	return kind;
}

char Token::get_syntax() const {
	return syntax;
}

const std::string& Token::get_name() const {
	if (kind != NAME) throw runtime_error("token must be a name");
	return name_arg;
}

const std::string& Token::get_argument() const {
	if (kind != ARG) throw runtime_error("token must be an argument");
	return name_arg;
}

Token::Keyword Token::get_keyword() const {
	return keyword;
}

double Token::get_number() const {
	if (kind != NUMBER) throw runtime_error("token must be a number");
	return number;
}
