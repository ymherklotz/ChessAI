/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 14/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Chess Board class that will have all the chess pieces on it
 *
 */

#ifndef YMH_CHESS_BOARD_HPP
#define YMH_CHESS_BOARD_HPP

#include "chess_piece.hpp"

#include <vector>
#include <memory>

namespace ymhChessAI {
typedef std::vector<std::unique_ptr<ChessPiece> >::iterator boardIterator;
typedef std::vector<std::unique_ptr<ChessPiece> > boardVector;
typedef std::unique_ptr<ChessPiece> chessPiecePtr;

class ChessBoard {
public:
	ChessBoard();

	void printBoard();
protected:
private:
	static const unsigned BOARD_SIZE = 64;

	boardVector board;
};
}

#endif
