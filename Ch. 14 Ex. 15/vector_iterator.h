#ifndef VECTOR_ITERATOR_H
#define VECTOR_ITERATOR_H

#include "iterator.h"
#include <vector>

class Vector_iterator : public Iterator {
public:
	Vector_iterator(std::vector<double>& v) : vec(v), i(0) { }
	virtual double* next();
private:
	std::vector<double>& vec;
	int i;
};

#endif
