/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 14/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Chess Board class implementation
 *
 */

#include "chess_board.hpp"
#include <iostream>

using namespace ymhChessAI;


ChessBoard::ChessBoard() {
}

void ChessBoard::printBoard() {
	int i = 0;

	for(auto&& piece : board) {
		std::cout << i << " ";
		piece->move(1, 2);
		++i;
	}
}
