#include "arc.h"

using namespace Graph_lib;

Arc::Arc() : semi_major_axis(0), semi_minor_axis(0), angle_start(0.0), angle_end(0.0) {
	add(Point());
}

Arc::Arc(Point center, int semi_major_axis, int semi_minor_axis, double angle_start, double angle_end) :
	semi_major_axis(semi_major_axis), semi_minor_axis(semi_minor_axis),
	angle_start(angle_start), angle_end(angle_end) {
	add(center);
}

void Arc::draw_lines() const {
	Point center = point(0);

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());
		fl_pie(center.x-semi_major_axis, center.y-semi_minor_axis,
			   2*semi_major_axis, 2*semi_minor_axis,
			   angle_start, angle_end);
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(center.x-semi_major_axis, center.y-semi_minor_axis,
			   2*semi_major_axis, 2*semi_minor_axis,
			   angle_start, angle_end);
	}
}
