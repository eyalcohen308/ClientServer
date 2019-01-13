//
// Created by tomer on 1/7/19.
//

#ifndef CLIENTSERVER_STATE_H
#define CLIENTSERVER_STATE_H
/**
 *
 * @tparam T
 */
template <class T>
class State {
    T state;
    double cost;
    State<T> came_from;

public:
    State(T stat): state(stat){}; // Ctor
    // check if other state equal to this state.
    bool operator==(const State<T> other){
        return (this->state == other.state);
    }
};


#endif //CLIENTSERVER_STATE_H
