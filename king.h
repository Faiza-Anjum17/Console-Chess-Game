#pragma once
#include "Piece.h"

class King : public Piece {
public:
    King(Color c) : Piece(c) {}

    char getSymbol() const override {
        return color == WHITE ? 'K' : 'k';
    }

    bool canMove(const Board& board,
        int fromRow, int fromCol,
        int toRow, int toCol) const override;
};
