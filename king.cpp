#include "King.h"
#include "Board.h"
#include <stdlib.h>
bool King::canMove(const Board& board,
    int fromRow, int fromCol,
    int toRow, int toCol) const {
    int dRow = abs(toRow - fromRow);
    int dCol = abs(toCol - fromCol);

    // King can move 1 square any direction
    if (dRow > 1 || dCol > 1 || (dRow == 0 && dCol == 0))
        return false;

    // Can't land on same-color piece
    Piece* target = board.getPiece(toRow, toCol);
    if (target && target->getColor() == color)
        return false;

    // (Check, castling, etc. handle later)
    return true;
}
