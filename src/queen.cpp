/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 *
 * -----------------------------------------------------------------------------
 *
 * Queen class implementation
 *
 */

#include "chess_piece.hpp"

using namespace ymhChessAI;


Queen::Queen() : ChessPiece() {
}

Queen::Queen(const int& x, const int& y, const Colour& colour) : ChessPiece(x, y, colour) {
}

void Queen::move(const int& x, const int& y) {
}
