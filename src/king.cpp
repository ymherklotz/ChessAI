/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 13/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * King class implementation
 *
 */

#include "chess_piece.hpp"
#include <iostream>

using namespace ymhChessAI;


King::King() : ChessPiece() {
}

King::King(const int& x, const int& y, const Colour& colour) : ChessPiece(x, y, colour) {
}

void King::move(const int& x, const int& y) {
	std::cout << "This is the king" << std::endl;
}
