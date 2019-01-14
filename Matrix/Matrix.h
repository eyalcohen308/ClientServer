//
// Created by eyal on 1/13/19.
//

#ifndef CLIENTSERVER_MATRIX_H
#define CLIENTSERVER_MATRIX_H


#include <string>
#include "../searchAlgo/Searchable.h"

using namespace std;
typedef pair<int, int> point;

class Matrix : public Searchable<point> {
private:
    State<point> *begin;
    State<point> *end;
    vector<vector<State<point> *>> matrix;

    void createMatrix(vector<vector<string>> &lines);

public:
    Matrix(vector<vector<string>> lines);

    virtual State<point> *getInitState() {
        return this->begin;
    }

    virtual State<point> *getGoalState() {
        return this->end;
    }

    virtual vector<State<point> *> getAllPossibleStates(State<point> *state);

    virtual vector<State<point> *> getAllStates();

    bool checkIfValidNeighbor(int col, int row);
};


#endif //CLIENTSERVER_MATRIX_H
