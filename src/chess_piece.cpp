/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 13/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Chess Piece class implementation
 *
 */

#include "chess_piece.hpp"

using namespace ymhChessAI;


ChessPiece::ChessPiece() : m_x(0), m_y(0), m_colour(Colour::White) {
}

ChessPiece::ChessPiece(const int& x, const int& y, const Colour& colour) : m_x(x), m_y(y), m_colour(colour) {
}

EmptyPiece::EmptyPiece() : ChessPiece() {
}

EmptyPiece::EmptyPiece(const int& x, const int& y) : ChessPiece(x, y, Colour::None) {
}

void EmptyPiece::move(const int& x, const int& y) {
}
