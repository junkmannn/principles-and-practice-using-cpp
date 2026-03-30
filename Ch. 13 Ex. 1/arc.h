#ifndef ARC_H
#define ARC_H

#include "Graph.h"

namespace Graph_lib {

class Arc : public Shape {
public:
	Arc();
	Arc(Point center, int semi_major_axis, int semi_minor_axis, double angle_start, double angle_end);

	Point get_center() const { return point(0); }
	void set_center(Point p) { set_point(0, p); }

	int get_semi_major_axis() const { return semi_major_axis; }
	void set_semi_major_axis(int i) { semi_major_axis = i; }

	int get_semi_minor_axis() const { return semi_minor_axis; }
	void set_semi_minor_axis(int i) { semi_minor_axis = i; }

	double get_angle_start() const { return angle_start; }
	void set_angle_start(double d) { angle_start = d; }

	double get_angle_end() const { return angle_end; }
	void set_angle_end(double d) { angle_end = d; }

protected:
	virtual void draw_lines() const;

private:
	int semi_major_axis;
	int semi_minor_axis;
	double angle_start;
	double angle_end;
};

}

#endif
