//
// Created by eyal & tomer on 1/7/19.
//

#ifndef CLIENTSERVER_SEARCHABLE_H
#define CLIENTSERVER_SEARCHABLE_H

#include "State.h"
#include <vector>

template<class T>
class Searchable {
public:
    virtual State<T> *getInitState() = 0;

    virtual State<T> *getGoalState() = 0;

    virtual std::vector<State<T> *> getAllPossibleStates(State<T> *s) = 0;

    virtual std::vector<State<T> *> getAllStates() = 0;

    virtual void setDistance(State<T> *current) = 0;
};

#endif //CLIENTSERVER_SEARCHABLE_H
