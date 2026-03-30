#include "../std_lib_facilities.h"

void init_numbers();
int number_to_int(string number);

vector<string> numbers_spelled_out(10);
vector<string> numbers_digit(10);

int main() {
	init_numbers();

	cout << "Enter two operands (single digit only; can also be spelled-out)\nfollowed by an operation (e.g. one 5 +)\n";

	string s_operand1 = "";
	string s_operand2 = "";
	char operation = ' ';
	cin >> s_operand1 >> s_operand2 >> operation;

	int i_operand1 = number_to_int(s_operand1);
	int i_operand2 = number_to_int(s_operand2);
	if (i_operand1 == -1 || i_operand2 == -1) {
		simple_error("operands must be between 0 and 9 (spelled-out or digit form)");
	}
	else {
		switch (operation) {
		case '+':
			cout << "The sum of " << i_operand1 << " and " << i_operand2 << " is " << (i_operand1+i_operand2) << '\n';
			break;
		case '-':
			cout << "The difference of " << i_operand1 << " and " << i_operand2 << " is " << (i_operand1-i_operand2) << '\n';
			break;
		case '*':
			cout << "The product of " << i_operand1 << " and " << i_operand2 << " is " << (i_operand1*i_operand2) << '\n';
			break;
		case '/':
			if (i_operand2 == 0) {
				simple_error("cannot divide by 0");
			}
			else {
				cout << "The quotient of " << i_operand1 << " and " << i_operand2 << " is " << (i_operand1/i_operand2) << '\n';
			}
			break;
		default:
			simple_error("invalid operation (supported: +, -, * and /");
			break;
		}
	}

	keep_window_open();
	return 0;
}

void init_numbers() {
	numbers_spelled_out[0] = "zero";
	numbers_spelled_out[1] = "one";
	numbers_spelled_out[2] = "two";
	numbers_spelled_out[3] = "three";
	numbers_spelled_out[4] = "four";
	numbers_spelled_out[5] = "five";
	numbers_spelled_out[6] = "six";
	numbers_spelled_out[7] = "seven";
	numbers_spelled_out[8] = "eight";
	numbers_spelled_out[9] = "nine";

	numbers_digit[0] = "0";
	numbers_digit[1] = "1";
	numbers_digit[2] = "2";
	numbers_digit[3] = "3";
	numbers_digit[4] = "4";
	numbers_digit[5] = "5";
	numbers_digit[6] = "6";
	numbers_digit[7] = "7";
	numbers_digit[8] = "8";
	numbers_digit[9] = "9";
}

int number_to_int(string number) {
	for (int i = 0; i < 10; ++i) {
		if (number == numbers_spelled_out[i] || number == numbers_digit[i]) {
			return i;
		}
	}
	return -1;
}