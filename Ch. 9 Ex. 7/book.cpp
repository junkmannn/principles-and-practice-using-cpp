#include "book.h"
#include <string>

using namespace std;

Book::Book(string p_isbn, string p_title, string p_author, Genre p_genre, string p_copyright_date):
isbn(p_isbn), title(p_title), author(p_author), genre(p_genre), copyright_date(p_copyright_date) {

	if (!is_isbn(isbn)) throw Invalid();
}

string Book::get_isbn() const {
	return isbn;
}

string Book::get_title() const {
	return title;
}

string Book::get_author() const {
	return author;
}

Book::Genre Book::get_genre() const {
	return genre;
}

string Book::get_copyright_date() const {
	return copyright_date;
}

bool Book::is_checked_out() const {
	return checked_out;
}

void Book::check_out() {
	checked_out = true;
}

bool is_isbn(const string& isbn) {
	const char token = '-';
	const int expected_token_count = 3;

	int token_count = 0;
	bool previous = false;

	for (int i = 0, size = isbn.size(); i < size; ++i) {
		if (isdigit(isbn[i])) {
			previous = true;
		}
		else if (isbn[i] == token) {
			if (!previous) return false; // two dashes in a row? that's invalid!
			++token_count;
			if (token_count < expected_token_count) { // still more tokens to go; keep going
				previous = false;
			}
			else {
				// LAST TOKEN
				// check for what should be the last character:
				// not ok? that means the isbn ends with a dash which is invalid
				// OR it has more than one character after the dash which is also invalid
				// ok? check if it is a digit or a letter and nothing else
				if (i + 1 == size - 1 && isalnum(isbn[i + 1])) {
					return true; // DONE: valid isbn
				}
				else {
					return false;
				}
			}
		}
		else {
			return false;
		}
	}

	return false;
}

bool operator==(const Book& b1, const Book& b2) {
	return (b1.get_isbn() == b2.get_isbn());
}

bool operator!=(const Book& b1, const Book& b2) {
	return !(b1 == b2);
}

ostream& operator<<(ostream& os, const Book& b) {
	os << "Title: " << b.get_title() <<
		"\nAuthor: " << b.get_author() <<
		"\nISBN: " << b.get_isbn();
	return os;
}