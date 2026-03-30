#include "box.h"

using namespace Graph_lib;

Box::Box() : width(0), height(0), edge_percent(0.0) {
	add(Point());
}

Box::Box(Point pos, int width, int height, double edge_percent) :
	width(width), height(height), edge_percent(edge_percent) {
	add(pos);
}

void Box::draw_lines() const {
	if (!color().visibility() && !fill_color().visibility()) return;

	int short_side = (height < width) ? height : width;
	int edge_radius = short_side * edge_percent;
	int h_line_length = width - 2*edge_radius;
	int v_line_length = height - 2*edge_radius;
	int x = point(0).x;
	int y = point(0).y;

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		fl_rectf(x+edge_radius, y, h_line_length, height);
		fl_rectf(x, y+edge_radius, width, v_line_length);
		fl_pie(x, y, 2*edge_radius, 2*edge_radius, 90.0, 180.0);
		fl_pie(x+h_line_length, y, 2*edge_radius, 2*edge_radius, 0.0, 90.0);
		fl_pie(x+h_line_length, y+v_line_length, 2*edge_radius, 2*edge_radius, 270.0, 360.0);
		fl_pie(x, y+v_line_length, 2*edge_radius, 2*edge_radius, 180.0, 270.0);
	}

	if (color().visibility()) {
		fl_color(color().as_int());

		fl_arc(x, y, 2*edge_radius, 2*edge_radius, 90.0, 180.0);
		fl_line(x+edge_radius, y, x+edge_radius+h_line_length, y);
		fl_arc(x+h_line_length, y, 2*edge_radius, 2*edge_radius, 0.0, 90.0);
		fl_line(x+width, y+edge_radius, x+width, y+edge_radius+v_line_length);
		fl_arc(x+h_line_length, y+v_line_length, 2*edge_radius, 2*edge_radius, 270.0, 360.0);
		fl_line(x+edge_radius+h_line_length, y+height, x+edge_radius, y+height);
		fl_arc(x, y+v_line_length, 2*edge_radius, 2*edge_radius, 180.0, 270.0);
		fl_line(x, y+edge_radius+v_line_length, x, y+edge_radius);
	}
}
