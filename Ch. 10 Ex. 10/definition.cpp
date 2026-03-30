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

	if (!nvt.add(Name_value(*name, value, constant))) throw Calculator_error("name already defined");

	return value;
}

double Definition::redefine_name() {
	const string* name = nullptr;
	double value = 0.0;
	get_name_value(name, value);

	Name_value* name_value = nullptr;
	if (!nvt.get(*name, name_value)) throw Calculator_error("undefined name");
	if (name_value->is_constant()) throw Calculator_error("cannot redefine a constant");

	name_value->set_value(value);

	return value;
}

bool Definition::is_constant() {
	const Token& token = ts.get();

	switch (token.get_keyword()) {
	case Token::VAR:   return false;
	case Token::CONST: return true;
	default:           throw Calculator_error("var or const expected");
	}
}

void Definition::get_name_value(const string*& name, double& value) {
	const Token* token = nullptr;

	// get name
	// -----------------------------------------------------------
	token = &ts.get();

	if (token->get_kind() != Token::NAME) throw Calculator_error("name expected");

	name = &token->get_name();
	// -----------------------------------------------------------

	// =
	// -----------------------------------------------------------
	token = &ts.get();

	if (token->get_syntax() != '=') throw Calculator_error("= expected");
	// -----------------------------------------------------------

	// get value
	// -----------------------------------------------------------
	value = exp.solve();
	// -----------------------------------------------------------
}
