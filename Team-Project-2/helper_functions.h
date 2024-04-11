#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <string>
#include <sstream>
#include <stack>
#include <iostream>
#include <exception>

using namespace std;

unsigned int get_precedence(const string&);

void add_spaces_between_terms(string&);

void evaluate_specific_terms(stack<int>&, string&);

#endif