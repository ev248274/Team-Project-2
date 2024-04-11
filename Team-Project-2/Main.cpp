#include "Evaluator.h"

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

	getline(input_file, infix_expression);

	input_file.close();
	return infix_expression;
}

int main() {
	Evaluator eval;
	string infix_val = get_file();
	cout << eval.eval_infix(infix_val) << endl;

	system("pause");
	return 0;
}