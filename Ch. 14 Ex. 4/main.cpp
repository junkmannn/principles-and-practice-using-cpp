#include "Simple_window.h"
#include "Graph.h"
#include "immobile_circle.h"

using namespace std;
using namespace Graph_lib;

void keep_window_open();

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 14 Ex. 4");

	Immobile_circle ic(Point(250,200), 175);
	ic.set_color(Color::black);
	ic.set_fill_color(Color::white);
	ic.set_style(Line_style::dash);
	// ic.move(25, 25); // doesn't work ofc

	win.attach(ic);

	win.wait_for_button();

	return 0;
}
