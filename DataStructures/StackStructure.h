//
// Created by tomer on 1/16/19.
//

#ifndef CLIENTSERVER_STACKSTRUCTURE_H
#define CLIENTSERVER_STACKSTRUCTURE_H


#include <stack>
#include "DataStructure.h"
#include "../searchAlgo/State.h"

template <class T>
class StackStructure : DataStructure<T>{
    std::stack<T> structure;
public:
    virtual void pushNode(State<T>*& node){
        structure.push_back(node);
    }
    virtual void popNode(){
        structure.pop();
    }
    virtual State<T>* topNode(){
        return structure.top();
    }
    virtual bool isEmpty(){
        return structure.empty();
    }
};


#endif //CLIENTSERVER_STACKSTRUCTURE_H
