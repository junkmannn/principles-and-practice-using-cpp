#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include "iterator.h"
#include <list>

class List_iterator : public Iterator {
public:
	List_iterator(std::list<double>& l) : it(l.begin()), end(l.end()) { }
	virtual double* next();
private:
	std::list<double>::iterator it;
	std::list<double>::iterator end;
};

#endif
