
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../std_lib_facilities.h"

// OK
struct Token {
	char kind;
	double value;
	string name;
	Token(char ch): kind(ch), value(0) { }
	Token(char ch, double val): kind(ch), value(val) { }
	Token(char ch, string val): kind(ch), name(val) { }
};

// OK
class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream(): full(0), buffer(0) { }

	Token get();
	void unget(Token t) {
		buffer = t;
		full = true;
	}
	void ignore(char c);
	void ignore();
};

// OK
const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char square = 's';
const char power = 'p';
const char declkey = '#';
const string exitkey = "exit";
const string sqrtkey = "sqrt";
const string powkey = "pow";

// OK
Token Token_stream::get() {
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '{':
	case '}':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case '!':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{
		cin.unget();
		double val;
		cin >> val;
		return Token(number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; // Error 1: s = ch;
			cin.unget();
			if (s == exitkey) return Token(quit); // Error 2: Token(name)
			else if (s == sqrtkey) return Token(square);
			else if (s == powkey) return Token(power);
			return Token(name, s);
		}
		else if (ch == declkey) {
			return Token(let);
		}
		error("Bad token");
	}
}

// OK
void Token_stream::ignore(char c) {
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch) {
		if (ch == c) return;
	}
}

// OK
void Token_stream::ignore() {
	full = false;

	char ch;
	while (true) {
		ch = cin.get();
		if (ch == '\n') return;
	}

	// cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// OK
struct Variable {
	string name;
	double value;
	Variable(string n, double v): name(n), value(v) { }
};

// OK
vector<Variable> names;

// OK
double get_value(string s) {
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == s) return names[i].value;
	}
	error("get: undefined name ", s);
}

// OK
void set_value(string s, double d) {
	for (int i = 0; i < names.size(); ++i) { // Error 3: i <= names.size();
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	}
	error("set: undefined name ", s);
}

// OK
bool is_declared(string s) {
	for (int i = 0; i < names.size(); ++i) {
		if (names[i].name == s) return true;
	}
	return false;
}

// OK
Token_stream ts;

// OK
double expression();

// OK
unsigned int factorial(unsigned int a) {
	unsigned int f = 1;
	for (unsigned int i = 2; i <= a; ++i) f *= i;
	return f;
}

// OK
double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d; // Error 4: return was missing
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case square:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		if (d < 0) error("sqrt of a negative value");
		return sqrt(d);
	}
	case power:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ',') error("',' expected");
		double d2 = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return pow(d, (int)d2);
	}
	case '-':
		return -primary();
	case number:
	{
		// return t.value;

		Token t2 = ts.get();
		if (t2.kind == '!') {
			return factorial(t.value);
		}
		else {
			ts.unget(t2);
			return t.value;
		}

	}
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

// OK
double term() {
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

// OK
double expression() {
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

// OK
double declaration() {
	Token t = ts.get();
	if (t.kind != name) error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

// OK
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

// OK
void clean_up_mess() {
	// ts.ignore(print);
	ts.ignore();
}

// OK
const string prompt = "> ";
const string result = "= ";

// OK
void calculate() {
	while (true) {
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == print) t = ts.get();
			if (t.kind == quit) return;
			ts.unget(t);
			cout << result << statement() << '\n';
		}
		catch (runtime_error& e) {
			cerr << e.what() << '\n';
			clean_up_mess();
		}
	}
}

// OK
void predefine_vars() {
	names.push_back(Variable("k", 1000));
}

// OK
int main() {
	predefine_vars();
	try {
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << '\n';
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}