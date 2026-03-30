#include "Simple_window.h"
#include "arc.h"
#include <string>
#include <iostream>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Ellipse Fl_Ellipse;
typedef Graph_lib::Arc Fl_Arc;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 1");

	Fl_Arc arc1(Point(150, 100), 100, 50, 0.0, 90.0);
	arc1.set_color(Color::red);
	arc1.set_fill_color(Color::blue);
	Fl_Arc arc2(Point(250, 100), 50, 50, 0.0, 360.0);
	arc2.set_color(Color::green);
	Fl_Arc arc3(Point(250, 200), 75, 10, 0.0, 270.0);
	arc3.set_color(Color::blue);
	win.attach(arc1);
	win.attach(arc2);
	win.attach(arc3);

	win.wait_for_button(); // display!

	arc1.set_angle_start(90.0);
	arc1.set_angle_end(180.0);

	win.wait_for_button(); // display!

	arc1.set_semi_major_axis(50);
	arc1.set_fill_color(Color::white);

	win.wait_for_button(); // display!
}
