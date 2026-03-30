#ifndef STAR_H
#define STAR_H

#include "Graph.h"

namespace Graph_lib {

class Star : public Shape {
public:
	Star();
	Star(Point center, int points, int density, int radius);

	Point get_center() const { return point(0); }
	void set_center(Point p) { set_point(0, p); }

	int get_points() const { return points; }
	void set_points(int i) { points = i; }

	int get_density() const { return density; }
	void set_density(int i) { density = i; }

	int get_radius() const { return radius; }
	void set_radius(int i) { radius = i; }

protected:
	virtual void draw_lines() const;

private:
	int points;
	int density;
	int radius;
};

}

#endif
