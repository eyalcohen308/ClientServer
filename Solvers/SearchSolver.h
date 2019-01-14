//
// Created by tomer on 1/13/19.
//

#ifndef CLIENTSERVER_SEARCHSOLVER_H
#define CLIENTSERVER_SEARCHSOLVER_H

#include <vector>
#include <string>
#include "Solver.h"
#include "../searchAlgo/Searcher.h"
#include "../Matrix/Matrix.h"
#include "../Matrix/MatrixResult.h"
enum Color {
    WHITE, GREY, BLACK
};
using namespace std;

template<class T, class Solution>
class SearchSolver : public Solver<vector<vector<string>>, Solution> {
    Searcher<T> *searcher;
public:
    SearchSolver(Searcher<T> *searcher){
        this->searcher=searcher;
    }
    /*
     * solve
     */
    virtual Solution solve(vector<vector<string>> lines) {
        // init matrix into nre searchable
        Searchable<T> *matrix = new Matrix(lines);
        // find path- from start to goal state
        vector<State<pair<int,int>> *> path = searcher->search(matrix);
        // return the result in string of directions
        MatrixResult matrixResult;
        string str_solution = matrixResult.getSolution(path);

        delete(matrix); // free
        return str_solution;
    }
};


#endif //CLIENTSERVER_SEARCHSOLVER_H
