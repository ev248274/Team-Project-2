#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

#include <string>
#include <sstream>
#include <stack>

using namespace std;

unsigned int get_precedence(const string&);

string infix_to_postfix(const string&);

#endif