#pragma once
#include "Piece.h"

class Knight : public Piece {
public:
    Knight(Color c) : Piece(c) {}

    char getSymbol() const override {
        return color == WHITE ? 'N' : 'n'; // N = kNight
    }

    bool canMove(const Board& board,
        int fromRow, int fromCol,
        int toRow, int toCol) const override;
};
