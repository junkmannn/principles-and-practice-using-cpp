#include "frowny.h"
#include "arc.h"

using namespace Graph_lib;

Frowny::Frowny(Point center, int radius) : Circle(center, radius) {

}

void Frowny::draw_lines() const {
	Circle::draw_lines();

	Point center = this->center();
	int radius = this->radius();


	// draw mouth
	Arc mouth(Point(center.x, center.y+radius*0.45),
			  radius*0.65, radius*0.20,
			  0.0, 180.0);
	mouth.set_color(color());
	mouth.set_fill_color(Color::invisible);
	mouth.set_style(style());
	mouth.draw();


	// draw eyes
	int eye_dx = radius * 0.40;
	int eye_y = center.y - radius*0.30;
	int eye_radius = radius * 0.09;

	Circle left_eye(Point(center.x-eye_dx, eye_y), eye_radius);
	left_eye.set_color(color());
	left_eye.set_fill_color(Color::invisible);
	left_eye.set_style(style());
	left_eye.draw();

	Circle right_eye(Point(center.x+eye_dx, eye_y), eye_radius);
	right_eye.set_color(color());
	right_eye.set_fill_color(Color::invisible);
	right_eye.set_style(style());
	right_eye.draw();
}
