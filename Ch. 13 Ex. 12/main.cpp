#define _USE_MATH_DEFINES

#include "Simple_window.h"
#include "Graph.h"
#include <cmath>
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 12");

	const int radius = 150;
	const int center_x = 300;
	const int center_y = 200;
	Circle circle(Point(center_x, center_y), radius);

	double angle = 0.0;
	double steps = M_PI / 45.0;

	Point pt(center_x+radius*cos(angle), center_y+radius*sin(angle));
	Mark mark(pt, 'x');

	win.attach(circle);
	win.attach(mark);

	do {
		win.wait_for_button(); // display!
		angle += steps;
		pt.x = center_x+radius*cos(angle);
		pt.y = center_y-radius*sin(angle);
		mark.move(pt.x-mark.point(0).x, pt.y-mark.point(0).y);
	}
	while (1);
}
