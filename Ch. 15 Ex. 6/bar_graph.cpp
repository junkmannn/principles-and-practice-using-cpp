#include "bar_graph.h"

using namespace Graph_lib;

Bar_graph::Bar_graph() :
	_data(nullptr), _bar_width(0), _bar_spacing(0), _bar_scale(0.0) {
	add(Point());
}

void Bar_graph::draw_lines() const {
	if (_data == nullptr) return;

	fl_color(fill_color().as_int());

	Point graph_origin = get_graph_origin();
	int xpos = graph_origin.x + _bar_spacing;
	int num_data = _data->size();

	for (int i = 0; i < num_data; ++i) {
		int bar_height = int(_data->at(i)*_bar_scale);
		fl_rectf(xpos, graph_origin.y-bar_height, _bar_width, bar_height);
		xpos += _bar_spacing + _bar_width;
	}
}
