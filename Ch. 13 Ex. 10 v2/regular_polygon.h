#ifndef REGULAR_HEXAGON_H
#define REGULAR_HEXAGON_H

#include "Graph.h"

namespace Graph_lib {

class Regular_polygon : public Shape {
public:
	Regular_polygon();
	Regular_polygon(Point center, int radius, int sides);

	Point get_center() const { return point(0); }
	void set_center(Point p) { set_point(0, p); }

	int get_radius() const { return radius; }
	void set_radius(int i) { radius = i; }

	int get_sides() const { return sides; }
	void set_sides(int i) { sides = i; }

protected:
	virtual void draw_lines() const;

private:
	int radius;
	int sides;
};

}

#endif
