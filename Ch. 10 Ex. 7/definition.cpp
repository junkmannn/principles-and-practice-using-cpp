#include "definition.h"
#include "myexceptions.h"

using namespace std;

Definition::Definition(Token_stream& ts, Name_value_table& nvt, Expression& exp) :
	ts(ts), nvt(nvt), exp(exp) { }

double Definition::define_name() {
	bool constant = is_constant();
	const string* name = nullptr;
	double value = 0.0;
	get_name_value(name, value);

	if (!nvt.add(Name_value(*name, value, constant))) throw Syntax_error("name already defined");

	// print(cout, *name + " = " + to_string(value));
	return value;
}

double Definition::redefine_name() {
	const string* name = nullptr;
	double value = 0.0;
	get_name_value(name, value);

	Name_value* name_value = nullptr;
	if (!nvt.get(*name, name_value)) throw Syntax_error("undefined name");
	if (name_value->is_constant()) throw Syntax_error("cannot redefine a constant");

	name_value->set_value(value);

	// print(cout, *name + " = " + to_string(value));
	return value;
}

bool Definition::is_constant() {
	const Token& token = ts.get();

	// if (token.get_kind() != Token::KEYWORD) throw Syntax_error("var or const expected");

	switch (token.get_keyword()) {
	case Token::VAR:   return false;
	case Token::CONST: return true;
	default:           throw Syntax_error("var or const expected");
	}
}

void Definition::get_name_value(const string*& name, double& value) {
	const Token* token = nullptr;

	// get name
	// -----------------------------------------------------------
	token = &ts.get();

	if (token->get_kind() != Token::NAME) throw Syntax_error("name expected");

	name = &token->get_name();
	// -----------------------------------------------------------

	// =
	// -----------------------------------------------------------
	token = &ts.get();

	// if ((*token).get_kind() != Token::SYNTAX || (*token).get_syntax() != '=')
	if (token->get_syntax() != '=') throw Syntax_error("= expected");
	// -----------------------------------------------------------

	// get value
	// -----------------------------------------------------------
	value = exp.solve();
	// -----------------------------------------------------------
}
