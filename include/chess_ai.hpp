#ifndef CHESS_AI_HPP
#define CHESS_AI_HPP

#define CHESS_BOARD_SIZE 8

#include <vector>
#include <iostream>
#include <string>

namespace chess_ai {

    enum piece_type : unsigned;
    enum piece_colour : unsigned;
    enum board_state : unsigned;
    class chess_board;
    class chess_piece;

    // Describes the different types of chess pieces there are on the board
    enum piece_type : unsigned {
        // A pawn can only move forward twice on the first move, otherwise only
        // once. It only take pieces that are on the diagonals in front of it,
        // or through en passant.
        // They are chess_initially placed as a line in front of the other pieces.
        pawn,

        // A rook can only move vertically or horizontally and they are placed
        // in the corners of the board.
        rook,

        // A knight can only move to 8 locations around it which are specified
        // by moving twice horizontally or vertically in a row and once
        // diagonally. These are placed next to the rook.
        knight,

        // A Bishop can only move diagonally and are placed next to the knight
        bishop,

        // The queen combines the bishop and the rook and is placed on either
        // d1 or d8
        queen,

        // The king moves like the queen but only for one square and is placed
        // on e1 or e8
        king,

        // empty square
        empty
    };

    // Describes the colour of the pieces
    enum piece_colour : unsigned {
        // Looking at the board white will be at the bottom
        white,
        // Black will be at the top
        black,
        // no colour
        none
    };

    // just describes if the board is full or empty
    enum board_state : unsigned {
        // The starting position of the board with all pieces in the right
        // position
        initial,
        // While the game is going this will be the state
        playing,
        // When the game is over
        finished,
        // When the board is completely empty
        clear
    };

    // The chess board that will be played on
    class chess_board {
    public:

        // Create an empty chess board
        chess_board();

        // Create a chess board depending on the state
        chess_board(board_state state);
        
        // prints the current board state
        void print_board();

        // Set a piece somewhere on the board replacing anything that was there
        // previously
        void set_piece(chess_piece piece);

        // removes a piece from the board at location
        void remove_piece(chess_piece piece);

        // remove piece at a specific location only
        void remove_piece(unsigned x, unsigned y);
        
    protected:

        void init_board_vector();
        
    private:
        
        // The size of the chess board is a constant and hence defined by a
        // preprocessed define statement.
        unsigned const SIZE = CHESS_BOARD_SIZE;

        // The actual board where the values of the pieces will be changed.
        std::vector<std::vector<chess_piece>> grid;
    };

    // Any chess piece in the game
    class chess_piece {
        friend class chess_board;
    public:
        
        // Initialises the chess piece to an empty square on the board 
        chess_piece() : type(empty), colour(none), x(0), y(0) {}

        // Otherwise initialise the chess piece to a king or queen where the
        // location is alreay known
        chess_piece(piece_type type, piece_colour colour);

        // Finally initialise the chess piece to a specified piece
        chess_piece(piece_type type, piece_colour colour, unsigned x,
                    unsigned y);

        // Set the type of the chess_piece
        void set_type(piece_type type);

        // set the colour of the piece
        void set_colour(piece_colour colour);

        // set the x coordinate of the piece
        void set_x(unsigned x);

        // set the y coordinate of the piece
        void set_y(unsigned y);

        // set the different values
        void set(piece_type type, piece_colour colour, unsigned x, unsigned y);

        // overloading operators

        // so that we can make two copies of a point
        chess_piece& operator==(const chess_piece& piece) {
            if(this != &piece) {
                this->set(piece.type, piece.colour, piece.x, piece.y);
            }
            return *this;
        }

        // overload ++ operator for pawns
        chess_piece& operator++() {
            return *this;
        }

        chess_piece operator++(int) {
            chess_piece tmp(*this);
            operator++();
            return tmp;
        }

        // return a printable version of the square
        std::string str();
        
    protected:
    private:

        // Type of the chess piece, eg. bishop or queen
        piece_type type;

        // Colour of the chess piece
        piece_colour colour;
        
        // x location of the chess piece
        unsigned x;
        
        // y location of the chess piece
        unsigned y;
    };
}

#endif
