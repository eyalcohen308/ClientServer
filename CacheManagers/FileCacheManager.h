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
        loadSolutionFromDisk();
    }

    virtual bool hasSolutionTo(const Problem &problem) {
        return (!(data_base.find(problem) == data_base.end()));
    }

    virtual Solution *getSolutionTo(const Problem &problem) {
        if (hasSolutionTo(problem)) {
            return &data_base.at(problem);
        }
        //TODO: decide if null or execption.
        return NULL;
    }

    virtual void loadSolutionFromDisk() {
        // save to file each problem and solution.
        ifstream input;
        input.open("input.txt", ios::in | ios::app);
        if (!input.is_open()) {
            throw runtime_error("unable to open file");
        }
        while (!input.eof()) {
            Problem p;
            Solution s;
            //read Problem Data to problem object
            input.read((char *) &p, sizeof(p));
            //read solution Data to solution object
            input.read((char *) &s, sizeof(s));
            if (p == "") {
                return;
            }
            data_base.insert(pair<Problem, Solution>(p, s));
        }
    }
    ~FileCacheManager() {
        // save to file each problem and solution.
        ofstream input;
        input.open("input.txt", ios::app);
//        if (!input.is_open()) {
//            throw runtime_error("unable to open file");
//        }
        for (auto it : data_base) {
            // write the problem data to file.
            input.write((char *) &(it.first), sizeof(it.first));
            // write the solution data to file.
            input.write((char *) &(it.second), sizeof(it.second));
        }
    }

    void saveSolutionFor(const Problem p, const Solution s) {
        data_base.insert(pair<Problem, Solution>(p, s));
    }
};

#endif //CLIENTSERVER_FILECACHEMANAGER_H
