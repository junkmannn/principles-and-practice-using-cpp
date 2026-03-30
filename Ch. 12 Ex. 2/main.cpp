#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 12 Ex. 2");

	Graph_lib::Rectangle rect(Point(25, 25), 100, 30);

	Text text(Point(50, 45), "Howdy!");

	win.attach(rect);
	win.attach(text);

	win.wait_for_button(); // display!
}
