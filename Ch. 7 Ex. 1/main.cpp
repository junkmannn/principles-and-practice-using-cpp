/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../std_lib_facilities.h"

const string prompt = "> ";
const string result = "= ";

const char defkind = 'd';
const char quitkind = 'q';
const char printkind = ';';
const char numberkind = '0';
const char namekind = 'n';
const char sqrtkind = 's';
const char powkind = 'p';

const string defkey = "def";
const string quitkey = "quit";
const string sqrtkey = "sqrt";
const string powkey = "pow";

class Token_stream;
struct Token;
struct Variable;

double get_value(string s);
void set_value(string s, double d);
bool is_declared(string s);
double define();

unsigned int factorial(unsigned int a);

double primary();
double term();
double expression();
double statement();

void calculate();

void clean_up_mess();

struct Token {
	char kind;
	double value;
	string name;
	Token(char c): kind(c), value(0.0) { }
	Token(char c, double d): kind(c), value(d) { }
	Token(char c, string s): kind(c), name(s) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream(): full(false), buffer(0) { }

	Token get() {
		if (full) {
			full = false;
			return buffer;
		}

		char c;
		cin >> c;

		switch (c) {
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
			return Token(c);
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
			double d;
			cin >> d;
			if (!cin.good()) error("Bad token");
			return Token(numberkind, d);
		}
		default:
			if (isalpha(c)) {
				string s;
				s += c;
				while (cin.get(c) && (isalpha(c) || isdigit(c) || c == '_')) s += c;
				cin.unget();
				if (s == defkey) return Token(defkind);
				else if (s == quitkey) return Token(quitkind);
				else if (s == sqrtkey) return Token(sqrtkind);
				else if (s == powkey) return Token(powkind);
				return Token(namekind, s);
			}
			error("Bad token");
		}
	}

	void unget(Token t) {
		buffer = t;
		full = true;
	}

	void ignore(char c) {
		if (full && c == buffer.kind) {
			full = false;
			return;
		}

		full = false;

		char c2;
		while (cin >> c2)
			if (c2 == c) return;
	}

	void ignore() {
		full = false;

		cin.clear();

		char c;
		while (true) {
			c = cin.get();
			if (c == '\n') return;
		}
	}
};

Token_stream ts;

struct Variable {
	string name;
	double value;
	Variable(string s, double d): name(s), value(d) { }
};

vector<Variable> vars;

double get_value(string s) {
	for (int i = 0; i < vars.size(); ++i) {
		if (vars[i].name == s) return vars[i].value;
	}
	error("get: undefined name ", s);
}

void set_value(string s, double d) {
	for (int i = 0; i < vars.size(); ++i) {
		if (vars[i].name == s) {
			vars[i].value = d;
			return;
		}
	}
	error("set: undefined name ", s);
}

bool is_declared(string s) {
	for (int i = 0; i < vars.size(); ++i) {
		if (vars[i].name == s) return true;
	}
	return false;
}

double define() {
	Token t = ts.get();
	switch (t.kind) {
	case namekind:
	{
		string name = t.name;
		if (is_declared(name)) error(name, " declared twice");
		t = ts.get();
		if (t.kind != '=') error("= missing in declaration of ", name);
		double val = expression();
		vars.push_back(Variable(name, val));
		return val;
	}
	default:
		error("name expected in declaration");
	}
}

unsigned int factorial(unsigned int a) {
	unsigned int f = 1;
	for (unsigned int i = 2; i <= a; ++i) f *= i;
	return f;
}

double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}') error("'}' expected");
		return d;
	}
	case sqrtkind:
	{
		t = ts.get();
		if (t.kind != '(') error("'(' expected");
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		if (d < 0) error("sqrt of a negative value");
		return sqrt(d);
	}
	case powkind:
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
	case numberkind:
	{
		Token t2 = ts.get();
		if (t2.kind == '!') {
			return factorial(t.value);
		}
		else {
			ts.unget(t2);
			return t.value;
		}
	}
	case namekind:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term() {
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			return left *= primary();
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			return left /= d;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression() {
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			return left += term();
		case '-':
			return left -= term();
		default:
			ts.unget(t);
			return left;
		}
	}
}

double statement() {
	Token t = ts.get();
	switch (t.kind) {
	case defkind:
		return define();
	default:
		ts.unget(t);
		return expression();
	}
}

void calculate() {
	while (true) {
		try {
			cout << prompt;
			Token t = ts.get();
			while (t.kind == printkind) t = ts.get();
			if (t.kind == quitkind) return;
			ts.unget(t);
			cout << result << statement() << '\n';
		}
		catch (runtime_error& e) {
			cerr << e.what() << '\n';
			clean_up_mess();
		}
	}
}

void clean_up_mess() {
	// ts.ignore(print);
	ts.ignore();
}

int main() {
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
