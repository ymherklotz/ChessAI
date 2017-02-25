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
#include "chess_constants.hpp"

#include <iostream>

using namespace ymhChessAI;


ChessBoard::ChessBoard() {
	for(unsigned i = 0; i < ChessConstants::BOARD_SIZE; ++i)
		board.emplace_back(new EmptyPiece);
}

bool ChessBoard::populateBoard() {
	for(auto && piece : board)
		piece = chessPiecePtr(new Knight);
	return true;
}

bool ChessBoard::printBoard() {
	int i = 0;

	for(auto && piece : board) {
		std::cout << i << " ";
		piece->move(1, 2);
		++i;
	}

	return true;
}
