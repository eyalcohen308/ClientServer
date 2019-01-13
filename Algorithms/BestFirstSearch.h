//
// Created by tomer on 1/7/19.
//

#ifndef CLIENTSERVER_BESTFIRSTSEARCH_H
#define CLIENTSERVER_BESTFIRSTSEARCH_H


#include <queue>
#include <algorithm>
#include "../searchAlgo/Searcher.h"

template<class T>

class BestFirstSearch : Searcher<T> {
    std::priority_queue<T> open_list;
    int evaluate_nodes;

    std::vector<State<T>> backTrace(){
        // TODO func
    }
public:
    // Ctor
    BestFirstSearch() {
        open_list = new std::priority_queue<T>();
        evaluate_nodes = 0;
    }

    // search method
    virtual std::vector<T> search(Searchable<T> *searchable){
        open_list.push(searchable->getInitState());
        std::vector<State<T>> close_list = new std::vector<T>;
        while (getOpenListSize()>0){
            State<T> n = popOpenList();
            close_list.insert(n);
            if (n==searchable->getGoalState()){
                return backTrace;
            }
            std::vector<State<T>> succerssors = searchable->getAllPossibleStates(n);
            for(typename std::vector<State<T>>::iterator it = succerssors.begin(); it != succerssors.end(); it++){
                // if not found in the open and in the close lists
                if((std::find(close_list.begin(),close_list.end(), (*it))==close_list.end)
                && (std::find(open_list.begin(),open_list.end(), (*it))==open_list.end)){
                    // TODO - do s.setCameFrom(n); in getAllPossibleStates
                    open_list.push((*it)); // add succerssors to open list
                } else {
                    //  if( new path is better than the prev one){
                // if (std::find(open_list.begin(),open_list.end(), (*it))==open_list.end)){
                 //
                 // }
                // }
                }
            }

        }

        delete(close_list);
    }

    //  get how many nodes were evaluated by the algorithm
    virtual int getNumOfNodesEvaluated(){
        return evaluate_nodes;
    }

    State<T> popOpenList(){
        ++(this->evaluate_nodes);
        T temp_top = open_list.top();
        open_list.pop();
        return temp_top;
    }

    int getOpenListSize(){
        return open_list.size();
    }

    ~BestFirstSearch() {
        delete (open_list);
    }
};


#endif //CLIENTSERVER_BESTFIRSTSEARCH_H
