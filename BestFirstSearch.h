//
// Created by eyal & tomer on 1/7/19.
//

#ifndef CLIENTSERVER_BESTFIRSTSEARCH_H
#define CLIENTSERVER_BESTFIRSTSEARCH_H

#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>
#include "Searcher.h"
#include "AbstractAstarBest.h"

template<class T>

class BestFirstSearch : public AbstractAstarBest<T> {

    virtual void setHeuristic(State<T> *state, Searchable<T> *searchable) {
        return; // no Heuristic
    }
};

#endif //CLIENTSERVER_BESTFIRSTSEARCH_H
