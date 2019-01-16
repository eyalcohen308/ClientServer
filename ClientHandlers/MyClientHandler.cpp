//
// Created by tomer on 1/13/19.
//

#include "MyClientHandler.h"

/**
 * get (read) data from socket
 * @param sock_id
 * @return problem in string
 */
string MyClientHandler::getData(int sock_id) {
    string curr_line;
    string problem;
    while (true) { // condition to stop- inside
        curr_line = getLineFromSocket(sock_id);
        problem += curr_line;
        if (curr_line.find("end") != std::string::npos) {
            break;
        }
    }
    return problem;
}

/**
 * lexer
 * with regex
 * @param input
 * @return
 */
vector<vector<string>> MyClientHandler::lexer(string input) {
    vector<vector<string >> after_lex;
    vector<string> vec_lex;
    string temp;
    regex number("[0-9.]*");
    smatch match_results;
    while (input.size() > 0) { // have more to read
        if (input[0] == '\n') {
            input = input.substr(1, input.size());
            after_lex.push_back(vec_lex);
            temp = ""; // clear to list
            vec_lex.clear();
        } else if ((input[0] >= 48 && input[0] < 58)) {
            // if valid number or minus
            regex_search(input, match_results, number);
            for (unsigned i = 0; i < match_results.size(); ++i) {
                // TODO check the +=
                temp += temp + match_results.str(i);
            }
            vec_lex.push_back(temp);
            input = input.substr(temp.size(), input.size());
            temp = ""; // clear to list
        } else if ((input[0] >= 65 && input[0] <= 90) || (input[0] >= 97 && input[0] <= 122)) {
            // if a char- "end" - return and finish
            return after_lex;
        } else if (input[0] == 45) {

            temp = "-1";
            vec_lex.push_back(temp);
            input = input.substr(temp.size(), input.size());
            temp = "";

        } else {
            temp = ""; // clear to list
            input = input.substr(1, input.size());
        }
    }
    return after_lex;
}

/**
 * handle client
 * get problem and check if you have saved solution
 * if have - get it and write it
 * else - solve, save the solution and write it
 * @param sock_id
 */
void MyClientHandler::handleClient(int sock_id) {
    string solution;
    string problem;
    vector<vector<string>> data;
    problem = getData(sock_id);
    string problem_to_lexer = problem;

    // arrange the string problem
    replace(problem.begin(), problem.end(), '\n', '$');
    if (problem.back() == '$') { // take out the last $
        problem.pop_back();
    }

    // if we have the solution (saved)
    if (this->cache_Manager->hasSolutionTo(problem)) {
        // write the solution and return
        solution = this->cache_Manager->getSolutionTo(problem);
        writeSolutionToSocket(solution, sock_id);
        return;
    }

    // else - find solution
    data = this->lexer(problem_to_lexer);
    solution = solver->solve(data);
    // the solution isn't saved already- save, write and return
    this->cache_Manager->saveSolutionFor(problem, solution);
    writeSolutionToSocket(solution, sock_id);
}

/**
 * write Solution To Socket
 * @param sol
 * @param sock_id
 */
void MyClientHandler::writeSolutionToSocket(string sol, int sock_id) {
    const char *solution = sol.c_str();
    int n = write(sock_id, solution, strlen(solution));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

/**
 * get Line From Socket
 * @param sock_id
 * @return
 */
string MyClientHandler::getLineFromSocket(int sock_id) {
    char buf[CHARS_TO_BUFFER];
    ssize_t readen_bytes;
    readen_bytes = read(sock_id, buf, CHARS_TO_BUFFER - 1);
    if (readen_bytes < 0) {
        __throw_bad_exception();
    } else if (readen_bytes == 0) {
        //connection closed
    } else {
        buf[readen_bytes] = NULL;
    }
    return buf;
}
