/*

  description: This is the test_bench file for the chess_ai

  author: Yann Herklotz <ymherklotz@gmail.com>
  date created: DD-MM-YYYY

 */

#include "chess_ai.hpp"
#include "chess_tester.hpp"

#include <iostream>

using namespace std;
using namespace chess_ai;

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    int test_id;
    bool passed;

    chess_tester test_bench;

    chess_board empty_board(clear);
    chess_board initial_board(initial);

    test_bench.chess_begin_test_suite();

    test_id = test_bench.chess_begin_test("PAWN");
    chess_piece piece(pawn, white, 1, 6);
    empty_board.set_piece(piece);
    empty_board.print_board();
    cout << empty_board.move_piece(1, 6, 1, 4) << endl;
    piece.set(pawn, white, 1, 4);
    if(empty_board.at(1, 4) == piece)
        passed = true;
    else
        passed = false;
    empty_board.print_board();
    test_bench.chess_end_test(test_id, passed);

    test_bench.chess_end_test_suite();

    return 0;
}
