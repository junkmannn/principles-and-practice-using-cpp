#ifndef STRIPED_RECTANGLE
#define STRIPED_RECTANGLE

#include "Graph.h"

namespace Graph_lib {

class Striped_rectangle : public Rectangle {
public:
	Striped_rectangle(Point tl, int width, int height);

protected:
	virtual void draw_lines() const;

private:

};

}

#endif
