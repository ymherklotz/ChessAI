/*
 *
 * author: Yann Herklotz
 * username: ymherklotz
 * email: ymherklotz@gmail.com
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
	// using the default constructor for the copy constructor
	ChessPiece(const ChessPiece& other) = default;
	// initialise piece at a specific location on the board to save code
	ChessPiece(const int& x, const int& y, const Colour& colour);
	// using default virtual d, const Colour &colourfault;
	virtual ~ChessPiece() = default;

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


// King class that provides the class for the king

class King : public ChessPiece {
public:
	King();
	King(const King& other) = default;
	King(const int& x, const int& y, const Colour& colour);
	~King() = default;

	virtual void move(const int& x, const int& y);
protected:
private:
};

class Queen : public ChessPiece {
public:
	Queen();
	Queen(const Queen& other) = default;
	Queen(const int& x, const int& y, const Colour& colour);
	~Queen() = default;

	virtual void move(const int& x, const int& y);
protected:
private:
};

class Rook : public ChessPiece {
public:
	Rook();
	Rook(const Rook& other) = default;
	Rook(const int& x, const int& y, const Colour& colour);
	~Rook() = default;

	virtual void move(const int& x, const int& y);
protected:
private:
};


class Bishop : public ChessPiece {
public:
	Bishop();
	Bishop(const Bishop &other) = default;
	Bishop(const int& x, const int& y, const Colour& colour);
	~Bishop() = default;

	virtual void move(const int& x, const int& y);
protected:
private:
};

class Knight : public ChessPiece {
public:
	Knight();
	Knight(const Knight& other) = default;
	Knight(const int& x, const int& y, const Colour& colour);
	~Knight() = default;

	virtual void move(const int& x, const int& y);
protected:
private:
};

class Pawn : public ChessPiece {
public:
	Pawn();
	Pawn(const Pawn& other) = default;
	Pawn(const int& x, const int& y, const Colour& colour);
	~Pawn() = default;

	virtual void move(const int& x, const int& y);
protected:
private:
};
};

#endif
