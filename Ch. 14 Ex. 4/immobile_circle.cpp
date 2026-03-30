#include "immobile_circle.h"

using namespace Graph_lib;

Immobile_circle::Immobile_circle(Point center, int radius) : Circle(center, radius) {

}

void Immobile_circle::move(int dx, int dy) {
	throw std::runtime_error("move undefined");
}
