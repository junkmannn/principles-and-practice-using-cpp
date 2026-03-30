#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "Graph.h"
#include <string>

namespace Graph_lib {

class Textbox : public Shape {
public:
	Textbox() { add(Point()); }
	Textbox(Point pos, const std::string& text) : text(text) { add(pos); }

	Point get_pos() const { return point(0); }
	void set_pos(Point p) { set_point(0, p); }

	const std::string& get_text() const { return text; }
	void set_text(const std::string& s) { text = s; }

protected:
	virtual void draw_lines() const;

private:
	std::string text;
};

}

#endif
