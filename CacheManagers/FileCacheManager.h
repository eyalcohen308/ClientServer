//
// Created by eyal on 1/3/19.
//

#ifndef CLIENTSERVER_FILECACHEMANAGER_H
#define CLIENTSERVER_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <map>
#include <iostream>
#include <unordered_map>
#include <fstream>

using namespace std;

template<class Problem, class Solution>

class FileCacheManager : public CacheManager<Problem, Solution> {
private:
    unordered_map<Problem, Solution> data_base;

public:

    FileCacheManager() {
        loadSolutionsFromDisk();
    }

    virtual bool hasSolutionTo(const Problem &problem) {
        return (!(data_base.find(problem) == data_base.end()));
    }

    virtual Solution getSolutionTo(const Problem &problem) {
        if (hasSolutionTo(problem)) {
            return data_base.at(problem);
        }
        //TODO: decide if null or execption.
        return NULL;
    }

    virtual void loadSolutionsFromDisk() {
        // save to file each problem and solution.
        fstream input;
        input.open("input.txt", fstream::in | fstream::out | fstream::app);
        if (!input.is_open()) {
            throw runtime_error("unable to open file");
        }
        string line;
        while (getline(input, line)) {
            size_t pos = line.find("end$");
            string problem = line.substr(0, pos+3);
            string solution = line.substr(pos + 4, line.length() - 1);
            data_base.insert(pair<Problem,Solution>(problem,solution));
        }
    }

    virtual void writeSolutions(){
        // save to file each problem and solution.
        fstream input;
        input.open("input.txt", std::ofstream::out | std::ofstream::trunc);

        for (auto it : data_base) {
            // write the problem data to file.
            input << (it.first) << "$";
            // write the solution data to file.
            input << (it.second) << endl;
        }
        input.close();
    }

    void saveSolutionFor(const Problem p, const Solution s) {
        data_base.insert(pair<Problem, Solution>(p, s));
    }
};

#endif //CLIENTSERVER_FILECACHEMANAGER_H
