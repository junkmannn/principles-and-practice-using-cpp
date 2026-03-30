#include "my_function.h"

using namespace Graph_lib;

My_function::My_function() :
	_func(nullptr), _precision(0), _range_min(0.0), _range_max(0.0), _xscale(0.0), _yscale(0.0) {
	add(Point()); // origin
}

void My_function::draw_lines() const {
	if (!color().visibility()) return;

	double interval = (_range_max-_range_min) / _precision;
	double x = _range_min;
	Point origin = get_origin();
	Open_polyline curve;

	for (int i = 0; i <= _precision; ++i) {
		Point p;
		p.x = origin.x + x*_xscale;
		p.y = origin.y - _func(x)*_yscale;
		curve.add(p);
		x += interval;
	}

	curve.set_color(color());
	curve.draw();
}
