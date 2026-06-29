#pragma once
#include "Piece.h"
#include "Board.h" // if pawn needs to inspect board
class Board; // forward declare
class Pawn : public Piece {
public:
    Pawn(Color c) : Piece(c) {}

    char getSymbol() const override {
        return color == WHITE ? 'P' : 'p';
    }

    bool canMove(const Board& board, int fromRow, int fromCol, int toRow, int toCol) const override;
};
