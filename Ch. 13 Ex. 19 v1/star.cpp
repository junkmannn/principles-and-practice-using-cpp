#define _USE_MATH_DEFINES

#include "star.h"
#include <cmath>

using namespace Graph_lib;

Star::Star() : points(0), density(0), radius(0) {
	add(Point());
}

Star::Star(Point center, int points, int density, int radius) :
	points(points), density(density), radius(radius) {
	add(center);
}

void Star::draw_lines() const {
	if (!color().visibility()) return;

	fl_color(color().as_int());

	const double interior_angle = 2*M_PI / points;
	Point center = point(0);
	Point* pts = new Point[points];

	for (int i = 0; i < points; ++i) {
		pts[i].x = cos(M_PI_2+i*interior_angle)*radius + center.x;
		pts[i].y = -sin(M_PI_2+i*interior_angle)*radius + center.y;
	}

	int i = 0;
	int i2 = density;
	int i3 = points - density;
	for (; i < density; ++i) {
		fl_line(pts[i].x, pts[i].y, pts[i2].x, pts[i2].y);
		fl_line(pts[i].x, pts[i].y, pts[i3].x, pts[i3].y);
		++i2;
		++i3;
	}
	for (; i < points-density; ++i) {
		fl_line(pts[i].x, pts[i].y, pts[i2].x, pts[i2].y);
		++i2;
	}

	delete[] pts;
}
