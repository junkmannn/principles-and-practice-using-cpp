#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller {
public:
	virtual void on() { state = ON; }
	virtual void off() { state = OFF; }
	virtual void set_level(int i) { level = i; }
	virtual void show() const = 0;

protected:
	enum State { ON, OFF };
	State state;
	int level;
};

#endif
