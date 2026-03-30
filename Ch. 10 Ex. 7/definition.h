#ifndef DEFINITION_H
#define DEFINITION_H

#include "token_stream.h"
#include "name_value_table.h"
#include "expression.h"

class Definition {
public:
	Definition(Token_stream& ts, Name_value_table& nvt, Expression& exp);

	double define_name();
	double redefine_name();

private:
	Token_stream& ts;
	Name_value_table& nvt;
	Expression& exp;

	bool is_constant();
	void get_name_value(const std::string*& name, double& value);
};

#endif
