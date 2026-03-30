#ifndef FROWNY_H
#define FROWNY_H

#include "Graph.h"

namespace Graph_lib {

class Frowny : public Circle {
public:
	Frowny(Point center, int radius);

protected:
	virtual void draw_lines() const;

private:

};

}

#endif
