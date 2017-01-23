/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 13/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Pawn class implementation
 *
 */

#include "chess_piece.hpp"
#include "chess_constants.hpp"

using namespace ymhChessAI;


Pawn::Pawn() : ChessPiece() {
}

Pawn::Pawn(const int& x, const int& y, const Colour& colour) : ChessPiece(x, y, colour) {
}

void Pawn::move(const int& x, const int& y) {
	if(m_colour == Colour::White) {
		if(m_y == ChessConstants::WHITE_PAWN_ROW) {
		}
	} else {
		if(m_y == ChessConstants::BLACK_PAWN_ROW) {
		}
	}
}
