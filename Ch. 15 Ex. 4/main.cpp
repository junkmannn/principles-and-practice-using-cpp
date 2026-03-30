#include "Simple_window.h"
#include "Graph.h"
#include "my_function.h"

using namespace std;
using namespace Graph_lib;

double func0(double x);
double func1(double x);

int main() {
	Simple_window win(Point(100,100), 600, 600, "Ch. 15 Ex. 4");

	const int NUM_FUNC = 4;
	const Point graph_origin(300, 300);
	const double range_min = -10.0;
	const double range_max = 10.0;
	const double range_total = range_max-range_min;
	const double xscale = 20.0;
	const double yscale = 50.0;

	// functions
	// -----------------------------------
	My_function fx[NUM_FUNC];

	fx[0].set_func(func0);
	fx[1].set_func(func1);
	fx[2].set_func(sin);
	fx[3].set_func(cos);

	fx[0].set_color(Color::red);
	fx[1].set_color(Color::blue);
	fx[2].set_color(Color::green);
	fx[3].set_color(Color::cyan);

	for (int i = 0; i < NUM_FUNC; ++i) {
		fx[i].set_origin(graph_origin);
		fx[i].set_precision(100);
		fx[i].set_range_min(range_min);
		fx[i].set_range_max(range_max);
		fx[i].set_xscale(xscale);
		fx[i].set_yscale(yscale);

		win.attach(fx[i]);
	}
	// -----------------------------------

	// function labels
	// -----------------------------------
	Text* fx_lbl[NUM_FUNC]; // no default constructor
	for (int i = 0; i < NUM_FUNC; ++i) {
		fx_lbl[i] = new Text(graph_origin, "");
	}

	fx_lbl[0]->move(-290, 20);
	fx_lbl[0]->set_label("sin(x)+cos(x)");
	fx_lbl[0]->set_color(Color::red);
	win.attach(*fx_lbl[0]);

	fx_lbl[1]->move(-298, -45);
	fx_lbl[1]->set_label("sin(x)^2+cos(x)^2");
	fx_lbl[1]->set_color(Color::blue);
	fx_lbl[1]->set_font_size(12);
	win.attach(*fx_lbl[1]);

	fx_lbl[2]->move(-245, -20);
	fx_lbl[2]->set_label("sin(x)");
	fx_lbl[2]->set_color(Color::green);
	win.attach(*fx_lbl[2]);

	fx_lbl[3]->move(-245, 45);
	fx_lbl[3]->set_label("cos(x)");
	fx_lbl[3]->set_color(Color::cyan);
	win.attach(*fx_lbl[3]);
	// -----------------------------------

	// axes
	// -----------------------------------
	int xa_length = range_total*xscale;
	Point xa_pos = graph_origin;
	xa_pos.x -= xa_length/2;
	Axis xa(Axis::x, xa_pos, xa_length, int(xa_length/xscale), "x [1 notch = 1 unit]");
	win.attach(xa);

	int ya_length = xa_length;
	Point ya_pos = graph_origin;
	ya_pos.y += ya_length/2;
	Axis ya(Axis::y, ya_pos, ya_length, int(ya_length/yscale), "y [1 notch = 1 unit]");
	win.attach(ya);
	// -----------------------------------

	win.wait_for_button(); // display!
}

double func0(double x) {
	return sin(x)+cos(x);
}

double func1(double x) {
	return pow(sin(x),2.0)+pow(cos(x),2.0);
}
