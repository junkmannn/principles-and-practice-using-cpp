#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include <vector>
#include "token.h"

class Token_stream {
public:
	// keywords
	static const std::string DEF_KW;
	static const std::string REDEF_KW;
	static const std::string VAR_KW;
	static const std::string CONST_KW;
	static const std::string SQRT_KW;
	static const std::string POW_KW;
	static const std::string HELP_KW;
	static const std::string FROM_KW;
	static const std::string TO_KW;

	// Create an empty token stream
	Token_stream();
	// Create a token stream from the input (calls set_input)
	Token_stream(const std::string& input);

	// Get the next token in the stream
	const Token& get();
	// Unget the previously got token
	void unget();

	// Check if stream contains no token other than the END token
	bool is_empty();

	// Tokenize string input (must be a single line)
	void set_input(const std::string& new_input);

private:
	size_t pos;
	std::vector<Token> tokens;

	void init_tokens(const std::string& input);
};

#endif
