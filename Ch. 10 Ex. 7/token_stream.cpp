#include "token_stream.h"
#include "roman_numeral.h"
#include "myexceptions.h"
#include <sstream>
#include <algorithm>

using namespace std;

const string Token_stream::DEF_KW = "def";
const string Token_stream::REDEF_KW = "redef";
const string Token_stream::VAR_KW = "var";
const string Token_stream::CONST_KW = "const";
const string Token_stream::SQRT_KW = "sqrt";
const string Token_stream::POW_KW = "pow";
const string Token_stream::HELP_KW = "help";

Token_stream::Token_stream() : pos(0), tokens() { }

Token_stream::Token_stream(const std::string& input) {
	set_input(input);
}

const Token& Token_stream::get() {
	if (pos == tokens.size()) throw runtime_error("no more token to get");
	Token& token = tokens[pos];
	++pos;
	return token;
}

void Token_stream::unget() {
	if (pos == 0) throw runtime_error("no token to unget");
	--pos;
}

void Token_stream::set_input(const std::string& new_input) {
	pos = 0;
	init_tokens(new_input);
}

void Token_stream::init_tokens(const std::string& input) {
	tokens.clear();

	istringstream iss(input);

	char c;
	while (iss >> c) {
		switch (c) {
		case '(':
		case ')':
		case '{':
		case '}':
		case '+':
		case '-':
		case '*':
		case '/':
		case '!':
		case ',':
		case '=':
		{
			tokens.push_back(Token(c));
			break;
		}
		case 'I':
		case 'V':
		case 'X':
		case 'L':
		case 'C':
		case 'D':
		case 'M':
		{
			iss.unget();
			Roman_numeral rn;
			iss >> rn;
			if (!iss) throw Syntax_error("roman numeral expected");
			tokens.push_back(Token((double)rn.get_value()));
			/*
			iss.unget();
			double d;
			iss >> d;
			if (!iss) throw Syntax_error("number expected");
			tokens.push_back(Token(d));
			*/
			break;
		}
		default:
		{
			if (!isalpha(c)) throw Syntax_error("invalid name");

			string name;
			name += c;
			while (iss.get(c) && (isalpha(c) || isdigit(c) || c == '_')) name += c;
			iss.unget();

			string lc_name(name);
			transform(lc_name.begin(), lc_name.end(), lc_name.begin(), tolower);

			if (lc_name == DEF_KW) tokens.push_back(Token(Token::DEF));
			else if (lc_name == REDEF_KW) tokens.push_back(Token(Token::REDEF));
			else if (lc_name == VAR_KW) tokens.push_back(Token(Token::VAR));
			else if (lc_name == CONST_KW) tokens.push_back(Token(Token::CONST));
			else if (lc_name == SQRT_KW) tokens.push_back(Token(Token::SQRT));
			else if (lc_name == POW_KW) tokens.push_back(Token(Token::POW));
			else if (lc_name == HELP_KW) tokens.push_back(Token(Token::HELP));
			else tokens.push_back(Token(name));

			break;
		}
		}
	}

	tokens.push_back(Token()); // eof token
}
