#ifndef CHESS_AI_HPP
#define CHESS_AI_HPP

#define CHESS_BOARD_SIZE 8

#include <vector>
#include <iostream>
#include <string>

namespace chess_ai {

    // Describes the different types of chess pieces there are on the board
    enum piece_type : unsigned;
    
    // Describes the colour of the pieces
    enum piece_colour : unsigned;
    
    // just describes if the board is full or empty
    enum board_state : unsigned;

    // defines the errors that can happen when moving a piece
    enum movement_flag : unsigned;
    
    // The chess board that will be played on
    class chess_board;

    // Any chess piece in the game
    class chess_piece;

    // typedefs for iterators to access elements easier
    typedef std::vector<std::vector<chess_ai::chess_piece>>::
iterator vector_iterator;
    typedef std::vector<chess_ai::chess_piece>::iterator square_iterator;

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

    enum piece_colour : unsigned {
        // Looking at the board white will be at the bottom
        white,
        // Black will be at the top
        black,
        // no colour
        none
    };

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

    enum movement_flag : unsigned {
        // when king is in check there are limited possibilities
        move_error_KingInCheckAfterMove,
        // when there is a friendly piece in the way
        move_error_FriendlyPieceOnDestination,
        // when there is an enemy piece blocking the way
        move_error_EnemyPieceOnDestination,
        // illegal move for chose piece
        move_error_IllegalMove,

        // when the move is successful
        move_Success,
        // when a move leads to a check
        move_Check,
        // when a move leads to a checkmate
        move_Checkmate,
    };

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

        // move a piece according to the chess rules
        movement_flag move_piece(chess_piece piece);
        movement_flag move_piece(unsigned x, unsigned y);
        movement_flag move_piece(unsigned orig_x, unsigned orig_y, unsigned dest_x,
                                 unsigned dest_y);
        movement_flag move_piece(unsigned orig_x, unsigned orig_y, unsigned dest_x,
                                 unsigned dest_y, chess_piece& taken_piece);
        movement_flag move_piece(chess_piece piece, unsigned x, unsigned y);

        // iterate through the list and return the pointer to change
        square_iterator& iterate_board(square_iterator& it, unsigned x, unsigned y);

        
    private:

        // initialises vector
        void init_board_vector();

        // moves the pawn
        movement_flag move_pawn(square_iterator it, square_iterator new_it,
                                chess_piece& taken_piece);
        
        // The size of the chess board is a constant and hence defined by a
        // preprocessed define statement.
        const unsigned SIZE;

        // The actual board where the values of the pieces will be changed.
        std::vector<std::vector<chess_piece>> grid;
    };

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

        // return a printable version of the square
        std::string str();
        
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
