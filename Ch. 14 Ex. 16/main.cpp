#include "Simple_window.h"
#include "Graph.h"
#include "controller_derived1.h"
#include "controller_derived2.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100,100), 600, 400, "Ch. 14 Ex. 16");

	Controller_derived1 cd1;
	cd1.off();
	cd1.set_level(3);
	cd1.show();

	Line l(Point(0,0), Point(600,400));
	win.attach(l);
	Controller_derived2 cd2;
	cd2.set_line(l);

	win.wait_for_button(); // display!

	cd2.on();

	win.wait_for_button();

	cd2.off();

	win.wait_for_button();

	cd2.set_level(0xFF007F);

	win.wait_for_button();

}
