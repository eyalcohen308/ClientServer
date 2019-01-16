//
// Created by tomer on 1/14/19.
//

#ifndef CLIENTSERVER_DEPTHFIRSTSEARCH_H
#define CLIENTSERVER_DEPTHFIRSTSEARCH_H

#include<stack>
#include <vector>
#include <algorithm>
#include "../searchAlgo/Searcher.h"
#include "AbstractBfsDfs.h"
#include "../DataStructures/StackStructure.h"

using namespace std;

template<class Problem>
class DepthFirstSearch : public AbstractBfsDfs<Problem> {
public:
//    virtual DataStructure<State<Problem> *> *createStructure() {
//        return new StackStructure<State<Problem> *>();
//    }
    virtual void initStructure() {
        this->structure = new StackStructure<State<Problem> *>();
    }

};

#endif //CLIENTSERVER_DEPTHFIRSTSEARCH_H
