#include "chess_piece.hpp"

using namespace ymhChessAI;


// Chess Piece Base class that all the pieces inherit from

ChessPiece::ChessPiece() : m_x(0), m_y(0) {
}

ChessPiece::ChessPiece(const int& x, const int& y) : m_x(x), m_y(y) {
}
