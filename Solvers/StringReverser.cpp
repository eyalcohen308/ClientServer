//
// Created by eyal on 1/3/19.
//

#include "StringReverser.h"

string StringReverser::solve(const string &problem) {
    string reversed_string(problem);
    reverse(reversed_string.begin(), reversed_string.end());
    return reversed_string;
}
