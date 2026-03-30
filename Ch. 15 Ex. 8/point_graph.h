#ifndef POINT_GRAPH_H
#define POINT_GRAPH_H

#include "Graph.h"
#include <vector>

namespace Graph_lib {

template<class T>
class Point_graph : public Shape {
public:
	Point_graph();

	Point get_origin() const { return point(0); }
	void set_origin(Point p) { set_point(0, p); }

	void set_data(const std::vector<T>* v) { _data = v; }

	double get_xrange_min() const { return _xrange_min; }
	void set_xrange_min(double d) { _xrange_min = d; }

	double get_xrange_max() const { return _xrange_max; }
	void set_xrange_max(double d) { _xrange_max = d; }

	void set_xrange(double min, double max)
		{ _xrange_min = min; _xrange_max = max; }

	double get_yrange_min() const { return _yrange_min; }
	void set_yrange_min(double d) { _yrange_min = d; }

	double get_yrange_max() const { return _yrange_max; }
	void set_yrange_max(double d) { _yrange_max = d; }

	void set_yrange(double min, double max)
		{ _yrange_min = min; _yrange_max = max; }

	double get_xscale() const { return _xscale; }
	void set_xscale(double d) { _xscale = d; }

	double get_yscale() const { return _yscale; }
	void set_yscale(double d) { _yscale = d; }

	double get_xstart() const { return _xstart; }
	void set_xstart(double d) { _xstart = d; }

	double get_ystart() const { return _ystart; }
	void set_ystart(double d) { _ystart = d; }

	int get_point_size() const { return _point_size; }
	void set_point_size(int i) { _point_size = i; }

protected:
	virtual void draw_lines() const;

private:
	const std::vector<T>* _data;
	double _xrange_min;
	double _xrange_max;
	double _yrange_min;
	double _yrange_max;
	double _xscale;
	double _yscale;
	double _xstart;
	double _ystart;
	int _point_size; // radius of the point
};

template<class T>
Point_graph<T>::Point_graph() :
	_data(nullptr), _xrange_min(0.0), _xrange_max(0.0), _yrange_min(0.0), _yrange_max(0.0),
	_xscale(0.0), _yscale(0.0), _xstart(0.0), _ystart(0.0) {
	static_assert(std::is_base_of<Graphable, T>::value,
		"type parameter of this class must derive from Graphable");
	add(Point()); // origin
}

template<class T>
void Point_graph<T>::draw_lines() const {
	if (_data == nullptr) return;

	fl_color(color().as_int());

	Point origin = get_origin();

	int xoffset = int(_xstart*_xscale);
	int yoffset = int(_ystart*_yscale);

	for (int i = 0, num_data = _data->size(); i < num_data; ++i) {
		const Graphable& xy = _data->at(i);

		if (xy.x() < _xrange_min || xy.x() > _xrange_max ||
			xy.y() < _yrange_min || xy.y() > _yrange_max)
			continue; // ignore data not in range

		int finalx = origin.x+int(xy.x()*_xscale)-xoffset;
		int finaly = origin.y-int(xy.y()*_yscale)+yoffset;

		fl_pie(finalx-_point_size, finaly+_point_size,
			   _point_size*2, _point_size*2,
			   0.0, 360.0);
	}
}

}

#endif
