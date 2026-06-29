#pragma once
#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Color c) : Piece(c) {}

    char getSymbol() const override {
        return color == WHITE ? 'B' : 'b';
    }

    bool canMove(const Board& board,
        int fromRow, int fromCol,
        int toRow, int toCol) const override;
};
