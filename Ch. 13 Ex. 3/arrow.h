#ifndef ARROW_H
#define ARROW_H

#include "Graph.h"

namespace Graph_lib {

class Arrow : public Shape {
public:
	Arrow() { add(Point()); add(Point()); }
	Arrow(Point p1, Point p2) { add(p1); add(p2); }

	Point get_p1() { return point(0); }
	void set_p1(Point p) { set_point(0, p); }

	Point get_p2() { return point(1); }
	void set_p2(Point p) { set_point(1, p); }

protected:
	virtual void draw_lines() const;

private:

};

}

#endif
