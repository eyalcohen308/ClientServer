//
// Created by tomer on 1/16/19.
//

#ifndef CLIENTSERVER_QUEUESTRUCTURE_H
#define CLIENTSERVER_QUEUESTRUCTURE_H

#include <list>
#include "DataStructure.h"
#include "../searchAlgo/State.h"

template<class T>
class QueueStructure: public DataStructure<T>{
    std::list<State<T>*> structure;
public:
    virtual void pushNode(State<T>*& node){
        structure.push_back(node);
    }
    virtual void popNode(){
        structure.pop_front();
    }
    virtual State<T>* topNode(){
        return structure.front();
    }
    virtual bool isEmpty(){
        return structure.empty();
    }

};


#endif //CLIENTSERVER_QUEUESTRUCTURE_H
