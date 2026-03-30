#include "Simple_window.h"
#include "Graph.h"
#include "regular_hexagon.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 9");

	int radius = 75;
	int radius2 = 0.5*radius*sqrt(3); // ll
	int radius3 = 0.5*radius; // sl

	Regular_hexagon rh(Point(100,200), radius);
	Regular_hexagon rh2(Point(100+2*radius2,200), radius);
	Regular_hexagon rh3(Point(100+4*radius2,200), radius);
	Regular_hexagon rh4(Point(100+6*radius2,200), radius);

	Regular_hexagon rh5(Point(100+1*radius2,200-radius3-radius), radius);
	Regular_hexagon rh6(Point(100+3*radius2,200-radius3-radius), radius);
	Regular_hexagon rh7(Point(100+5*radius2,200-radius3-radius), radius);

	Regular_hexagon rh8(Point(100+1*radius2,200+radius3+radius), radius);
	Regular_hexagon rh9(Point(100+3*radius2,200+radius3+radius), radius);
	Regular_hexagon rh10(Point(100+5*radius2,200+radius3+radius), radius);

	win.attach(rh);
	win.attach(rh2);
	win.attach(rh3);
	win.attach(rh4);
	win.attach(rh5);
	win.attach(rh6);
	win.attach(rh7);
	win.attach(rh8);
	win.attach(rh9);
	win.attach(rh10);

	win.wait_for_button(); // display!
}
