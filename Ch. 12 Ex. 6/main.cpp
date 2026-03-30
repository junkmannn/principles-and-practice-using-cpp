#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 12 Ex. 6");
	// shape that does not fit the window
	Graph_lib::Rectangle rect(Point(75,75), 800, 800);
	win.attach(rect);

	// window that does not fit the screen
	win.size(3000, 3000);

	win.wait_for_button(); // display!
}
