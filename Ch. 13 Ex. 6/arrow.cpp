#define _USE_MATH_DEFINES

#include "arrow.h"
#include <cmath>

using namespace Graph_lib;

void Arrow::draw_lines() const {
	typedef Point Vector;

	if (!color().visibility()) return;

	Shape::draw_lines();

	Point p1 = point(0);
	Point p2 = point(1);
	Vector v(p2.x-p1.x, p2.y-p1.y);
	double v_length = sqrt(pow((double)v.x, 2.0) + pow((double)v.y, 2.0));
	double angle = acos(v.x / v_length); // in radians
	if (v.y > 0) angle = 2*M_PI - angle;
	angle = (angle / M_PI) * 180.0; // to degrees

	fl_translate(p2.x, p2.y);
	fl_rotate(angle);

	fl_begin_polygon();
	fl_vertex(0, 0);
	fl_vertex(-5, -5);
	fl_vertex(-5, 5);
	fl_end_polygon();

	fl_rotate(-angle);
	fl_translate(-p2.x, -p2.y);
}
