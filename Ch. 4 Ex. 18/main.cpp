#include "../std_lib_facilities.h"

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

	vector<double> solutions = solve_quadratic(a, b, c);
	cout << "x1=" << solutions[0] << ' ' << "x2=" << solutions[1] << '\n';

	keep_window_open();

	return 0;
}

vector<double> solve_quadratic(double a, double b, double c) {
	vector<double> solutions(2);
	solutions[0] = (-b-sqrt(b*b-4*a*c))/(2*a);
	solutions[1] = (-b+sqrt(b*b-4*a*c))/(2*a);
	return solutions;
}