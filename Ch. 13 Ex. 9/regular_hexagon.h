#ifndef REGULAR_HEXAGON_H
#define REGULAR_HEXAGON_H

#include "Graph.h"

namespace Graph_lib {

class Regular_hexagon : public Shape {
public:
	Regular_hexagon() : radius(0) { add(Point()); }
	Regular_hexagon(Point center, int radius) :  radius(radius) { add(center); }

	Point get_center() const { return point(0); }
	void set_center(Point p) { set_point(0, p); }

	int get_radius() const { return radius; }
	void set_radius(int i) { radius = i; }

protected:
	virtual void draw_lines() const;

private:
	int radius;
};

}

#endif
