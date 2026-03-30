#define _USE_MATH_DEFINES

#include "right_triangle.h"

using namespace Graph_lib;
using namespace std;

Right_triangle::Right_triangle() : a(0), b(0), angle(0.0) {
	add(Point());
}

Right_triangle::Right_triangle(Point A, int a, int b, double angle) :
	a(a), b(b), angle(angle) {
	add(A);
}

void Right_triangle::draw_lines() const {
	if (!color().visibility() && !fill_color().visibility()) return;

	double angle_rad = angle/180*M_PI;
	double theta = atan((double)a/b);
	double c = sqrt(pow((double)a,2.0)+pow((double)b,2.0));
	pair<double,double> A(point(0).x, point(0).y);
	pair<double,double> B(cos(theta+angle_rad)*c+A.first, -sin(theta+angle_rad)*c+A.second);
	pair<double,double> C(cos(angle_rad)*b+A.first, -sin(angle_rad)*b+A.second);

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_begin_polygon();
		fl_vertex(A.first, A.second);
		fl_vertex(B.first, B.second);
		fl_vertex(C.first, C.second);
		fl_end_polygon();
	}

	if (color().visibility()) {
		fl_color(color().as_int());

		fl_begin_loop();
		fl_vertex(A.first, A.second);
		fl_vertex(B.first, B.second);
		fl_vertex(C.first, C.second);
		fl_end_loop();
	}
}
