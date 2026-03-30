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

	Point cxy = point(0); // center
	int cx = cxy.x;
	int cy = cxy.y;
	const double interior_angle = 2*M_PI / sides;
	double angle = M_PI_2;
	pair<double,double>* points = new pair<double,double>[sides];

	// very top point (common to all polygons)
	points[0] = make_pair(cx, -radius+cy);

	// all polygons can at least do y-axis symmetry
	int ya_sym = sides - 2;

	if (sides % 2 == 0) {
		// very bottom point (common to polygons where its side count is divisible by 2)
		points[sides/2] = make_pair(cx, radius+cy);

		int xa_sym = sides/2 - 2;
		int quarter = 0; // points in the quadrant II

		if (sides % 4 == 0) {
			// very left and very right point
			// (common to polygons where its side count is divisible by 4)
			points[sides/4] = make_pair(-radius+cx, cy);
			points[3*sides/4] = make_pair(radius+cx, cy);

			quarter = (sides-4)/4 + 1;
		}
		else {
			quarter = (sides-2)/4 + 1;
		}

		for (int i = 1; i < quarter; ++i) {
			angle += interior_angle;

			double x = cos(angle)*radius;
			double y = -sin(angle)*radius;

			points[i] = make_pair(x+cx, y+cy);
			points[i+ya_sym] = make_pair(-x+cx, y+cy); // y-axis symmetry
			points[i+xa_sym] = make_pair(x+cx, -y+cy); // x-axis symmetry
			points[i+sides/2] = make_pair(-x+cx, -y+cy); // y-axis and x-axis symmetry

			ya_sym -= 2;
			xa_sym -= 2;
		}
	}
	else {
		int half = (sides-1)/2 + 1; // points in the quadrant II and III

		for (int i = 1; i < half; ++i) {
			angle += interior_angle;

			double x = cos(angle)*radius;
			double y = -sin(angle)*radius + cy; // includes cy translation

			points[i] = make_pair(x+cx, y);
			points[i+ya_sym] = make_pair(-x+cx, y); // y-axis symmetry

			ya_sym -= 2;
		}
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
