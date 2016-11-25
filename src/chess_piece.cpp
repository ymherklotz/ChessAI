#include "chess_ai.hpp"

chess_ai::chess_piece::chess_piece(piece_type type, piece_colour colour) :
    type(type), colour(colour) {

    if(colour == black) {
        y = 0;
    } else {
        y = 7;
    }

    if(type == king) {
        x = 4;
    } else {
        x = 3;
    }
}

chess_ai::chess_piece::chess_piece(piece_type type, piece_colour colour,
                                   unsigned x, unsigned y) :
    type(type), colour(colour), x(x), y(y) {}

chess_ai::chess_piece::~chess_piece() {}

void chess_ai::chess_piece::set_type(piece_type type) {
    this->type = type;
}

void chess_ai::chess_piece::set_colour(piece_colour colour) {
    this->colour = colour;
}

void chess_ai::chess_piece::set_x(unsigned x) {
    this->x = x;
}

void chess_ai::chess_piece::set_y(unsigned y) {
    this->y = y;
}

void chess_ai::chess_piece::set(piece_type type, piece_colour colour,
                                unsigned x, unsigned y) {
    set_type(type);
    set_colour(colour);
    set_x(x);
    set_y(y);
}

std::string chess_ai::chess_piece::str() {
    if(type == empty)
        return " ";
    else if(type == pawn)
        return "p";
    else if(type == rook)
        return "r";
    else if(type == knight)
        return "n";
    else if(type == bishop)
        return "b";
    else if(type == queen)
        return "q";
    return "k";
}
