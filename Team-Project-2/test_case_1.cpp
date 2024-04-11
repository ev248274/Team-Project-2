#include "Evaluator.h"
#include <iostream>
#include <fstream>
#include <string>
/*
Test case 1 analysis with file "Infix_Expression_tc1"
*/

using namespace std;

void test_case_1() {
	ifstream input_file;
	string infix_expression = "";

	input_file.open("Infix_Expression_tc1.txt");

	getline(input_file, infix_expression);

	input_file.close();
	Evaluator test_1;
	cout << test_1.eval_infix(infix_expression) << endl;
}