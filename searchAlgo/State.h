//
// Created by eyal & tomer on 1/7/19.
//

#ifndef CLIENTSERVER_STATE_H
#define CLIENTSERVER_STATE_H

template<class T>
class State {
    T state;
    int cost;
    State<T> *came_from;
    bool has_visited;
    int path_value;
    int distance;

public:
    /**
     * Ctor
     * @param stat
     * @param cost
     */
    State(T stat, int cost) : state(stat), cost(cost) {
        has_visited = false;
        path_value = cost;
        came_from = nullptr;
        distance = 0;
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
 * set distance by hiuristic.
 * @param d int to set.
 */
    void setDistance(int d) {
        this->distance = d;
    }
/**
 * get the distance have by hiuristic.
 * @return int distance.
 */
    int getDistance() {
        return this->distance;
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
    void visit() {
        this->has_visited = true;
    }

    /**
     * get visit status
     */
    bool is_visited() {
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
    int getCost() {
        return this->cost;
    }

    /**
    * get distance
    */
    int getPathValue() {
        return this->path_value;
    }

    /**
     * set new path value
     * @param new_pv
     */
    void setPathValue(int new_pv) {
        this->path_value = new_pv;
    }

    /**
     * add cost to the path
     * @param path
     */
    void addPathValue(int path) {
        this->path_value += path;
    }
};


#endif //CLIENTSERVER_STATE_H
