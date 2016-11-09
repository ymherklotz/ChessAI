/*

  description:

  author: Yann Herklotz <ymherklotz@gmail.com>
  date created: DD-MM-YYYY

 */

#include "../include/chess_ai.hpp"

#include <iostream>

using namespace std;
using namespace chess_ai;

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    chess_board board(initial);
    board.print_board();

    chess_piece piece(rook, white, 5, 3);
    board.set_piece(piece);

    board.print_board();

    board.remove_piece(5, 3);
    
    board.print_board();

    board.move_piece(4, 6, 4, 4);
    board.move_piece(4, 1, 4, 3);
    board.move_piece(3, 6, 3, 5);
    
    board.print_board();
    
    return 0;
}
