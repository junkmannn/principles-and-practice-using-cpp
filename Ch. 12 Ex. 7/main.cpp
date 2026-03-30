#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 12 Ex. 7");

	// chimney
	// -------------------------------------------
	Graph_lib::Rectangle chimney(Point(332, 145), 30, 50);
	chimney.set_fill_color(Color::black);
	chimney.set_color(Color::white);
	win.attach(chimney);
	// -------------------------------------------

	// roof
	// -------------------------------------------
	Graph_lib::Polygon roof;
	roof.add(Point(300, 125));
	roof.add(Point(225, 200));
	roof.add(Point(375, 200));
	roof.set_fill_color(Color::black);
	roof.set_color(Color::white);
	win.attach(roof);
	// -------------------------------------------

	// frame
	// -------------------------------------------
	Graph_lib::Rectangle frame(Point(225,200), 150, 125);
	frame.set_fill_color(Color::black);
	frame.set_color(Color::white);
	win.attach(frame);
	// -------------------------------------------

	// door
	// -------------------------------------------
	Graph_lib::Rectangle door(Point(285,275), 30, 50);
	door.set_color(Color::white);
	win.attach(door);
	// -------------------------------------------

	// windows
	// -------------------------------------------
	Graph_lib::Rectangle window1(Point(240,225), 30, 30);
	window1.set_color(Color::white);
	win.attach(window1);
	Line window1line1(Point(255, 225), Point(255, 254));
	window1line1.set_color(Color::white);
	win.attach(window1line1);
	Line window1line2(Point(240, 240), Point(269, 240));
	window1line2.set_color(Color::white);
	win.attach(window1line2);

	Graph_lib::Rectangle window2(Point(330,225), 30, 30);
	window2.set_color(Color::white);
	win.attach(window2);
	Line window2line1(Point(345, 225), Point(345, 254));
	window2line1.set_color(Color::white);
	win.attach(window2line1);
	Line window2line2(Point(330, 240), Point(359, 240));
	window2line2.set_color(Color::white);
	win.attach(window2line2);
	// -------------------------------------------

	win.wait_for_button(); // display!
}
