#ifndef BAR_GRAPH_H
#define BAR_GRAPH_H

#include "Graph.h"
#include <vector>

namespace Graph_lib {

class Bar_graph : public Shape {
public:
	Bar_graph();

	Point get_graph_origin() const { return point(0); }
	void set_graph_origin(Point p) { set_point(0, p); }

	void set_data(const std::vector<double>* v) { _data = v; }

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
	int _bar_width;
	int _bar_spacing;
	double _bar_scale;
};

}

#endif
