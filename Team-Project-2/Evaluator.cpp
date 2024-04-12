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
	string token;

	while (iss >> token) { 
		if (isdigit(token.front())) { operands.push(stoi(token)); } // push operand onto stack operands
		else if (token == "-" && (operands.size() == 0)) { // checks for negative numbers in the beginning
			iss >> token;
			operands.push(-stoi(token));
		}
		else if (token == "(") { 
			operators.push(token); 
		} // checks for parentheses
		else if (token == ")") {
			while (operators.top() != "(") { // evaluates every operator within parentheses
				evaluate_specific_terms(operands, operators.top());
				operators.pop();
			}
			operators.pop();
		}
		else { // evaluate current operator
			while (!operators.empty() && operators.top() != "(" && get_precedence(token) <= get_precedence(operators.top())) {
				evaluate_specific_terms(operands, operators.top());
				operators.pop();
			}
			operators.push(token);
		}
	}
	while (!operators.empty()) { // evaluate every operator
		evaluate_specific_terms(operands, operators.top());
		operators.pop();
	}
	return operands.top(); // return result
}
