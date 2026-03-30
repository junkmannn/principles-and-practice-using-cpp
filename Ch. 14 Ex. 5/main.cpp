#include "Simple_window.h"
#include "Graph.h"
#include "striped_rectangle.h"

using namespace std;
using namespace Graph_lib;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 14 Ex. 5");

	Striped_rectangle sr(Point(100,100), 100, 101);
	sr.set_color(Color::red);
	sr.set_fill_color(Color::blue);
	win.attach(sr);

	Striped_rectangle sr2(Point(250,100), 100, 100);
	sr2.set_color(Color::cyan);
	sr2.set_fill_color(Color::white);
	win.attach(sr2);

	win.wait_for_button(); // display!
}
