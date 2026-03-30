#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

#include <omp.h>

using namespace std;
using namespace Graph_lib;

struct Superellipse {
	Superellipse(double a, double b, double n, double m) : a(abs(a)), b(abs(b)), n(n), m(m) { }
	double a;
	double b;
	double n;
	double m;
};

void eval_superellipse(double x, double y[2], const Superellipse& se);

int main() {
	const int SCALING = 75;
	const int WINDOW_WIDTH = 600;
	const int WINDOW_HEIGHT = 600;

	string window_title;
	bool ok = false;

	cout << "Enter values for a, b, n > 0, m > 0 and N > 0 in the respective order.\n";
	double a = 0.0;
	double b = 0.0;
	double n = 0.0;
	double m = 0.0;
	int N = 0;
	if (cin >> a &&
		cin >> b &&
		cin >> n && n > 0.0 &&
		cin >> m && m > 0.0 &&
		cin >> N && N > 0) {
		ostringstream oss;
		oss << "a = " << a << ", b = " << b << ", n = " << n << ", m = " << m << ", N = " << N;
		window_title = oss.str();
		ok = true;
	}
	else {
		window_title = "Bad parameters";
		ok = false;
	}

	Simple_window win(Point(100, 100), WINDOW_WIDTH, WINDOW_HEIGHT, window_title);

	if (!ok) {
		win.wait_for_button(); // display!
		return 0;
	}

	Superellipse se(a, b, n, m);

	Open_polyline se_tl;
	Open_polyline se_tr;
	Open_polyline se_bl;
	Open_polyline se_br;

	double steps = se.a / (N/2);
	double x = 0.0;
	for (int i = 0; i <= (N/2); ++i) {
		double y[2];
		eval_superellipse(x, y, se);
		cout << '(' << x << ", " << y[0] << ")\n";
		cout << '(' << x << ", " << y[1] << ")\n\n";

		se_tl.add(Point(-x*SCALING + WINDOW_WIDTH/2, y[1]*SCALING + WINDOW_HEIGHT/2));
		se_tr.add(Point(x*SCALING  + WINDOW_WIDTH/2, y[1]*SCALING + WINDOW_HEIGHT/2));
		se_bl.add(Point(-x*SCALING + WINDOW_WIDTH/2, y[0]*SCALING + WINDOW_HEIGHT/2));
		se_br.add(Point(x*SCALING  + WINDOW_WIDTH/2, y[0]*SCALING + WINDOW_HEIGHT/2));
		x += steps;
	}

	Axis xa(Axis::x, Point(0, WINDOW_HEIGHT/2), WINDOW_WIDTH, 8);
	Axis ya(Axis::y, Point(WINDOW_WIDTH/2, WINDOW_HEIGHT), WINDOW_HEIGHT, 8);

	win.attach(se_tl);
	win.attach(se_tr);
	win.attach(se_bl);
	win.attach(se_br);
	win.attach(xa);
	win.attach(ya);

	win.wait_for_button(); // display!

	return 0;
}

void eval_superellipse(double x, double y[2], const Superellipse& se) {
	double abs_b_exp_n = pow(abs(se.b), se.n);
	double abs_xdiva_exp_m = pow(abs(x/se.a), se.m);
	double base = abs_b_exp_n * (1 - abs_xdiva_exp_m);
	double exp = 1/se.n;
	y[0] = pow(abs(base), exp);
	y[1] = -y[0];
}
