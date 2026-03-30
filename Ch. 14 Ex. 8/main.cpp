#include "Simple_window.h"
#include "Graph.h"
#include "octagon.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 600, "Ch. 14 Ex. 8");

	Octagon oct(Point(300, 300), 275);
	oct.set_color(Color::blue);
	oct.set_fill_color(Color::white);
	oct.set_style(Line_style::solid);

	win.attach(oct);

	win.wait_for_button(); // display!

	oct.set_radius(200);

	win.wait_for_button(); // display!

	// oct.move(50, 50);
	oct.set_center(Point(350,350));

	win.wait_for_button(); // display!
}
