//
// Created by eyal on 1/3/19.
//

#ifndef CLIENTSERVER_CACHEMANAGER_H
#define CLIENTSERVER_CACHEMANAGER_H

#include<string>
#include <iostream>

using namespace std;

template<class Problem, class Solution>
class CacheManager {
public:
    virtual bool hasSolutionTo(const Problem &problem) = 0;

    virtual Solution getSolutionTo(const Problem &problem) = 0;

    virtual void saveSolutionFor(const Problem problem, const Solution solution) = 0;

    virtual void writeSolutions() = 0;

    virtual ~CacheManager() {
        cout << "hello" << endl;
    }
};

#endif //CLIENTSERVER_CACHEMANAGER_H
