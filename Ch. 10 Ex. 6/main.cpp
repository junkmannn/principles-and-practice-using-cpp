#include "roman_numeral.h"
#include <iostream>
#include <fstream>

using namespace std;

void roman_numerals_test();
void roman_numerals_test2();
void roman_numerals_test3();

int main() {
	// roman_numerals_test();
	// roman_numerals_test2();
	// roman_numerals_test3();

	Roman_numeral rn;
	cin >> rn;
	if (!cin.fail()) {
		cout << "Roman " << rn << " equals " << rn.get_value() << '\n';
	}
	else {
		cout << "Bad roman numerals\n";
		cin.clear();
	}

	char c;
	cin >> c;

	return 0;
}

void roman_numerals_test() {
	int int_val = 0;
	string roman;

	// All symbols
	// ---------------------------------
	cout << "All symbols\n";

	roman = "I";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 1)\n";

	roman = "V";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 5)\n";

	roman = "X";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 10)\n";

	roman = "L";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 50)\n";

	roman = "C";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 100)\n";

	roman = "D";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 500)\n";

	roman = "M";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 1000)\n";

	cout << '\n';
	// ---------------------------------

	// Something invalid (cur_sym_val == 0)
	// ---------------------------------
	cout << "Something invalid (cur_sym_val == 0)\n";

	roman = "NOT ROMAN";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val == prev_sym_val
	// ---------------------------------
	cout << "cur_sym_val == prev_sym_val\n";

	roman = "II";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 2)\n";

	roman = "III";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 3)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val == prev_sym_val AND cur_sym_val == 5 || cur_sym_val == 50 || cur_sym_val == 500
	// ---------------------------------
	cout << "cur_sym_val == prev_sym_val AND cur_sym_val == 5 || cur_sym_val == 50 || cur_sym_val == 500\n";

	roman = "VV";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "LL";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "DD";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val == prev_sym_val AND prev_prev_sym_val < cur_sym_val
	// ---------------------------------
	cout << "cur_sym_val == prev_sym_val AND prev_prev_sym_val < cur_sym_val\n";

	roman = "IXX";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val == prev_sym_val AND repeated_sym_count == 3
	// ---------------------------------
	cout << "cur_sym_val == prev_sym_val AND repeated_sym_count == 3\n";

	roman = "IIII";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val < prev_sym_val
	// ---------------------------------
	cout << "cur_sym_val < prev_sym_val\n";

	roman = "MDCLXVI";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 1666)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val < prev_sym_val AND cur_sym_val >= prev_prev_sym_val
	// ---------------------------------
	cout << "cur_sym_val < prev_sym_val AND cur_sym_val >= prev_prev_sym_val\n";

	roman = "IXI";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "IXV";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val > prev_sym_val (else) AND (prev_sym_val != 1 && prev_sym_val != 10 && prev_sym_val != 100)
	// ---------------------------------
	cout << "cur_sym_val > prev_sym_val (else) AND (prev_sym_val != 1 && prev_sym_val != 10 && prev_sym_val != 100)\n";

	roman = "VX";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "VL";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "VC";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "VD";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "VM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "LC";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "LD";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "LM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "DM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "MVX";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val > prev_sym_val (else) AND prev_sym_val * 10 < cur_sym_val
	// ---------------------------------
	cout << "cur_sym_val > prev_sym_val (else) AND prev_sym_val * 10 < cur_sym_val\n";

	roman = "IV";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 4)\n";

	roman = "IX";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 9)\n";

	roman = "IL";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "IC";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "ID";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "IM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "XL";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 40)\n";

	roman = "XC";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 90)\n";

	roman = "XD";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "XM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "CD";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 400)\n";

	roman = "CM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 900)\n";

	roman = "MIL";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "MIV";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 1004)\n";

	cout << '\n';
	// ---------------------------------

	// cur_sym_val > prev_sym_val (else) AND cur_sym_val > prev_prev_sym_val
	// ---------------------------------
	cout << "cur_sym_val > prev_sym_val (else) AND cur_sym_val > prev_prev_sym_val\n";

	roman = "IXL";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "IXC";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	cout << '\n';
	// ---------------------------------

	// random
	// ---------------------------------
	cout << "random tests\n";

	// see if we didn't fuck up this one
	roman = "XIX";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 19)\n";

	roman = "MDCIXC";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "MDCM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "MDCCM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	roman = "MDCCCM";
	int_val = roman_value_of(roman);
	cout << roman << " = " << int_val << " (SHOULD BE 0)\n";

	cout << '\n';
	// ---------------------------------
}

void roman_numerals_test2() {
	ifstream ist("test.txt");
	int int_val = 0;
	string roman;
	while (ist >> int_val >> roman) {
		int rti = roman_value_of(roman);
		if (int_val != rti) {
			cout << "rti is " << rti << " should be " << int_val << '\n';
			return;
		}
	}
	cout << "roman_numerals_test2 success!\n";
}

void roman_numerals_test3() {
	ifstream ist("test.txt");
	int int_val = 0;
	string roman;
	while (ist >> int_val >> roman) {
		string dtr = decimal_to_roman(int_val);
		if (dtr != roman) {
			cout << "dtr is " << dtr << " should be " << roman << '\n';
			return;
		}
	}
	cout << "roman_numerals_test3 success!\n";
}
