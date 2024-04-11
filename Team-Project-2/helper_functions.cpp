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

/*
This function will add spaces between every term, operator, and parentheses
@param str: the string to format
*/
void add_spaces_between_terms(string& str) {
	string result_string = " ";

	for (auto it = str.begin(); it != str.end(); ++it) {
		string s(1, *it);
		if (*it != ' ') {
			// Numbers
			if (isdigit(*it)) {
				result_string += s;
			}
			// Parentheses
			else if (*it == '(') {
				result_string += s + ' ';
			}
			else if (*it == ')') {
				result_string += ' ' + s;
			}
			// Operators with a possible length of 2
			else if (*it == '>') {
				if (*(it + 1) == '=') {
					result_string += " >= ";
					it++;
				}
				else { result_string += s; }
			}
			else if (*it == '<') {
				if (*(it + 1) == '=') {
					result_string += " <= ";
					it++;
				}
				else { result_string += s; }
			}
			else if (*it == '=') {
				result_string += " == ";
				it++;
			}
			else if (*it == '!') {
				result_string += " != ";
				it++;
			}
			else if (*it == '&') {
				result_string += " && ";
				it++;
			}
			else if (*it == '|') {
				result_string += " || ";
				it++;
			}
			// Operators with a length of 1
			else {
				result_string += ' ' + s + ' ';
			}
		}
	}
	result_string += " ";
	// Update our string
	str = result_string;
}
void evaluate_specific_terms(stack<int>& stk_i, string& str) {
	int right = stk_i.top();
	stk_i.pop();
	int left = stk_i.top();
	stk_i.pop();
	
	// supported operators
	if (str == "+") { stk_i.push(left + right); }
	if (str == "-") { stk_i.push(left - right); }
	if (str == "*") { stk_i.push(left * right); }
	if (str == "/") {
		if (!right) { throw exception("Divide by zero"); }
		stk_i.push(left / right);
	}
	if (str == "^") { stk_i.push(pow(left, right)); }
	if (str == "%") { stk_i.push(left % right); }
	if (str == ">") { stk_i.push(left > right); }
	if (str == ">=") { stk_i.push(left >= right); }
	if (str == "<") { stk_i.push(left < right); }
	if (str == "<=") { stk_i.push(left <= right); }
	if (str == "==") { stk_i.push(left == right); }
	if (str == "!=") { stk_i.push(left != right); }
	if (str == "&&") { stk_i.push(left && right); } // FIXME >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	if (str == "||") { stk_i.push(left || right); } // FIXME >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

}