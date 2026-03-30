#include "../std_lib_facilities.h"

int main() {
	cout << "Enter two operands followed by an operation (e.g. 100 3.14 +)\n";

	double operand1 = 0.0;
	double operand2 = 0.0;
	char operation = ' ';
	cin >> operand1 >> operand2 >> operation;

	switch (operation) {
	case '+':
		cout << "The sum of " << operand1 << " and " << operand2 << " is " << (operand1+operand2) << '\n';
		break;
	case '-':
		cout << "The difference of " << operand1 << " and " << operand2 << " is " << (operand1-operand2) << '\n';
		break;
	case '*':
		cout << "The product of " << operand1 << " and " << operand2 << " is " << (operand1*operand2) << '\n';
		break;
	case '/':
		cout << "The quotient of " << operand1 << " and " << operand2 << " is " << (operand1/operand2) << '\n';
		break;
	default:
		simple_error("invalid operation");
		break;
	}

	keep_window_open();
	return 0;
}