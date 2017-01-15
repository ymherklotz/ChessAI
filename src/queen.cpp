/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 13/01/17
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
