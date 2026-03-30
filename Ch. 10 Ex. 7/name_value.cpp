#include "name_value.h"

using namespace std;

// Name_value::Name_value() { }

Name_value::Name_value(const std::string& name, double value, bool constant) :
	name(name), value(value), constant(constant) { }

const std::string& Name_value::get_name() const {
	return name;
}

double Name_value::get_value() const {
	return value;
}

bool Name_value::is_constant() const {
	return constant;
}

void Name_value::set_value(double new_value) {
	if (constant) throw runtime_error("can't change value of a constant");
	value = new_value;
}
