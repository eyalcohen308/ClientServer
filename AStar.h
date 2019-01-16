//
// Created by eyal & tomer on 1/14/19.
//

#ifndef CLIENTSERVER_ASTAR_H
#define CLIENTSERVER_ASTAR_H


#include <queue>
#include <unordered_map>
#include <algorithm>
#include "Searcher.h"
#include "AbstractAstarBest.h"

template<class T>
class AStar : public AbstractAstarBest<T> {
    virtual void setHeuristic(State<T> *state, Searchable<T> *searchable){
        searchable->setDistance(state);
    }
};


#endif //CLIENTSERVER_ASTAR_H
