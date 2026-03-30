#include "Simple_window.h"
#include "Graph.h"
#include "regular_hexagon.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 8");

	Regular_hexagon rh(Point(200,200), 100);
	rh.set_color(Color::red);
	rh.set_fill_color(Color::white);

	win.attach(rh);

	win.wait_for_button(); // display!
}
