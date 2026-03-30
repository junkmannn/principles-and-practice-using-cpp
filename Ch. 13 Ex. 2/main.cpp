#include "Simple_window.h"
#include "Graph.h"
#include "box.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 1000, 1000, "Ch. 13 Ex. 2");

	Box box(Point(10,10), 543, 127, 0.05);
	box.set_color(Color::black);
	box.set_fill_color(Color::white);

	win.attach(box);

	win.wait_for_button(); // display!

	box.set_height(80);

	win.wait_for_button(); // display!

	box.set_width(750);

	win.wait_for_button(); // display!

	box.set_height(800);

	win.wait_for_button(); // display!
}
