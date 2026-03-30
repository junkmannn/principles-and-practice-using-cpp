#define _USE_MATH_DEFINES

#include "regular_polygon.h"
#include <cmath>

using namespace std;
using namespace Graph_lib;

Regular_polygon::Regular_polygon() : radius(0), sides(0) {
	add(Point());
}

Regular_polygon::Regular_polygon(Point center, int radius, int sides) :
	radius(radius), sides(sides) {
	add(center);
}

void Regular_polygon::draw_lines() const {
	if (!color().visibility() && !fill_color().visibility()) return;

	Point center = point(0);
	const double interior_angle = 2*M_PI / sides;
	double angle = M_PI_2;
	pair<double,double>* points = new pair<double,double>[sides];

	for (int i = 0; i < sides; ++i) {
		points[i].first = cos(angle)*radius + center.x; // x
		points[i].second = -sin(angle)*radius + center.y; // y
		angle += interior_angle;
	}

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_begin_polygon();
		for (int i = 0; i < sides; ++i) {
			fl_vertex(points[i].first, points[i].second);
		}
		fl_end_polygon();
	}

	if (color().visibility()) {
		fl_color(color().as_int());

		fl_begin_loop();
		for (int i = 0; i < sides; ++i) {
			fl_vertex(points[i].first, points[i].second);
		}
		fl_end_loop();
	}

	delete[] points;
}
