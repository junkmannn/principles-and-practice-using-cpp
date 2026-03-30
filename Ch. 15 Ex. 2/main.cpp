#include "Simple_window.h"
#include "Graph.h"
#include "my_function.h"

using namespace std;
using namespace Graph_lib;

double slope(double x);
double ten_sin(double x);

int main() {
	Simple_window win(Point(100, 100), 600, 600, "Ch. 15 Ex. 2");

	Point graph_origin(300, 300);

	My_function fct;
	fct.set_func(slope);
	fct.set_origin(graph_origin);
	fct.set_precision(100);
	fct.set_range_min(-10.0);
	fct.set_range_max(10.0);
	fct.set_xscale(20.0);
	fct.set_yscale(20.0);
	fct.set_color(Color::red);
	win.attach(fct);

	int xa_length = 400;
	Point xa_start;
	xa_start.x = graph_origin.x - xa_length/2;
	xa_start.y = graph_origin.y;
	Axis xa(Axis::x, xa_start, 400, 0, "x");
	win.attach(xa);

	int ya_length = 400;
	Point ya_start;
	ya_start.x = graph_origin.x;
	ya_start.y = graph_origin.y + ya_length/2;
	Axis ya(Axis::y, ya_start, ya_length, 0, "y");
	win.attach(ya);

	win.wait_for_button(); // display!

	fct.set_func(ten_sin);

	win.wait_for_button(); // display!

	fct.set_precision(10);

	win.wait_for_button(); // display!

	fct.set_precision(100);

	win.wait_for_button(); // display!

	fct.set_range_min(-5.0);
	fct.set_range_max(5.0);
	fct.set_xscale(40.0);
	fct.set_yscale(20.0);

	win.wait_for_button(); // display!
}

double slope(double x) {
	return x;
}

double ten_sin(double x) {
	return 10*sin(x);
}
