#ifndef DEFINITION_H
#define DEFINITION_H

#include "token_stream.h"
#include "name_value_table.h"
#include "expression.h"

class Definition {
public:
	// Need the token stream to read the definition statement
	// Need the name value table to solve the names
	// Need the expression to solve the expression statement
	Definition(Token_stream& ts, Name_value_table& nvt, Expression& exp);

	// Define a new name (variable or constant)
	double define_name();
	// Redefine an existing name (variable only)
	double redefine_name();

private:
	Token_stream& ts;
	Name_value_table& nvt;
	Expression& exp;

	// Check if the definition is for a variable or a constant
	bool is_constant();
	// Get the name and value for that variable or constant
	void get_name_value(const std::string*& name, double& value);
};

#endif
