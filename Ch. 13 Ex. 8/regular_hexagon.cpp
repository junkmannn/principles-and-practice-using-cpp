#include "regular_hexagon.h"

using namespace Graph_lib;

void Regular_hexagon::draw_lines() const {
	if (!color().visibility() && !fill_color().visibility()) return;

	int x = point(0).x;
	int y = point(0).y;
	double sl = 0.5 * radius;
	double ll = sl * sqrt(3);

	Point a(x+ll, y-sl);
	Point b(x, y-radius);
	Point c(x-ll, y-sl);
	Point d(x-ll, y+sl);
	Point e(x, y+radius);
	Point f(x+ll, y+sl);

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_begin_polygon();
		fl_vertex(a.x, a.y);
		fl_vertex(b.x, b.y);
		fl_vertex(c.x, c.y);
		fl_vertex(d.x, d.y);
		fl_vertex(e.x, e.y);
		fl_vertex(f.x, f.y);
		fl_end_polygon();
	}

	if (color().visibility()) {
		fl_color(color().as_int());

		fl_begin_loop();
		fl_vertex(a.x, a.y);
		fl_vertex(b.x, b.y);
		fl_vertex(c.x, c.y);
		fl_vertex(d.x, d.y);
		fl_vertex(e.x, e.y);
		fl_vertex(f.x, f.y);
		fl_end_loop();
	}
}
