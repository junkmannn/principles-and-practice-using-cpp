#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 12 Ex. 5");

	Graph_lib::Rectangle rect(Point(75,75), 175, 100);
	rect.set_style(Line_style(Line_style::solid, 15));
	win.attach(rect);

	win.wait_for_button(); // display!
}
