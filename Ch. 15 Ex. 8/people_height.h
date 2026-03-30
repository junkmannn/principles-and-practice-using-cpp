#ifndef PEOPLE_HEIGHT_H
#define PEOPLE_HEIGHT_H

#include "graphable.h"

class People_height : public Graphable {
public:
	People_height() : _height(0), _num_people(0) { }
	People_height(int height, int num_people) :
		_height(height), _num_people(num_people) { }

	int get_height() const { return _height; }
	void set_height(int i) { _height = i; }

	int get_num_people() const { return _num_people; }
	void set_num_people(int i) { _num_people = i; }

	virtual double x() const { return (double)_height; }
	virtual double y() const { return (double)_num_people; }

private:
	int _height;
	int _num_people;
};

#endif
