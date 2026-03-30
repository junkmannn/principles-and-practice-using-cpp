#ifndef STRIPED_CIRCLE
#define STRIPED_CIRCLE

#include "Graph.h"

namespace Graph_lib {

class Striped_circle : public Circle {
public:
	Striped_circle(Point center, int radius);

protected:
	virtual void draw_lines() const;

private:

};

}

#endif
