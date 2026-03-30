#include "textbox.h"
#include "box.h"

using namespace std;
using namespace Graph_lib;

void Textbox::draw_lines() const {
	if (!color().visibility() && !fill_color().visibility()) return;

	Point xy = point(0);
	int x = xy.x;
	int y = xy.y;

	int text_width = 0;
	int text_height = 0;
	fl_measure(text.c_str(), text_width, text_height);

	int h_padding = 5; // left and right padding
	int v_padding = 3; // top and bottom padding
	int width = text_width + 2*h_padding; // box width
	int height = text_height + 2*v_padding; // box height

	Box box(xy, width, height, 0.25);
	box.set_color(color());
	box.set_fill_color(fill_color());
	box.draw();

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_draw(text.c_str(), x+h_padding, y-fl_descent()+fl_height()+v_padding);
	}
}
