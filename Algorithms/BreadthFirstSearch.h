//
// Created by tomer on 1/13/19.
//

#ifndef CLIENTSERVER_BREADTHFIRSTSEARCH_H
#define CLIENTSERVER_BREADTHFIRSTSEARCH_H


#include <list>
#include <algorithm>
#include "../searchAlgo/Searcher.h"
#include "AbstractBfsDfs.h"
#include "../DataStructures/QueueStructure.h"

using namespace std;

template<class Problem>
class BreadthFirstSearch : public AbstractBfsDfs<Problem> {
public:
//    virtual DataStructure<State<Problem> *> *createStructure() {
//        return new QueueStructure<State<Problem> *>();
//    }
    virtual void initStructure() {
        this->structure = new QueueStructure<State<Problem> *>();
    }

};


#endif //CLIENTSERVER_BREADTHFIRSTSEARCH_H
