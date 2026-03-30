#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 12 Ex. 1");

	// Rectangle as a Rectangle
	Graph_lib::Rectangle rect_rect(Point(25, 25), 200, 100);
	rect_rect.set_color(Color::blue);

	// Rectangle as a Polygon
	Graph_lib::Polygon poly_rect;
	poly_rect.add(Point(25, 150));
	poly_rect.add(Point(225, 150));
	poly_rect.add(Point(225, 250));
	poly_rect.add(Point(25, 250));
	poly_rect.set_color(Color::red);

	win.attach(rect_rect);
	win.attach(poly_rect);

	win.wait_for_button(); // display!
}
