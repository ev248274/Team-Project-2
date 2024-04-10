#include "helper_functions.h"

/*
Returns the predefined precedence value of an operator
@param this_operator: the given operator
@return: the precendence value represented as an unsigned integer (higher number, higher precedence)
*/
unsigned int get_precedence(const string& this_operator) {
	if (this_operator == "^") {
		return 7;
	}
	else if (this_operator == "*" || this_operator == "/" || this_operator == "%") {
		return 6;
	}
	else if (this_operator == "+" || this_operator == "-") {
		return 5;
	}
	else if (this_operator == ">" || this_operator == ">=" || this_operator == "<" || this_operator == "<=") {
		return 4;
	}
	else if (this_operator == "==" || this_operator == "!=") {
		return 3;
	}
	else if (this_operator == "&&") {
		return 2;
	}
	else if (this_operator == "||") {
		return 1;
	}
}

/** Converts an infix expression to postfix expression.
@param infix_exp: infix expression to convert
@return: postfix expression converted from the infix expression
*/
string infix_to_postfix(const string& infix_exp) {
	istringstream iss(infix_exp);
	ostringstream oss;
	stack<string> stk;
	string token;

	while (iss >> token) {
		if (isdigit(token.front())) { oss << ' ' << token; }
		else if (token == "(") { stk.push(token); }
		else if (token == ")") {
			while (stk.top() != "(") {
				oss << ' ' << stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else {
			while (!stk.empty() && stk.top() != "(" && get_precedence(token) >= get_precedence(stk.top())) {
				oss << ' ' << stk.top();
				stk.pop();
			}
			stk.push(token);
		}
	}
	while (!stk.empty()) {
		oss << ' ' << stk.top();
		stk.pop();
	}
	return oss.str();
}

// FIXME <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
/*
This function will add spaces between every term, operator, and parentheses
@param str: the string to format
*/
void add_spaces_between_terms(string& str) {
	string result_string = "";
	string curr_number = ""; // Numbers can have more than 1 digit, so we'll save all digits in the current number

	result_string += ' '; // Leading space

	for (string::iterator it = str.begin(); it != str.end(); ++it) {
		// Numbers
		if (isdigit(*it)) {
			curr_number += *it;
		}
		// Parentheses
		else if (*it == '(') {
			result_string += curr_number;
			curr_number = "";
			result_string += (' ' + *it + ' ');
		}
		else if (*it == ')') {
			result_string += curr_number;
			curr_number = "";
			result_string += (' ' + *it + ' ');

		}
		// Operators
		else {
			result_string += curr_number;
			curr_number = "";
			result_string += (' ' + *it + ' ');
		}
	}

	// Update our string
	str = result_string;
}