/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 *
 * -----------------------------------------------------------------------------
 *
 * Rook class implementation
 *
 */

#include "chess_piece.hpp"

using namespace ymhChessAI;


Rook::Rook() : ChessPiece() {
}

Rook::Rook(const int& x, const int& y, const Colour& colour) : ChessPiece(x, y, colour) {
}

void Rook::move(const int& x, const int& y) {
}
