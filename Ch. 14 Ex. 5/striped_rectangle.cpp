#include "striped_rectangle.h"

using namespace Graph_lib;

Striped_rectangle::Striped_rectangle(Point tl, int width, int height) :
	Rectangle(tl, width, height) {

}

void Striped_rectangle::draw_lines() const {
	Point xy = point(0);
	int x = xy.x;
	int y = xy.y;
	int w = width();
	int h = height();

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_rect(x, y, w, h);
	}

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		for (int i = 1; i < h-1; i+=2)
			fl_line(x+1, y+i, x+w-2, y+i);
	}
}
