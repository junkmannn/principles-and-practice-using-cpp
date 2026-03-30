#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Polygon Fl_Polygon;
typedef Graph_lib::Rectangle Fl_Rectangle;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 12 Ex. 11");

	Fl_Rectangle square(Point(100,100), 50, 50);

	Fl_Polygon poly;
	poly.add(Point(200, 200));
	poly.add(Point(250, 250));
	poly.add(Point(150, 250));

	win.attach(square);
	win.attach(poly);

	win.wait_for_button(); // display!
}
