#ifndef IO_MANAGEMENT_H
#define IO_MANAGEMENT_H

#include "token_stream.h"
#include <fstream>

class IO_Management {
public:
	// Need the token stream to read the IO redirect statement
	IO_Management(Token_stream& ts);

	// Get current input stream
	std::istream& get_istream();
	// Get current output stream
	std::ostream& get_ostream();

	// Set the input stream to the console (cin) or a file
	void set_istream();
	// Set the output stream to the console (cout) or a file
	void set_ostream();
	// Reset the input stream back to cin
	void reset_istream();

private:
	Token_stream& ts;
	std::ifstream ifs;
	std::ofstream ofs;

	// Get the argument (file name or console) for the IO redirect
	void get_argument(const std::string*& arg);
};

#endif
