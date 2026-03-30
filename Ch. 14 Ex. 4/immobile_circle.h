#ifndef IMMOBILE_CIRCLE_H
#define IMMOBILE_CIRCLE_H

#include "Graph.h"

namespace Graph_lib {

class Immobile_circle : public Circle {
public:
	Immobile_circle(Point center, int radius);

	virtual void move(int dx, int dy);

private:

};

}

#endif
