//
// Created by tomer on 1/16/19.
//

#ifndef CLIENTSERVER_DATASTRUCTURE_H
#define CLIENTSERVER_DATASTRUCTURE_H
template<class T>
class DataStructure{
public:
    virtual void pushNode(State<T>*& node) = 0;
    virtual void popNode() = 0;
    virtual State<T>* topNode() = 0;
    virtual bool isEmpty() = 0;
};
#endif //CLIENTSERVER_DATASTRUCTURE_H
