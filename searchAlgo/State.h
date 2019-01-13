//
// Created by tomer on 1/7/19.
//

#ifndef CLIENTSERVER_STATE_H
#define CLIENTSERVER_STATE_H

/**
 *
 * @tparam T
 */
template<class T>
class State {
    T state;
    double cost;
    State<T> *came_from;
    bool has_visited;
public:
    State(T stat, double cost) : state(stat), cost(cost) {
        this->has_visited = false;
    }; // Ctor
    // check if other state equal to this state.
    bool operator==(const State<T> other) {
        return (this->state == other.state);
    }
};


#endif //CLIENTSERVER_STATE_H
