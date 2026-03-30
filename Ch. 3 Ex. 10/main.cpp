#include "../std_lib_facilities.h"

int main() {
	cout << "Enter an operation followed by two operands (e.g. + 100 3.14)\n";

	string operation = "";
	double operand1 = 0;
	double operand2 = 0;
	cin >> operation >> operand1 >> operand2;

	double result = 0;
	if (operation == "+") {
		result = operand1 + operand2;
	}
	else if (operation == "-") {
		result = operand1 - operand2;
	}
	else if (operation == "*") {
		result = operand1 * operand2;
	}
	else if (operation == "/") {
		result = operand1 / operand2;
	}
	else if (operation == "plus") {
		result = operand1 + operand2;
	}
	else if (operation == "minus") {
		result = operand1 - operand2;
	}
	else if (operation == "mul") {
		result = operand1 * operand2;
	}
	else if (operation == "div") {
		result = operand1 / operand2;
	}
	else {
		simple_error("Please enter a valid operation and operands\n");
	}

	cout << operand1 << ' ' << operation << ' ' << operand2 << " = " << result << '\n';

	keep_window_open();
	return 0;
}