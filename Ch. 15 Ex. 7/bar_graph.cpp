#include "bar_graph.h"
#include <sstream>

using namespace Graph_lib;
using namespace std;

Bar_graph::Bar_graph() :
	_data(nullptr), _data_labels(nullptr), _data_colors(nullptr),
	_display_data_values(false), _bar_width(0), _bar_spacing(0), _bar_scale(0.0) {
	add(Point());
}

void Bar_graph::draw_lines() const {
	if (_data == nullptr) return;

	Point graph_origin = get_graph_origin();
	int xpos = graph_origin.x + _bar_spacing;
	int num_data = _data->size();

	for (int i = 0; i < num_data; ++i) {
		int bar_height = int(_data->at(i)*_bar_scale);

		if (_data_colors != nullptr)
			fl_color(_data_colors->at(i).as_int());
		else
			fl_color(fill_color().as_int());
		fl_rectf(xpos, graph_origin.y-bar_height, _bar_width, bar_height);

		fl_color(color().as_int());

		if (_display_data_values) {
			ostringstream oss;
			oss << _data->at(i);
			string s = oss.str();
			const char* c = s.c_str();

			int text_width = 0;
			int text_height = 0;
			fl_measure(c, text_width, text_height);

			int text_xpos = (_bar_width-text_width)/2 + xpos;
			int text_ypos = graph_origin.y - bar_height - 20;
			fl_draw(c, text_xpos, text_ypos);
		}

		if (_data_labels != nullptr) {
			const char* c = _data_labels->at(i).c_str();

			int text_width = 0;
			int text_height = 0;
			fl_measure(c, text_width, text_height);

			int text_xpos = (_bar_width-text_width)/2 + xpos;
			int text_ypos = graph_origin.y + 20;
			fl_draw(c, text_xpos, text_ypos);
		}

		xpos += _bar_spacing + _bar_width;
	}
}
