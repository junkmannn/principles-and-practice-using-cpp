#ifndef SMILEY_H
#define SMILEY_H

#include "Graph.h"

namespace Graph_lib {

class Smiley : public Circle {
public:
	Smiley(Point center, int radius);

protected:
	virtual void draw_lines() const;

private:

};

}

#endif
