#include "vector_iterator.h"

double* Vector_iterator::next() {
	if (i < vec.size()) {
		double* d = &vec[i];
		++i;
		return d;
	}
	else {
		return nullptr;
	}
}
