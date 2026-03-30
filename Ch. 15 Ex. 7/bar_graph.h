#ifndef BAR_GRAPH_H
#define BAR_GRAPH_H

#include "Graph.h"
#include <vector>
#include <string>

namespace Graph_lib {

class Bar_graph : public Shape {
public:
	Bar_graph();

	Point get_graph_origin() const { return point(0); }
	void set_graph_origin(Point p) { set_point(0, p); }

	void set_data(const std::vector<double>* v) { _data = v; }

	void set_data_labels(const std::vector<std::string>* v) { _data_labels = v; }

	void set_data_colors(const std::vector<Color>* v) { _data_colors = v; }

	bool display_data_values() const { return _display_data_values; }
	void display_data_values(bool b) { _display_data_values = b; }

	int get_bar_width() const { return _bar_width; }
	void set_bar_width(int i) { _bar_width = i; }

	int get_bar_spacing() const { return _bar_spacing; }
	void set_bar_spacing(int i) { _bar_spacing = i; }

	double get_bar_scale() const { return _bar_scale; }
	void set_bar_scale(double d) { _bar_scale = d; }

protected:
	virtual void draw_lines() const;

private:
	const std::vector<double>* _data;
	const std::vector<std::string>* _data_labels;
	const std::vector<Color>* _data_colors;
	bool _display_data_values;
	int _bar_width;
	int _bar_spacing;
	double _bar_scale;
};

}

#endif
