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
class ChessPiece {
public:
	ChessPiece();
	ChessPiece(const ChessPiece& other) = default;
	ChessPiece(const int& x, const int& y);
	virtual ~ChessPiece() = default;

	virtual void move(const int& x, const int& y) = 0;
protected:
	int m_x, m_y;
private:
};

class King : public ChessPiece {
public:
	King();
	King(const King& other) = default;
	King(const int& x, const int& y);
	~King() = default;

	void move(const int& x, const int& y);
protected:
private:
};

class Queen : public ChessPiece {
public:
	Queen();
	Queen(const Queen& other) = default;
	Queen(const int& x, const int& y);
	~Queen() = default;

	void move(const int& x, const int& y);
protected:
private:
};

class Rook : public ChessPiece {
public:
	Rook();
	Rook(const Rook& other) = default;
	Rook(const int& x, const int& y);
	~Rook() = default;

	void move(const int& x, const int& y);
protected:
private:
};

class Bishop : public ChessPiece {
public:
	Bishop();
	Bishop(const Bishop& other) = default;
	Bishop(const int& x, const int& y);
	~Bishop() = default;

	void move(const int& x, const int& y);
protected:
private:
};

class Knight : public ChessPiece {
public:
	Knight();
	Knight(const Knight& other) = default;
	Knight(const int& x, const int& y);
	~Knight() = default;

	void move(const int& x, const int& y);
protected:
private:
};

class Pawn : public ChessPiece {
public:
	Pawn();
	Pawn(const Pawn& other) = default;
	Pawn(const int& x, const int& y);
	~Pawn() = default;

	void move(const int& x, const int& y);
protected:
private:
};
};

#endif
