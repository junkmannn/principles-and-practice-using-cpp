#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 12 Ex. 8");

	Circle blue_ring(Point(100, 150), 50);
	blue_ring.set_color(Color::blue);
	blue_ring.set_style(Line_style(Line_style::solid, 4));

	Circle black_ring(Point(210, 150), 50);
	black_ring.set_color(Color::black);
	black_ring.set_style(Line_style(Line_style::solid, 4));

	Circle red_ring(Point(320, 150), 50);
	red_ring.set_color(Color::red);
	red_ring.set_style(Line_style(Line_style::solid, 4));

	Circle yellow_ring(Point(155, 200), 50);
	yellow_ring.set_color(Color::yellow);
	yellow_ring.set_style(Line_style(Line_style::solid, 4));

	Circle green_ring(Point(265, 200), 50);
	green_ring.set_color(Color::dark_green);
	green_ring.set_style(Line_style(Line_style::solid, 4));


	win.attach(yellow_ring);
	win.attach(green_ring);
	win.attach(blue_ring);
	win.attach(black_ring);
	win.attach(red_ring);

	win.wait_for_button(); // display!
}
