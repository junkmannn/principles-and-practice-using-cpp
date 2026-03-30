#include "Simple_window.h"
#include "Graph.h"
#include <string>
#include <cmath>

using namespace std;
using namespace Graph_lib;

double one(double x);
double slope(double x);
double square(double x);
double sloping_cos(double x);

int main() {
	Simple_window win(Point(100,100), 600, 600, "Function graphs");

	const Point graph_origin(300, 300);
	double range_min = -10.0;
	double range_max = 10.0;

	const int xa_length = 400;
	const int xa_notches = 20;
	const Point xa_start(graph_origin.x-400/2, graph_origin.y);
	const string xa_label = "1 == 20 pixels";
	Axis xa(Axis::x, xa_start, xa_length, xa_notches, xa_label);
	xa.set_color(Color::red);
	win.attach(xa);

	const int ya_length = 400;
	const int ya_notches = 20;
	const Point ya_start(graph_origin.x, graph_origin.y+400/2);
	const string ya_label = "1 == 20 pixels";
	Axis ya(Axis::y, ya_start, ya_length, ya_notches, ya_label);
	ya.set_color(Color::red);
	win.attach(ya);

	Function fct_one(one, range_min, range_max, graph_origin, xa_length, xa_notches, ya_notches);
	win.attach(fct_one);

	Function fct_slope(slope, range_min, range_max, graph_origin, xa_length, xa_notches, ya_notches);
	win.attach(fct_slope);
	Text fct_slope_lbl(Point(graph_origin.x-190, graph_origin.y+80), "x/2");
	win.attach(fct_slope_lbl);

	Function fct_square(square, -sqrt(range_max), sqrt(range_max), graph_origin, xa_length, xa_notches, ya_notches);
	win.attach(fct_square);

	Function fct_cos(cos, range_min, range_max, graph_origin, xa_length, xa_notches, ya_notches);
	fct_cos.set_color(Color::blue);
	win.attach(fct_cos);

	Function fct_sloping_cos(sloping_cos, range_min, range_max, graph_origin, xa_length, xa_notches, ya_notches);
	win.attach(fct_sloping_cos);

	win.wait_for_button(); // display!
}

double one(double x) {
	return 1;
}

double slope(double x) {
	return x/2;
}

double square(double x) {
	return x*x;
}

double sloping_cos(double x) {
	return cos(x) + slope(x);
}
