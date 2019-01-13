//
// Created by tomer on 1/7/19.
//

#ifndef CLIENTSERVER_STATE_H
#define CLIENTSERVER_STATE_H


template<class T>
class State {
    T state;
    double cost;
    State<T> *came_from;
    bool has_visited;

public:
    /**
     * Ctor
     * @param stat
     * @param cost
     */
    State(T stat, double cost) : state(stat), cost(cost) {
        has_visited = false;
    };

    /**
     * check if other state equal to this state.
     * @param other
     * @return
     */
    bool operator==(const State<T> *other) {
        return (this->state == other->state);
    }

    /**
     * get state
     * @return
     */
    T getState() {
        return this->state;
    }

    /**
     * set came from
     * @param father
     */
    void setCameFrom(State<T> *father) {
        this->came_from = father;
    }

    /**
     * update visited
     */
    void updateVisited() {
        this->has_visited = true;
    }

    /**
     * get visit status
     */
    bool visited() {
        return this->has_visited;
    }

    /**
     * get came from
     */
    State<T> *getCameFrom() {
        return this->came_from;
    }

    /**
     * get cost
     */
    double getCost(){
        return this->cost;
    }
};


#endif //CLIENTSERVER_STATE_H
