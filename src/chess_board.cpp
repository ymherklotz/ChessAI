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
	for(unsigned i = 0; i < BOARD_SIZE; ++i)
		board.emplace_back(new EmptyPiece);
}

void ChessBoard::populateBoard() {
	for(auto&& piece : board)
		piece = chessPiecePtr(new Knight);
}

void ChessBoard::printBoard() {
	int i = 0;

	for(auto&& piece : board) {
		std::cout << i << " ";
		piece->move(1, 2);
		++i;
	}
}