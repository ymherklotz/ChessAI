/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 13/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Pawn class implementation, checking if there is a piece in the way of the
 * one that is currently moving will be the chess boards concern
 *
 * Update: Checking if a piece is in the way will be the concern of this class
 * because the move function has to perform the whole move.
 *
 */

#include "chess_piece.hpp"
#include "chess_constants.hpp"

#include <cmath>

using namespace ymhChessAI;


Pawn::Pawn() : ChessPiece() {
}

Pawn::Pawn(const int& x, const int& y, const Colour& colour) : ChessPiece(x, y, colour) {
}

void Pawn::move(const int& x, const int& y) {
	int move_length = y - (int)m_y;

	// First check what colour the pawn is
	if(m_colour == Colour::White) {
		// if this condition is met the pawn can move
		if(move_length == -2 && m_y == ChessConstants::WHITE_PAWN_ROW) {
			// we now have to check if there is a piece in between the pawn and
			// it's desination
		}
	} else {
	}
}
