#include "list_iterator.h"

double* List_iterator::next() {
	if (it != end) {
		double* d = &(*it);
		++it;
		return d;
	}
	else {
		return nullptr;
	}
}
