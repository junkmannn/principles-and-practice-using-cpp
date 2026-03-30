#include "Simple_window.h"
#include "Graph.h"
#include "striped_circle.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 800, 800, "Ch. 14 Ex. 6");

	Striped_circle sc(Point(400,400), 375);
	sc.set_color(Color::red);
	sc.set_fill_color(Color::blue);
	win.attach(sc);

	win.wait_for_button(); // display!
}
