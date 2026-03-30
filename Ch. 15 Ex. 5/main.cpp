#define _USE_MATH_DEFINES

#include "Simple_window.h"
#include "Graph.h"
#include "my_function.h"
#include <cmath>

using namespace std;
using namespace Graph_lib;

double leibniz_series(double n);
double pi_div_4(double x);

int main() {
	Simple_window win(Point(100,100), 1800, 600, "Ch. 15 Ex. 5");

	const Point graph_origin(100, 500);
	const int xa_length = 1600;
	const int ya_length = 400;
	const double yscale = 400.0;

	int nths[] = {5, 10, 20, 40, 80};
	const int num_nths = sizeof(nths)/sizeof(int);

	// functions
	// ------------------------------------------
	My_function leibniz;
	leibniz.set_func(leibniz_series);
	leibniz.set_origin(graph_origin);
	leibniz.set_range_min(0.0);
	leibniz.set_yscale(yscale);
	leibniz.set_color(Color::red);
	win.attach(leibniz);

	My_function pi4;
	pi4.set_func(pi_div_4);
	pi4.set_origin(graph_origin);
	pi4.set_precision(1);
	pi4.set_range_min(0.0);
	pi4.set_range_max(nths[0]);
	pi4.set_xscale(double(xa_length/nths[0]));
	pi4.set_yscale(yscale);
	pi4.set_color(Color::blue);
	win.attach(pi4);
	// ------------------------------------------

	// axes
	// ------------------------------------------
	Axis* xa = nullptr;
	Axis ya(Axis::y, graph_origin, ya_length, 4);
	win.attach(ya);
	// ------------------------------------------

	// labels
	// ------------------------------------------
	Point xa_lbl_pos(graph_origin);
	xa_lbl_pos.x += xa_length/2 - 50;
	xa_lbl_pos.y += 30;
	Text xa_lbl(xa_lbl_pos, "Number of terms");
	win.attach(xa_lbl);

	Point xa_min_pos(graph_origin);
	xa_min_pos.x -= 3;
	xa_min_pos.y += 30;
	Text xa_min(xa_min_pos, "1");
	win.attach(xa_min);

	Point xa_max_pos(graph_origin);
	xa_max_pos.x += xa_length - 3;
	xa_max_pos.y += 30;
	Text xa_max(xa_max_pos, "x");
	win.attach(xa_max);

	Point ya_lbl_pos(graph_origin);
	ya_lbl_pos.x -= 85;
	ya_lbl_pos.y -= ya_length/2 - 5;
	Text ya_lbl(ya_lbl_pos, "Estimation");
	win.attach(ya_lbl);

	Point ya_max_pos(graph_origin);
	ya_max_pos.x -= 30;
	ya_max_pos.y -= ya_length - 5;
	Text ya_max(ya_max_pos, "1");
	win.attach(ya_max);

	Point pi4_lbl_pos(graph_origin);
	pi4_lbl_pos.x -= 38;
	pi4_lbl_pos.y -= int(ya_length*M_PI_4) - 3;
	Text pi4_lbl(pi4_lbl_pos, "pi/4");
	pi4_lbl.set_color(Color::blue);
	win.attach(pi4_lbl);

	Point graph_title_pos(graph_origin);
	graph_title_pos.x += xa_length/2 - 120;
	graph_title_pos.y -= ya_length + 35;
	Text graph_title(graph_title_pos, "Estimation of pi/4 using Leibniz series");
	graph_title.set_color(Color::red);
	win.attach(graph_title);
	// ------------------------------------------

	// animate...
	for (int i = 0; i < num_nths; ++i) {
		leibniz.set_precision(nths[i]);
		leibniz.set_range_max(double(nths[i]));
		leibniz.set_xscale(double(xa_length/nths[i]));

		xa = new Axis(Axis::x, graph_origin, xa_length, nths[i]);
		win.attach(*xa);

		xa_max.set_label(to_string(nths[i]+1));

		win.wait_for_button(); // display!

		win.detach(*xa);
		delete xa;
	}
}

double leibniz_series(double n) {
	double sum = 0.0;
	double denom = 1.0;

	for (int i = 0; i <= int(n); ++i) {
		if (i & 1) // odd
			sum -= 1.0/denom;
		else // even
			sum += 1.0/denom;
		denom += 2.0;
	}

	return sum;
}

double pi_div_4(double x) {
	return M_PI_4;
}
