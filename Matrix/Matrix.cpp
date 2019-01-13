//
// Created by eyal on 1/13/19.
//

#include "Matrix.h"

vector<State<point> *> Matrix::getAllPossibleStates(State<point> *state) {
    vector<State<point> *> neighbors;
    int columns = matrix.back().size();
    int rows = matrix.size();
    int i = state->getState().first;
    int j = state->getState().second;
    if (i != 0 && checkIfValidNeighbor(i - 1, j)) neighbors.push_back(matrix[i - 1][j]);
    if (i != rows - 1 && checkIfValidNeighbor(i + 1, j))neighbors.push_back(matrix[i + 1][j]);
    if (j != 0 && checkIfValidNeighbor(i, j - 1))neighbors.push_back(matrix[i][j - 1]);
    if (j != columns - 1&& checkIfValidNeighbor(i, j + 1))neighbors.push_back(matrix[i][j + 1]);
    return neighbors;
}

bool Matrix::checkIfValidNeighbor(int row, int col) {
    return !(matrix[row][col]->getCost() == -1);
}

Matrix::Matrix(vector<vector<string>> lines) {
    createMatrix(lines);
}

/**
 * create the matrix by lines of values.
 * @param lines values.
 */
void Matrix::createMatrix(vector<vector<string>> &lines) {
    // the last line is the goal state.
    vector<string> end_vec = lines.back();
    lines.pop_back();
    // one line before it is the begin state.
    vector<string> begin_vec = lines.back();
    lines.pop_back();
    int rows_size = lines.size();
    int columns_size = lines[0].size();

    for (int i = 0; i < rows_size; ++i) {
        vector<State<point> *> row;
        for (int j = 0; j < columns_size; ++j) {
            // create the state by indexes and cost.
            double cost = stod(lines[i][j]);
            point location(i, j);
            auto *state = new State<point>(location, cost);
            row.push_back(state);
        }
        matrix.push_back(row);
    }

    // set start and goal states
    begin = matrix[stoi(begin_vec[0])][stoi(begin_vec[1])];
    end = matrix[stoi(end_vec[0])][stoi(end_vec[1])];
}
