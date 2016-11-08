#include "../include/chess_ai.hpp"

chess_ai::chess_board::chess_board() : SIZE(CHESS_BOARD_SIZE) {
    init_board_vector();
}

chess_ai::chess_board::chess_board(board_state state) : SIZE(CHESS_BOARD_SIZE){
    unsigned vec_index, sqr_index;

    init_board_vector();
    
    if(state == initial) {

        for(vector_iterator it_vec = grid.begin(); it_vec != grid.end();
            ++it_vec) {
            
            for(square_iterator it_sqr = (*it_vec).begin();
                it_sqr != (*it_vec).end(); ++it_sqr) {
                chess_piece piece;

                piece_colour colour;
                    
                if(vec_index < 3) {
                    colour = black;
                } else {
                    colour = white;
                }
                
                vec_index = it_vec - grid.begin();
                sqr_index = it_sqr - (*it_vec).begin();
                
                if(vec_index == 1 || vec_index == 6) {
                    piece.set_type(pawn);
                } else if(vec_index == 0 || vec_index == 7) {

                    if(sqr_index == 0 || sqr_index == 7)
                        piece.set_type(rook);
                    else if(sqr_index == 1 || sqr_index == 6)
                        piece.set_type(knight);
                    else if(sqr_index == 2 || sqr_index == 5)
                        piece.set_type(bishop);
                    else if(sqr_index == 3)
                        piece.set_type(queen);
                    else if(sqr_index == 4)
                        piece.set_type(king);
                }

                piece.set_colour(colour);
                piece.set_x(sqr_index);
                piece.set_y(vec_index);
                
                *it_sqr = piece;
            }
        }
    } else {
        for(auto& row : grid) {
            for(auto& square : row) {
                chess_piece piece;
                square = piece;
            }
        }
    }
}

void chess_ai::chess_board::init_board_vector() {
    for(unsigned i = 0; i < SIZE; ++i) {
        std::vector<chess_ai::chess_piece> tmp_vec;
        for(unsigned j = 0; j < SIZE; ++j) {
            chess_piece piece;
            tmp_vec.push_back(piece);
        }
        grid.push_back(tmp_vec);
    }
}

void chess_ai::chess_board::print_board() {
    std::cout << "  |";
    for(unsigned i = 0; i < SIZE; ++i) {
        std::cout << "---|";
    }
    std::cout << std::endl << "8 |";
    
    for(unsigned y = 0; y < SIZE; ++y) {
        for(unsigned x = 0; x < SIZE; ++x) {
            std::cout << " " << grid[y][x].str() << " |";
        }
        
        std::cout << std::endl << "  |";
        

        if(y == SIZE-1) {
            std::cout << "---+";
            for(unsigned i = 0; i < SIZE-2; ++i) {
                std::cout << "---+";
            }
            std::cout << "---|" << std::endl;
        } else {
            for(unsigned i = 0; i < SIZE-1; ++i) {
                std::cout << "---+";
            }
            std::cout << "---|" << std::endl;
            std::cout << 7-y << " |";
        }
    }
    std::cout << "    a   b   c   d   e   f   g   h" << std::endl;
}

void chess_ai::chess_board::set_piece(chess_piece piece) {
    square_iterator it_sqr;
    *iterate_board(it_sqr, piece.x, piece.y) = piece;
}

void chess_ai::chess_board::remove_piece(chess_piece piece) {
    remove_piece(piece.x, piece.y);
}

void chess_ai::chess_board::remove_piece(unsigned x, unsigned y) {
    square_iterator it_sqr;
    *iterate_board(it_sqr, x, y) = chess_piece();
}

void chess_ai::chess_board::move_piece(chess_piece piece) {
    move_piece(piece.x, piece.y);
}

void chess_ai::chess_board::move_piece(unsigned x, unsigned y) {
    square_iterator it;
    iterate_board(it, x, y);

    ++(*it);
}

void chess_ai::chess_board::move_piece(chess_ai::chess_piece piece,
                                       unsigned x, unsigned y) {
    move_piece(piece.x, piece.y, x, y);
}

void chess_ai::chess_board::move_piece(unsigned orig_x, unsigned orig_y,
                                       unsigned dest_x, unsigned dest_y) {
    
}

chess_ai::square_iterator& chess_ai::chess_board::iterate_board(
                     square_iterator& it, unsigned x, unsigned y) {
    unsigned vec_index, sqr_index;
    for(vector_iterator it_vec = grid.begin(); it_vec != grid.end(); ++it_vec) {
        for(square_iterator it_sqr = (*it_vec).begin();
            it_sqr != (*it_vec).end(); ++it_sqr) {
            vec_index = it_vec - grid.begin();
            sqr_index = it_sqr - (*it_vec).begin();
            
            if(vec_index == y && sqr_index == x) {
                it = it_sqr;
                return it;
            }
        }
    }
    return it;
}
