#include "helper_functions.h"

/*
Returns the predefined precedence value of an operator
@param this_operator: the given operator
@return: the precendence value represented as an unsigned integer (higher number, higher precedence)
*/
unsigned int get_precedence(const char this_operator) {
	if (this_operator == '^') {
		return 7;
	}
	else if (this_operator == '*' || this_operator == '/' || this_operator == '%') {
		return 6;
	}
	else if (this_operator == '+' || this_operator == '-') {
		return 5;
	}
	else if (this_operator == '>' || this_operator == '>=' || this_operator == '<' || this_operator == '<=') {
		return 4;
	}
	else if (this_operator == '==' || this_operator == '!=') {
		return 3;
	}
	else if (this_operator == '&&') {
		return 2;
	}
	else if (this_operator == '||') {
		return 1;
	}
}