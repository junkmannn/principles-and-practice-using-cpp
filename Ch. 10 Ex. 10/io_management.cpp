#include "io_management.h"
#include "myexceptions.h"
#include <iostream>
#include <fstream>

using namespace std;

IO_Management::IO_Management(Token_stream& ts) :
	ts(ts) { }

std::istream& IO_Management::get_istream() {
	if (ifs.is_open())
		return ifs;
	else
		return cin;
}

std::ostream& IO_Management::get_ostream() {
	if (ofs.is_open())
		return ofs;
	else
		return cout;
}

void IO_Management::set_istream() {
	const string* arg = nullptr;
	get_argument(arg);

	ifs.open(*arg);
	if (!ifs.is_open()) throw Calculator_error("file could not be opened for reading");
}

void IO_Management::set_ostream() {
	const string* arg = nullptr;
	get_argument(arg);

	if (ofs.is_open()) ofs.close();

	if (*arg != "console") {
		ofs.open(*arg);
		if (!ofs.is_open()) throw Calculator_error("file could not be opened for writing");
	}
}

void IO_Management::reset_istream() {
	if (ifs.is_open()) ifs.close();
}

void IO_Management::get_argument(const std::string*& arg) {
	const Token& token = ts.get();
	if (token.get_kind() != Token::ARG) throw Calculator_error("argument expected");
	arg = &token.get_argument();
}
