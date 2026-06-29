#include "Pawn.h"
#include "Board.h"
#include <stdlib.h>   // abs for int

bool Pawn::canMove(const Board& board,
    int fromRow, int fromCol,
    int toRow, int toCol) const {
    int direction = (color == WHITE) ? -1 : 1;
    int startRow = (color == WHITE) ? 6 : 1;

    if (fromCol == toCol &&
        toRow - fromRow == direction &&
        board.getPiece(toRow, toCol) == nullptr) {
        return true;
    }

    if (fromCol == toCol &&
        fromRow == startRow &&
        toRow - fromRow == 2 * direction &&
        board.getPiece(fromRow + direction, fromCol) == nullptr &&
        board.getPiece(toRow, toCol) == nullptr) {
        return true;
    }

    if (abs(fromCol - toCol) == 1 &&
        toRow - fromRow == direction) {
        Piece* target = board.getPiece(toRow, toCol);
        if (target && target->getColor() != color)
            return true;
    }

    return false;
}
