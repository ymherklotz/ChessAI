/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 13/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Knight class implementation
 *
 */

#include "chess_piece.hpp"

using namespace ymhChessAI;


Knight::Knight() : ChessPiece() {
}

Knight::Knight(const int& x, const int& y, const Colour& colour) : ChessPiece(x, y, colour) {
}

void Knight::move(const int& x, const int& y) {
}
