#include "Simple_window.h"
#include "Graph.h"
#include <string>

using namespace std;
using namespace Graph_lib;

typedef Graph_lib::Rectangle Fl_Rectangle;

int main() {
	Simple_window win(Point(100, 100), 600, 400, "Ch. 13 Ex. 13");

	const int lines = 16;
	const int columns = 16;
	Fl_Rectangle* colors[lines][columns];
	for (int i = 0; i < lines; ++i) {
		for (int j = 0; j < columns; ++j) {
			Fl_Rectangle* color = new Fl_Rectangle(Point(i*20,j*20), 20, 20);
			color->set_fill_color(Color(i*16+j));
			color->set_color(Color::invisible);
			colors[i][j] = color;
			win.attach(*color);
		}
	}

	win.wait_for_button(); // display!
}
