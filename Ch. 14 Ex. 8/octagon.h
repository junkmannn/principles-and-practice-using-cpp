#ifndef OCTAGON_H
#define OCTAGON_H

#include "Graph.h"

namespace Graph_lib {

class Octagon : public Shape {
public:
	Octagon();
	Octagon(Point center, int radius);

	Point get_center() const { return point(0); }
	void set_center(Point p) { set_point(0, p); }

	int get_radius() const { return radius; }
	void set_radius(int r) { radius = r; }

protected:
	virtual void draw_lines() const;

private:
	int radius;
};

}

#endif
