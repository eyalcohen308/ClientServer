//
// Created by tomer on 1/7/19.
//

#ifndef CLIENTSERVER_SEARCHABLE_H
#define CLIENTSERVER_SEARCHABLE_H

#include "State.h"
#include <vector>
template <class T>
class Searchable{
    virtual State<T> getInitState();
    virtual State<T> getGoalState();
    virtual std::vector<State<T>> getAllPosibaleStates(State<T> s);
};
#endif //CLIENTSERVER_SEARCHABLE_H
