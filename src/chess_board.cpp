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
	board.reserve(CHESS_BOARD_SIZE);

	for(auto&& piece : board)
		piece = std::unique_ptr<ChessPiece>(new King);

	// for(unsigned i = 0; i < CHESS_BOARD_SIZE; ++i)
	//  board.emplace_back(new King);
}

void ChessBoard::printBoard() {
	for(auto&& piece : board) {
		piece->move(1, 2);
		std::cout << "Hello" << std::endl;
	}
}
