//
// Created by eyal & tomer on 1/15/19.
//

#ifndef CLIENTSERVER_EMPIRICALEXPERIMENT_H
#define CLIENTSERVER_EMPIRICALEXPERIMENT_H

#include <vector>
#include "Solvers/Solver.h"
#include "Solvers/StringReverser.h"
#include "CacheManagers/CacheManager.h"
#include "CacheManagers/FileCacheManager.h"
#include "Solvers/SearchSolver.h"
#include "Algorithms/BreadthFirstSearch.h"
#include "Algorithms/DepthFirstSearch.h"
#include "Algorithms/BestFirstSearch.h"
#include "Algorithms/AStar.h"
#include <string>

using namespace std;

class EmpiricalExperiment {
    vector<vector<string>> randomMatrix(int row, int col) {
        vector<vector<string>> matrix;
        for (int i = 0; i < row; ++i) {
            vector<string> row_vec;
            for (int j = 0; j < col; ++j) {
                int r = rand() % 5;
                if (r == 0) r = 1;
                if (i == j && i % 2 == 0) r = -1;
                row_vec.push_back(to_string(r));
            }
            matrix.push_back(row_vec);
        }
        matrix[row - 1][col - 1] = to_string(rand() % 10 + 1);
        matrix[0][0] = to_string(rand() % 10 + 1);
        matrix.push_back({"0", "0"});
        matrix.push_back({to_string(row - 1), to_string(col - 1)});
        return matrix;
    }

    void writeMatrix(vector<vector<string>> matrix, fstream &graphs) {
        for (int i = 0; i < matrix.size() - 2; i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (j != matrix[0].size() - 1) {
                    graphs << matrix[i][j] << ",";
                } else {
                    graphs << matrix[i][j];
                }
            }
            graphs << "\n";
        }
    }

public:
    void testAndWriteToFiles() {
        // save to file each problem and solution.
        fstream graphs, solutions;
        graphs.open("graphs.txt", std::ofstream::out | std::ofstream::trunc);
        solutions.open("solutions.txt", std::ofstream::out | std::ofstream::trunc);
        int i = 40, j = 40;
        graphs << "10\n";
        auto *bfs = new BreadthFirstSearch<pair<int, int>>();
        auto *dfs = new DepthFirstSearch<pair<int, int>>();
        auto *astar = new AStar<pair<int, int>>();
        auto *bestfirst = new BestFirstSearch<pair<int, int>>();
        for (i; i <= 50; i += 5, j += 5) {
            graphs << to_string(i) << endl;
            graphs << "0,0" << endl;
            graphs << to_string(i - 1) << "," << to_string(i - 1) << endl;
            vector<vector<string>> matrix = randomMatrix(i, j);
            writeMatrix(matrix, graphs);

            auto *searchSolver1 = new SearchSolver<pair<int, int>, string>(bestfirst);
            auto *searchSolver2 = new SearchSolver<pair<int, int>, string>(dfs);
            auto *searchSolver3 = new SearchSolver<pair<int, int>, string>(bfs);
            auto *searchSolver4 = new SearchSolver<pair<int, int>, string>(astar);

            string res1 = searchSolver1->solve(matrix);
            string res2 = searchSolver2->solve(matrix);
            string res3 = searchSolver3->solve(matrix);
            string res4 = searchSolver4->solve(matrix);
            solutions << to_string(bestfirst->getNumOfNodesEvaluated()) << ","
                      << to_string(bestfirst->getSolutionSize())
                      << endl;
            solutions << to_string(dfs->getNumOfNodesEvaluated()) << "," << to_string(dfs->getSolutionSize()) << endl;
            solutions << to_string(bfs->getNumOfNodesEvaluated()) << "," << to_string(bfs->getSolutionSize()) << endl;
            solutions << to_string(astar->getNumOfNodesEvaluated()) << "," << to_string(astar->getSolutionSize())
                      << endl;

            // free solvers
            delete(searchSolver1);
            delete(searchSolver2);
            delete(searchSolver3);
            delete(searchSolver4);
        }
        graphs.close();
        solutions.close();
        // free algs
        delete(bfs);
        delete(dfs);
        delete(astar);
        delete(bestfirst);

    }
};


#endif //CLIENTSERVER_EMPIRICALEXPERIMENT_H
