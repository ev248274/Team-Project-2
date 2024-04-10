#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Returns a string with uniform spaces
@param str: reference to string variable
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
	
	string infix_val = get_file();

	system("pause");
	return 0;
}