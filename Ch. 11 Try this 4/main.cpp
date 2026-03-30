#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Person_info {
	Person_info(string firstname, string lastname, string telnum, string email) :
	firstname(firstname), lastname(lastname), telnum(telnum), email(email) { }

	string firstname;
	string lastname;
	string telnum;
	string email;
};

void print_people_info(vector<Person_info>& pi_vec);
void add_row(const string& col1, const string& col2, const string& col3, const string& col4);
void keep_window_open();

int main() {
	vector<Person_info> pi_vec;
	pi_vec.push_back(Person_info("John", "Smith", "666 666-6666", "john_smith@anonymous.com"));

	print_people_info(pi_vec);

	keep_window_open();

	return 0;
}

void print_people_info(vector<Person_info>& pi_vec) {
	// Header
	add_row("First name", "Last name", "Telephone number", "Email address");

	// Content
	for (int i = 0, size = pi_vec.size(); i < size; ++i) {
		Person_info& pi = pi_vec[i];
		add_row(pi.firstname, pi.lastname, pi.telnum, pi.email);
	}

}

void add_row(const string& col1, const string& col2, const string& col3, const string& col4) {
	cout << left << setw(20) << col1
		<< left << setw(20) << col2
		<< left << setw(20) << col3
		<< left << setw(25) << col4
		<< '\n';
}

void keep_window_open() {
	cout << "Please enter a character to exit.\n";
	char c;
	cin >> c;
}
