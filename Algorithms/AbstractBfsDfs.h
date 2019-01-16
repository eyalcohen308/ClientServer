//
// Created by tomer on 1/16/19.
//

#ifndef CLIENTSERVER_ABSTRACTBFSDFS_H
#define CLIENTSERVER_ABSTRACTBFSDFS_H


#include<stack>
#include <vector>
#include <algorithm>
#include "../searchAlgo/Searcher.h"
#include "../DataStructures/DataStructure.h"

using namespace std;

template<class Problem>
class AbstractBfsDfs : public Searcher<Problem> {

private:
    int nodesEvaluated = 0;
protected:
    DataStructure<State<Problem> *> *structure;

    AbstractBfsDfs() {
        initStructure();
    }

//    virtual DataStructure<State<Problem> *> *createStructure() = 0;
    virtual void initStructure() = 0;


public:
    virtual std::vector<State<Problem> *> search(Searchable<Problem> *searchable) {

        // create stack and save the goal and initialize state
//        std::stack<State<Problem> *> stack;
//        DataStructure<State<Problem> *> *structure = createStructure();
        searchable->getGoalState();
        State<Problem> *cur_state = searchable->getInitState();
        State<Problem> *goal = searchable->getGoalState();

        // push the first to stack
        this->structure->pushNode(cur_state);

        typename vector<State<Problem> *>::iterator it;

        while (!this->structure->isEmpty()) {
            //pop a vertex from stack
            cur_state = this->structure->topNode();
            this->structure->popNode();

            this->nodesEvaluated++;

            //if the cur_state not mark as visited already-mark as visited
            if (!cur_state->is_visited()) {
                cur_state->visit();
            }

            //if we reach the goal state -we done and exit
            if (cur_state == goal) {
                // we done
                break;
            }

            vector<State<Problem> *> adj = searchable->getAllPossibleStates(cur_state);
            it = adj.begin();
            //add the adj
            for (; it != adj.end(); ++it) {
                State<Problem> *neighbor = (*it);
                if (!neighbor->is_visited()) {
                    neighbor->visit();
                    neighbor->setCameFrom(cur_state);
                    this->structure->pushNode(neighbor);
                }
            }
        }

        vector<State<Problem> *> path;
        State<Problem> *begin_state = searchable->getInitState();
        cur_state = goal;
        if (cur_state->getCameFrom() == NULL) {
            this->solution_value = -1;
            delete (this->structure);
            return path;
        }
        while (!(cur_state == begin_state)) {
            path.push_back(cur_state);
            cur_state = cur_state->getCameFrom();
        }
        path.push_back(searchable->getInitState());
        std::reverse(path.begin(), path.end());
        this->solution_value = path.size();
        delete (this->structure);
        return path;

    }

    virtual int getNumOfNodesEvaluated() {
        return this->nodesEvaluated;
    }
};


#endif //CLIENTSERVER_ABSTRACTBFSDFS_H
