#ifndef FROWNY_HAT_H
#define FROWNY_HAT_H

#include "frowny.h"

namespace Graph_lib {

class Frowny_hat : public Frowny {
public:
	Frowny_hat(Point center, int radius);

protected:
	virtual void draw_lines() const;

private:

};

}

#endif
