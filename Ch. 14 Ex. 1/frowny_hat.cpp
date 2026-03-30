#include "frowny_hat.h"

namespace Graph_lib {

Frowny_hat::Frowny_hat(Point p, int rr) : Frowny(p, rr) {

}

void Frowny_hat::draw_lines() const {
	Frowny::draw_lines();

	Point xy = point(0);
	int x = xy.x;
	int y = xy.y;
	int r = radius();

	Closed_polyline hat;
	hat.set_color(color());
	hat.set_fill_color(fill_color());
	hat.set_style(style());
	hat.add(Point(x-0.25*r, y+0.30*r));
	hat.add(Point(x+2*r+0.25*r, y+0.30*r));
	hat.add(Point(x+r, y-0.30*r));
	hat.draw();
}

};
