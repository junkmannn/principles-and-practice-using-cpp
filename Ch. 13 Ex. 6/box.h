#ifndef BOX_H
#define BOX_H

#include "Graph.h"

namespace Graph_lib {

class Box : public Shape {
public:
	Box();
	Box(Point pos, int width, int height, double edge_percent);

	Point get_pos() const { return point(0); }
	void set_pos(Point p) { set_point(0, p); }

	int get_width() const { return width; }
	void set_width(int w) { width = w; }

	int get_height() const { return height; }
	void set_height(int h) { height = h; }

	double get_edge_percent() const { return edge_percent; }
	void set_edge_percent(double d) { edge_percent = d; }

protected:
	virtual void draw_lines() const;

private:
	int width;
	int height;
	double edge_percent;
};

}

#endif
