#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
public:
	Person() : _age(0) { }
	Person(const std::string& first_name, const std::string& second_name, int age);

	const std::string& get_first_name() const { return _first_name; }
	void set_first_name(const std::string& first_name);

	const std::string& get_second_name() const { return _second_name; }
	void set_second_name(const std::string& second_name);

	int get_age() const { return _age; }
	void set_age(int age);

private:
	std::string _first_name;
	std::string _second_name;
	int _age;
};

std::istream& operator>>(std::istream& is, Person& p);
std::ostream& operator<<(std::ostream& os, const Person& p);

#endif
