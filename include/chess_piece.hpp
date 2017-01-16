/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
 * date created: 13/01/17
 *
 * -----------------------------------------------------------------------------
 *
 * Chess Piece class with header for all the pieces as well that inherit
 * from the Chess Piece class.
 *
 */

#ifndef YMH_CHESS_PIECE_HPP
#define YMH_CHESS_PIECE_HPP


// defining seperate namespace so that I don't have to worry with duplicate
// names

namespace ymhChessAI {
// Colour enum class so that we can have the colours in the Chess Piece and not
// using normal enums because of undefined errors

enum class Colour {
	White,
	Black
};


// Base Chess Piece class that is inherited by all other chess pieces

class ChessPiece {
public:
	// constructor sets the initial position of the chess piece to 0, 0
	ChessPiece();
	// initialise piece at a specific location on the board to save code
	ChessPiece(const int& x, const int& y, const Colour& colour);

	// pure virtual function to move a piece as it depends completely on the
	// implementation of the piece
	virtual void move(const int& x, const int& y) = 0;
protected:
	// current location of the piece which is protected as it can still be
	// inherited by the piece classes
	int m_x, m_y;

	// defines what colour the piece is
	Colour m_colour;
};


// King class

class King : public ChessPiece {
public:
	King();
	King(const int& x, const int& y, const Colour& colour);

	virtual void move(const int& x, const int& y);
protected:
private:
};


// Queen class

class Queen : public ChessPiece {
public:
	Queen();
	Queen(const int& x, const int& y, const Colour& colour);

	virtual void move(const int& x, const int& y);
protected:
private:
};


// Rook class

class Rook : public ChessPiece {
public:
	Rook();
	Rook(const int& x, const int& y, const Colour& colour);

	virtual void move(const int& x, const int& y);
protected:
private:
};


// Bishop class

class Bishop : public ChessPiece {
public:
	Bishop();
	Bishop(const int& x, const int& y, const Colour& colour);

	virtual void move(const int& x, const int& y);
protected:
private:
};


// Knight class

class Knight : public ChessPiece {
public:
	Knight();
	Knight(const int& x, const int& y, const Colour& colour);

	virtual void move(const int& x, const int& y);
protected:
private:
};


// Pawn class

class Pawn : public ChessPiece {
public:
	Pawn();
	Pawn(const int& x, const int& y, const Colour& colour);

	virtual void move(const int& x, const int& y);
protected:
private:
};
}

#endif
