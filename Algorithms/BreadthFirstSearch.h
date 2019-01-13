//
// Created by tomer on 1/13/19.
//

#ifndef CLIENTSERVER_BREADTHFIRSTSEARCH_H
#define CLIENTSERVER_BREADTHFIRSTSEARCH_H


#include <list>
#include <algorithm>
#include "../searchAlgo/Searcher.h"

using namespace std;

template<class Problem>
class BreadthFirstSearch : public Searcher<Problem> {
private:
    int evaluated_nodes = 0;
public:
    BreadthFirstSearch(){}; // Ctor
    virtual vector<State<Problem> *> search(Searchable<Problem> *searchable) {

        // Create a queue for BFS
        std::list<State<Problem> *> queue;

        State<Problem> *cur_state = searchable->getInitState();

        queue.push_back(cur_state); // insert to the queue
        cur_state->visit(); // mark that visited

        //TODO check if the right place
        typename vector<State<Problem> *>::iterator it; // 'it' will be used to get all adjacent

        while (!queue.empty()) {
            // dequeue a vertex from queue
            cur_state = queue.front();
            queue.pop_front();

            this->evaluated_nodes++;

            if (cur_state == searchable->getGoalState()) {
                // we done
                break;
            }
            // Get all adjacent vertices of the dequeued
            // vertex s. If a adjacent has not been is_visited,
            // then mark it is_visited and enqueue it
            vector<State<Problem> *> adj = searchable->getAllPossibleStates(cur_state);
            for (it = adj.begin(); it != adj.end(); ++it) {
                State<Problem> *neighbor = (*it);
                if (!(neighbor->is_visited())) {
                    neighbor->visit();
                    neighbor->setCameFrom(cur_state);
                    // insert to queue
                    queue.push_back(neighbor);
                }
            }
        } // end of while loop

        //get the nodes from the goal to begin
        vector<State<Problem> *> path;
        //State<T> *currentState = searchable->getGoalState();
        cur_state = searchable->getGoalState();
        State<Problem> *beginState = searchable->getInitState();
        if (cur_state->getCameFrom() == NULL) {
            return path;
        }
        // insert path to vector
        while (!(cur_state == beginState)) {
            path.push_back(cur_state);
            cur_state = cur_state->getCameFrom();
        }
        // insert init state
        path.push_back(searchable->getInitState());
        // begin to the goal
        std::reverse(path.begin(), path.end());
        return path;
    }

    virtual int getNumOfNodesEvaluated() {
        return this->evaluated_nodes;
    }

};


#endif //CLIENTSERVER_BREADTHFIRSTSEARCH_H
