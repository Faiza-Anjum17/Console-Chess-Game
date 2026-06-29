#pragma once
#include "Piece.h"

class Rook : public Piece {
public:
    Rook(Color c) : Piece(c) {}

    char getSymbol() const override {
        return color == WHITE ? 'R' : 'r';
    }

    bool canMove(const Board& board,
        int fromRow, int fromCol,
        int toRow, int toCol) const override;
};
