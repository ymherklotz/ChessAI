/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 13/01/17
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
