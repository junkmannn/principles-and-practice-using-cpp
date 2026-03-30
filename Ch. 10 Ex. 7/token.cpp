#include "token.h"

using namespace std;

Token::Token() : kind(END) { }

Token::Token(char syntax) : kind(SYNTAX), syntax(syntax),
	name(), keyword(NOT_A_KEYWORD), number(0.0) { }

Token::Token(const std::string& name) : kind(NAME), name(name),
	syntax('\0'), keyword(NOT_A_KEYWORD), number(0.0) { }

Token::Token(Keyword keyword) : kind(KEYWORD), keyword(keyword),
	syntax('\0'), name(), number(0.0) { }

Token::Token(double number) : kind(NUMBER), number(number),
	syntax('\0'), name(), keyword(NOT_A_KEYWORD) { }

Token::Kind Token::get_kind() const {
	return kind;
}

char Token::get_syntax() const {
	// if (kind != SYNTAX) throw runtime_error("token must be syntax");
	return syntax;
}

const std::string& Token::get_name() const {
	// if (kind != NAME) throw runtime_error("token must be a name");
	return name;
}

Token::Keyword Token::get_keyword() const {
	// if (kind != KEYWORD) throw runtime_error("token must be a keyword");
	return keyword;
}

double Token::get_number() const {
	// if (kind != NUMBER) throw runtime_error("token must be a number");
	return number;
}
