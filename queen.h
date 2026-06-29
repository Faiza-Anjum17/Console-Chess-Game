#pragma once
#include "Piece.h"

class Queen : public Piece {
public:
    Queen(Color c) : Piece(c) {}

    char getSymbol() const override {
        return color == WHITE ? 'Q' : 'q';
    }

    bool canMove(const Board& board,
        int fromRow, int fromCol,
        int toRow, int toCol) const override;
};
