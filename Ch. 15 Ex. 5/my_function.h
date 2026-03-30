#ifndef MY_FUNCTION_H
#define MY_FUNCTION_H

#include "Graph.h"

namespace Graph_lib {

typedef double (*Func)(double);

class My_function : public Shape {
public:
	My_function();

	Func get_func() const { return _func; }
	void set_func(Func f) { _func = f; }

	Point get_origin() const { return point(0); }
	void set_origin(Point p) { set_point(0, p); }

	int get_precision() const { return _precision; }
	void set_precision(int i) { _precision = i; }

	double get_range_min() const { return _range_min; }
	void set_range_min(double d) { _range_min = d; }

	double get_range_max() const { return _range_max; }
	void set_range_max(double d) { _range_max = d; }

	double get_xscale() const { return _xscale; }
	void set_xscale(double d) { _xscale = d; }

	double get_yscale() const { return _yscale; }
	void set_yscale(double d) { _yscale = d; }

protected:
	virtual void draw_lines() const;

private:
	Func _func;
	int _precision;
	double _range_min;
	double _range_max;
	double _xscale;
	double _yscale;
};

}

#endif
