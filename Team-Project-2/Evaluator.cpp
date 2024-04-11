#include "Evaluator.h"

// Constructors

// Default Constructor
Evaluator::Evaluator() : operands(), operators() {}

// Destructor
Evaluator::~Evaluator() { clear(); }

// Class-member functions

/*
Empties two stacks and one string
*/
void Evaluator::clear() {
	while (!operands.empty()) { operands.pop(); }
	while (!operators.empty()) { operators.pop(); }
}

/*
Evaluates the given string infix expression
@param: infix expression
@return: evaluated infix expression
*/
int Evaluator::eval_infix(string& str) {
	add_spaces_between_terms(str);
	istringstream iss(str);
	ostringstream oss(str);
	string token;

	while (iss >> token) { // FIXME >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		if (isdigit(token.front())) { operands.push(stoi(token)); } // push operand onto stack operands
		else if (token == "(") { operators.push(token); }
		else if (token == ")") {
			while (operators.top() != "(") {
				evaluate_specific_terms(operands, operators.top());
				operators.pop();
			}
			operators.pop();
		}
		else {
			while (!operators.empty() && operators.top() != "(" && get_precedence(token) <= get_precedence(operators.top())) {
				evaluate_specific_terms(operands, operators.top());
				operators.pop();
			}
			operators.push(token);
		}
	}
	while (!operators.empty()) {
		evaluate_specific_terms(operands, operators.top());
		operators.pop();
	}
	return operands.top();
}
