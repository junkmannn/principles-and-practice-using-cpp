#include "../std_lib_facilities.h"

class No_real_roots { };

vector<double> solve_quadratic(double a, double b, double c);

int main() {
	cout << "This program solves quadratic equations (ax^2 + bx + c = 0)\n";
	// input a
	cout << "a = ";
	double a = 0;
	cin >> a;
	while (a == 0) {
		cout << "a must not be 0\na = ";
		cin >> a;
	}
	// input b
	cout << "b = ";
	double b = 0;
	cin >> b;
	// input c
	cout << "c = ";
	double c = 0;
	cin >> c;

	try {
		vector<double> solutions = solve_quadratic(a, b, c);
		cout << "x1=" << solutions[0] << ' ' << "x2=" << solutions[1] << '\n';
	}
	catch (No_real_roots &e) {
		cout << "No real roots\n";
	}

	keep_window_open();

	return 0;
}

vector<double> solve_quadratic(double a, double b, double c) {
	double x = b*b-4*a*c;
	if (x < 0) throw No_real_roots();

	vector<double> solutions(2);
	double res  = -b;
	double res2 = sqrt(x);
	double res3 = 2*a;
	solutions[0] = (res-res2)/res3;
	solutions[1] = (res+res2)/res3;
	return solutions;
}