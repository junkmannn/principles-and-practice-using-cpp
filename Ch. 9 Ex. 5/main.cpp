#include "book.h"
#include "../std_lib_facilities.h";

using namespace std;

void test_book();

int main() {
	// test_book();

	keep_window_open();

	return 0;
}

void test_book() {
	string isbn;

	isbn = "33-33-33-0"; if (!is_isbn(isbn)) throw Book::Invalid();
	isbn = "33-33-33-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33-33-00"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33-33-AA"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33-33-."; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33-33--"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33-33-"; if (!is_isbn(isbn)) throw Book::Invalid();
	isbn = "33-33-3-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33-3A-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33--A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33--33-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "-33-33-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "A-33-33-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-A-33-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33-A-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	isbn = "33-333-3333-A"; if (!is_isbn(isbn)) throw Book::Invalid();
	// isbn = "33-33-33-33-A"; if (!is_isbn(isbn)) throw Book::Invalid();

	Book b("33-33-33-0", "title", "author", "date");
	// b = Book("33-33-33-AA", "title", "author", "date");
}