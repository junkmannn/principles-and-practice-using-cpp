#ifndef CONTROLLER_DERIVED2_H
#define CONTROLLER_DERIVED2_H

#include "controller.h"
#include "Graph.h"

class Controller_derived2 : public Controller {
public:
	virtual void on();
	virtual void off();
	virtual void set_level(int i);
	virtual void show() const;

	Graph_lib::Line& get_line() const { return *line; }
	void set_line(Graph_lib::Line& l) { line = &l; }

protected:
	Graph_lib::Line* line;
};

#endif
