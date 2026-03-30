#define _USE_MATH_DEFINES

#include "star.h"
#include <cmath>

using namespace std;
using namespace Graph_lib;

void intersection(Point p1, Point p2, Point p3, Point p4, double& xi, double& yi, bool& parallel);

Star::Star() : points(0), density(0), radius(0) {
	add(Point());
}

Star::Star(Point center, int points, int density, int radius) :
	points(points), density(density), radius(radius) {
	add(center);
}

void Star::draw_lines() const {
	if (!color().visibility() && !fill_color().visibility()) return;

	const double interior_angle = 2*M_PI / points;
	double angle = 0.0;
	Point center = point(0);

	// exterior points of the star (edges)
	Point* pts_ext = new Point[points];
	angle = M_PI_2;
	for (int i = 0; i < points; ++i) {
		pts_ext[i].x = cos(angle)*radius + center.x;
		pts_ext[i].y = -sin(angle)*radius + center.y;
		angle += interior_angle;
	}

	// interior points of the star (intersections)
	Point* pts_int = new Point[points];
	double xi = 0.0; // x intersection
	double yi = 0.0; // y intersection
	bool parallel = false;
	intersection(pts_ext[0], pts_ext[density],
				 pts_ext[1], pts_ext[points-density],
				 xi, yi, parallel);
	double mini_radius = sqrt(pow(center.x-xi, 2.0) + pow(center.y-yi, 2.0));
	angle = M_PI_2 + interior_angle/2;
	for (int i = 0; i < points; ++i) {
		pts_int[i].x = cos(angle)*mini_radius + center.x;
		pts_int[i].y = -sin(angle)*mini_radius + center.y;
		angle += interior_angle;
	}

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_begin_polygon();
		for (int i = 0; i < points; ++i) {
			fl_vertex(pts_ext[i].x, pts_ext[i].y);
			fl_vertex(pts_int[i].x, pts_int[i].y);
		}
		fl_end_polygon();
	}

	if (color().visibility()) {
		fl_color(color().as_int());

		fl_begin_loop();
		for (int i = 0; i < points; ++i) {
			fl_vertex(pts_ext[i].x, pts_ext[i].y);
			fl_vertex(pts_int[i].x, pts_int[i].y);
		}
		fl_end_loop();
	}

	delete[] pts_ext;
	delete[] pts_int;
}

/**
 * Computes the intersection between two lines. The calculated point is approximate,
 * since integers are used. If you need a more precise result, use doubles
 * everywhere.
 * (c) 2007 Alexander Hristov. Use Freely (LGPL license). http://www.ahristov.com
 */
void intersection(Point p1, Point p2, Point p3, Point p4, double& xi, double& yi, bool& parallel) {
	double x1 = p1.x;
	double y1 = p1.y;
	double x2 = p2.x;
	double y2 = p2.y;
	double x3 = p3.x;
	double y3 = p3.y;
	double x4 = p4.x;
	double y4 = p4.y;

	double d = (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);

	if (d == 0.0) {
		xi = 0.0;
		yi = 0.0;
		parallel = true;
	}
	else {
		xi = ((x3-x4)*(x1*y2-y1*x2) - (x1-x2)*(x3*y4-y3*x4)) / d;
		yi = ((y3-y4)*(x1*y2-y1*x2) - (y1-y2)*(x3*y4-y3*x4)) / d;
		parallel = false;
	}
}
