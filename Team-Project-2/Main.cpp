#include "Evaluator.h"
#include "helper_functions.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Gets string value from file
*/
string get_file() {
	string infix_expression;
	ifstream input_file;

	input_file.open("Infix_Expression.txt");

	getline(input_file, infix_expression); // Reads the expression from the file

	input_file.close();
	return infix_expression;
}

int main() {
	Evaluator eval; // Calls an instance of the evaluator class
	string infix_val = get_file();

	cout << "The inputted expression is: " << infix_val << endl;
	cout << "The result of the input is: " << eval.eval_infix(infix_val) << endl;

	system("pause");
	return 0;
}