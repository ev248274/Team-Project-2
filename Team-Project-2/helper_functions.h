#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <string>
#include <sstream>
#include <stack>
#include <iostream>
#include <exception>

using namespace std;
using std::exception;

// Declaring the get_precedence function 
unsigned int get_precedence(const string&);

// Declaring the add_spaces_between function
void add_spaces_between_terms(string&);

// Declaring the evaluate_specific_terms function
void evaluate_specific_terms(stack<int>&, string&);

#endif