#include <iostream>
#include <fstream>
#include <string>

/*
Test case 2 analysis with file "Infix_Expression_tc2"
*/

using namespace std;

void test_case_2() {
	ifstream input_file;
	string infix_expression = "";

	input_file.open("Infix_Expression_tc2.txt");

	getline(input_file, infix_expression);

	input_file.close();
}