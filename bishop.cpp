#include "Bishop.h"
#include "Board.h"
#include <stdlib.h>
bool Bishop::canMove(const Board& board,
    int fromRow, int fromCol,
    int toRow, int toCol) const {
    int dRow = abs(toRow - fromRow);
    int dCol = abs(toCol - fromCol);

    // 1) Diagonal move condition
    if (dRow != dCol || dRow == 0) // no move or not diagonal
        return false;

    // 2) Path clear check
    int rowStep = (toRow > fromRow) ? 1 : -1;
    int colStep = (toCol > fromCol) ? 1 : -1;

    int r = fromRow + rowStep;
    int c = fromCol + colStep;
    while (r != toRow && c != toCol) {
        if (board.getPiece(r, c) != nullptr)
            return false; // blocked
        r += rowStep;
        c += colStep;
    }

    // 3) Final square: must not contain same-color piece
    Piece* target = board.getPiece(toRow, toCol);
    if (target && target->getColor() == color)
        return false;

    return true;
}
