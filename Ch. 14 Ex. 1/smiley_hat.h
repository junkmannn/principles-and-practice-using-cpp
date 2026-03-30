#ifndef SMILEY_HAT_H
#define SMILEY_HAT_H

#include "smiley.h"

namespace Graph_lib {

class Smiley_hat : public Smiley {
public:
	Smiley_hat(Point center, int radius);

protected:
	virtual void draw_lines() const;

private:

};

}

#endif
