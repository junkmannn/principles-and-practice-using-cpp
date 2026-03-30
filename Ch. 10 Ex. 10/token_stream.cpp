#include "token_stream.h"
#include "myexceptions.h"
#include <sstream>
#include <algorithm>

using namespace std;

const std::string Token_stream::DEF_KW = "def";
const std::string Token_stream::REDEF_KW = "redef";
const std::string Token_stream::VAR_KW = "var";
const std::string Token_stream::CONST_KW = "const";
const std::string Token_stream::SQRT_KW = "sqrt";
const std::string Token_stream::POW_KW = "pow";
const std::string Token_stream::HELP_KW = "help";
const std::string Token_stream::FROM_KW = "from";
const std::string Token_stream::TO_KW = "to";

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

bool Token_stream::is_empty() {
	return tokens.size() < 2;
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
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			iss.unget();
			double d;
			iss >> d;
			if (!iss) throw Calculator_error("number expected");
			tokens.push_back(Token(d));
			break;
		}
		case '"':
		{
			// TODO: more testing
			string argument;
			while (iss.get(c) && c != '"') argument += c;
			if (!iss) throw Calculator_error("\" expected");
			tokens.push_back(Token(argument, true));
			break;
		}
		default:
		{
			if (!isalpha(c) && c != '_') throw Calculator_error("invalid name");

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
			else if (lc_name == FROM_KW) tokens.push_back(Token(Token::FROM));
			else if (lc_name == TO_KW) tokens.push_back(Token(Token::TO));
			else tokens.push_back(Token(name, false));

			break;
		}
		}
	}

	tokens.push_back(Token()); // eof token
}
