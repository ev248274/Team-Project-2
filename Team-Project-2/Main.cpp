#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
Returns a string with uniform spaces
@param str: reference to string variable
*/
string set_spaces(string& str) {
	string uniform_string = "";
	for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
		if (*it != ' ') {
			string s(1, *it);
			uniform_string += " " + s;
		}
	}
	uniform_string += " ";
	return uniform_string;
}

int main() {
	ifstream input_file; 
	string infix_expression = "";

	input_file.open("Infix_Expression.txt");

	getline(input_file, infix_expression);

	input_file.close();

	cout << "Infix expression from file:\n" << set_spaces(infix_expression) << endl;

	system("pause");
	return 0;
}