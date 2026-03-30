#include "striped_circle.h"
#include <cmath>

using namespace Graph_lib;

Striped_circle::Striped_circle(Point center, int radius) : Circle(center, radius) {

}

void Striped_circle::draw_lines() const {
	Point center = this->center();
	int radius = this->radius();

	if (fill_color().visibility()) {
		fl_color(fill_color().as_int());

		double steps = 2.0/radius;
		double cur = 1.0 - steps/2.0;
		// double cur = steps;

		for (int i = radius-1; i > -radius+1; i-=2) {
			double x = sqrt(1-pow(cur,2))*radius; // = cos(asin(cur))*radius
			fl_line(center.x-x+1, center.y-i, center.x+x-1, center.y-i);
			cur -= steps;
		}

		/*
		for (int i = 2; i < radius; i+=2) {
			double x = sqrt(1-pow(cur,2))*radius; // = cos(asin(cur))*radius
			fl_line(center.x-x+1, center.y-i, center.x+x-1, center.y-i);
			fl_line(center.x-x+1, center.y+i-1, center.x+x-1, center.y+i-1);
			cur += steps;
		}
		*/
	}

	if (color().visibility()) {
		fl_color(color().as_int());
		// fl_arc(center.x-radius, center.y-radius, radius*2, radius*2, 0.0, 360.0);
		fl_circle(center.x, center.y, radius);
	}
}
