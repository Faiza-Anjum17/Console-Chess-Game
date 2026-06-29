#include "Knight.h"
#include "Board.h"
#include <stdlib.h> // abs for int

bool Knight::canMove(const Board& board,
    int fromRow, int fromCol,
    int toRow, int toCol) const {
    int dRow = abs(toRow - fromRow);// issue fixed
    int dCol = abs(toCol - fromCol);// issue fixed

    // L-shape check
    bool lShape = (dRow == 2 && dCol == 1) ||
        (dRow == 1 && dCol == 2);
    if (!lShape)
        return false;

    // Target square
    Piece* target = board.getPiece(toRow, toCol);
    if (target && target->getColor() == color)
        return false; // apna piece

    // Knight jumps, so path check ki zarurat nahi
    return true;
}
