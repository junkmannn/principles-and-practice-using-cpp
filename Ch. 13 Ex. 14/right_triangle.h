#ifndef RIGHT_TRIANGLE_H
#define RIGHT_TRIANGLE_H

#include "Graph.h"

namespace Graph_lib {

class Right_triangle : public Shape {
public:
	// as seen here https://upload.wikimedia.org/wikipedia/commons/6/6f/Rtriangle.svg
	Right_triangle();
	Right_triangle(Point A, int a, int b, double angle);

	Point get_A() const { return point(0); }
	void set_A(Point p) { set_point(0, p); }

	int get_a() const { return a; }
	void set_a(int i) { a = i; }

	int get_b() const { return b; }
	void set_b(int i) { b = i; }

	double get_angle() const { return angle; }
	void set_angle(double d) { angle = d; }

protected:
	virtual void draw_lines() const;

private:
	int a;
	int b;
	double angle;
};

}

#endif
