#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include <vector>
#include "token.h"

class Token_stream {
public:
	static const std::string DEF_KW;
	static const std::string REDEF_KW;
	static const std::string VAR_KW;
	static const std::string CONST_KW;
	static const std::string SQRT_KW;
	static const std::string POW_KW;
	static const std::string HELP_KW;

	Token_stream();
	Token_stream(const std::string& input);

	const Token& get();
	void unget();

	void set_input(const std::string& new_input);

private:
	size_t pos;
	std::vector<Token> tokens;

	void init_tokens(const std::string& input);
};

#endif
