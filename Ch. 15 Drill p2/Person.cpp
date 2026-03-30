#include "Person.h"
#include <string>

using namespace std;

bool is_valid_name(const string& name);

Person::Person(const string& first_name, const string& second_name, int age) {
	try {
		set_first_name(first_name);
		set_second_name(second_name);
		set_age(age);
	}
	catch (invalid_argument &e) {
		_first_name.clear();
		_second_name.clear();
		_age = 0;
		throw;
	}
}

const string BAD_NAME_MESSAGE = "; : \" ' [ ] * & ^ % $ # @ ! are not allowed";

void Person::set_first_name(const string& first_name) {
	if (!is_valid_name(first_name)) throw invalid_argument(BAD_NAME_MESSAGE);
	_first_name = first_name;
}

void Person::set_second_name(const string& second_name) {
	if (!is_valid_name(second_name)) throw invalid_argument(BAD_NAME_MESSAGE);
	_second_name = second_name;
}

void Person::set_age(int age) {
	if (age < 0 || age >= 150) throw invalid_argument("age must be in range of [0:150)");
	_age = age;
}

istream& operator>>(istream& is, Person& p) {
	string first_name;
	string second_name;
	int age;

	if (is >> first_name >> second_name >> age) {
		try {
			p = Person(first_name, second_name, age);
			return is;
		}
		catch (invalid_argument &e) { }
	}

	is.setstate(ios::failbit);

	return is;
}

ostream& operator<<(ostream& os, const Person& p) {
	os << "First name: " << p.get_first_name() << ", Second name: " << p.get_second_name()
	   << ", Age: " << p.get_age();
	return os;
}

bool is_valid_name(const string& name) {
	for (int i = 0, size = name.size(); i < size; ++i) {
		switch (name[i]) {
		case ';': case ':': case '[': case ']': case '*': case '&': case '^':
		case '%': case '$': case '#': case '@': case '!': case '"': case '\'':
			return false;
		}
	}
	return true;
}
