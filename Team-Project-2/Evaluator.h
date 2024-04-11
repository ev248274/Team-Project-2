#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "helper_functions.h"


using std::istringstream;
using std::ostringstream;

class Evaluator {
private:
	// Data Fields
	stack<string> operators;
	stack<int> operands;
public:
	// Constructors
	Evaluator();

	// Destructor
	~Evaluator();

	// Class-member functions
	void clear(); // Empties two stacks and string
	int eval_infix(string&); // Evaluates given string infix expression 
};
#endif EVALUATOR_H
