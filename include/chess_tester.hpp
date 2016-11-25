#ifndef CHESS_TESTER_HPP
#define CHESS_TESTER_HPP

#define CHESS_TEST_SIZE 7

#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>

struct tested_pieces {
    std::string piece_name;
    int num_passed;
    int num_failed;

    friend bool operator==(const tested_pieces& tp1, const tested_pieces& tp2) {
        if(tp1.piece_name == tp2.piece_name) {
            return true;
        }
        return false;
    }

    friend bool operator<(const tested_pieces& tp1, const tested_pieces& tp2) {
        if(tp1.piece_name < tp2.piece_name) {
            return true;
        }
        return false;
    }
};

class chess_tester {

public:

    // sets all the initial values for the tester
    chess_tester();

    // begins the test suite so that this class can record the results and
    // analyse them
    void chess_begin_test_suite();

    // begins the test
    int chess_begin_test(std::string test_name);

    // records the result of the test
    void chess_end_test(int test_id, bool passed);

    // analyses the results and prints them out
    void chess_end_test_suite();

    // see if the test is acceptable
    bool is_in_arr(const std::string& test_piece) const;

    // see if test is in vector
    bool is_in_vec(const tested_pieces& piece) const;

private:

    // checks if the test suite is running
    bool ts_begin;

    // list of pieces to test
    const std::string chess_test_pieces[CHESS_TEST_SIZE] = {
        "<INTERNAL>",
        "PAWN",
        "ROOK",
        "KNIGHT",
        "BISHOP",
        "QUEEN",
        "KING"
    };

    // vector that contains the tested pieces
    std::vector<tested_pieces> test_piece;

    // the test_id of the current instruction
    int test_id;

    // the test id of the test that has been started
    int test_id_test;

    // the current test that is being tested
    std::string current_test;
};

#endif
