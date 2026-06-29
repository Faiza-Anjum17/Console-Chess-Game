#include "Rook.h"
#include "Board.h"

bool Rook::canMove(const Board& board,
    int fromRow, int fromCol,
    int toRow, int toCol) const {
    // 1) Rook only moves in straight lines
    if (fromRow != toRow && fromCol != toCol)
        return false;

    // 2) Check path clear between from and to
    int rowStep = (toRow > fromRow) ? 1 : (toRow < fromRow ? -1 : 0);
    int colStep = (toCol > fromCol) ? 1 : (toCol < fromCol ? -1 : 0);

    int r = fromRow + rowStep;
    int c = fromCol + colStep;
    while (r != toRow || c != toCol) {
        if (board.getPiece(r, c) != nullptr)
            return false; // blocked
        r += rowStep;
        c += colStep;
    }

    // 3) Last square: must be empty or enemy
    Piece* target = board.getPiece(toRow, toCol);
    if (target && target->getColor() == color)
        return false;

    return true;
}
