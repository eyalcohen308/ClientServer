//
// Created by eyal & tomer on 1/3/19.
//

#ifndef CLIENTSERVER_STRINGREVERSER_H
#define CLIENTSERVER_STRINGREVERSER_H

#include <iostream>
#include "Solver.h"
#include <string>
#include <algorithm>
using namespace std;

class StringReverser : public Solver <string,string>{
public:
    virtual string solve(const string &problem);
};


#endif //CLIENTSERVER_STRINGREVERSER_H
