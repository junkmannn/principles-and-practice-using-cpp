#define _USE_MATH_DEFINES

#include "octagon.h"
#include <cmath>

using namespace Graph_lib;

Octagon::Octagon() : radius(0) {
	add(Point());
}

Octagon::Octagon(Point center, int radius) : radius(radius) {
	add(center);
}

void Octagon::draw_lines() const {
	Point center = point(0);

	const double interior_angle = 2*M_PI / 8;
	double angle = M_PI_2;

	Closed_polyline octagon;
	octagon.set_color(color());
	octagon.set_fill_color(fill_color());
	octagon.set_style(style());
	for (int i = 0; i < 8; ++i) {
		Point p(cos(angle)*radius+center.x, -sin(angle)*radius+center.y);
		octagon.add(p);
		angle += interior_angle;
	}
	octagon.draw();
}
