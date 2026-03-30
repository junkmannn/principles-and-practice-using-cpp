#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {

public:
	class Invalid { };

	Book(std::string p_isbn, std::string p_title, std::string p_author, std::string p_copyright_date);

	std::string get_isbn() const;
	std::string get_title() const;
	std::string get_author() const;
	std::string get_copyright_date() const;
	bool is_checked_out() const;

	void check_out();

private:
	std::string isbn;
	std::string title;
	std::string author;
	std::string copyright_date;
	bool checked_out;

};

bool is_isbn(const std::string& isbn);

#endif
