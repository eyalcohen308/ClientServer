//
// Created by eyal & tomer on 1/13/19.
//

#ifndef CLIENTSERVER_MATRIXRESULT_H
#define CLIENTSERVER_MATRIXRESULT_H

#include <string>
#include <vector>
#include "State.h"

using namespace std;
typedef pair<int, int> point;

class MatrixResult {
public:
    string getSolution(vector<State<point> *> solution) {
        string result = "";
        int sol_size=solution.size();
        //TODO check about size-1
        if (sol_size == 0) {
            return "No possible solution";
        }
        for (int i = 0; i < sol_size - 1; ++i) {

            if (solution[i]->getState().second == solution[i + 1]->getState().second) {
                if (solution[i]->getState().first > solution[i + 1]->getState().first) {
                    result = result + "Up,";

                } else {
                    result = result + "Down,";
                }
            } else if (solution[i]->getState().first == solution[i + 1]->getState().first) {
                if (solution[i]->getState().second > solution[i + 1]->getState().second) {
                    result = result + "Left,";

                } else {
                    result = result + "Right,";
                }

            }
        }
        // delete the extra ","
        string final_result = result.substr(0, result.size() - 1);

        return final_result;
    }
};


#endif //CLIENTSERVER_MATRIXRESULT_H
