//
// Created by eyal & tomer on 1/3/19.
//

#ifndef CLIENTSERVER_SOLVER_H
#define CLIENTSERVER_SOLVER_H


template<class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(const Problem problem) = 0;
};


#endif //CLIENTSERVER_SOLVER_H
