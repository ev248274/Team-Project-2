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