/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 *
 * -----------------------------------------------------------------------------
 *
 * King class implementation
 *
 */

#include "chess_piece.hpp"

using namespace ymhChessAI;


King::King() : ChessPiece() {
}

King::King(const int& x, const int& y, const Colour& colour) : ChessPiece(x, y, colour) {
}

void King::move(const int& x, const int& y) {
}
