/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 *
 * -----------------------------------------------------------------------------
 *
 * Bishop class implementation
 *
 */

#include "chess_piece.hpp"

using namespace ymhChessAI;


Bishop::Bishop() : ChessPiece() {
}

Bishop::Bishop(const int& x, const int& y, const Colour& colour) : ChessPiece(x, y, colour) {
}

void Bishop::move(const int& x, const int& y) {
}
