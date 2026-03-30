#include "smiley_hat.h"

namespace Graph_lib {

Smiley_hat::Smiley_hat(Point p, int rr) : Smiley(p, rr) {

}

void Smiley_hat::draw_lines() const {
	Smiley::draw_lines();

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
	hat.add(Point(x+2*r+0.25*r, y-0.15*r));
	hat.add(Point(x+2*r-0.40*r, y-0.15*r));
	hat.add(Point(x+2*r-0.40*r, y-0.60*r));
	hat.add(Point(x+0.40*r, y-0.60*r));
	hat.add(Point(x+0.40*r, y-0.15*r));
	hat.add(Point(x-0.25*r, y-0.15*r));
	hat.draw();
}

};
