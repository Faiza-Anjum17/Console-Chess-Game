#include "Queen.h"
#include "Board.h"
#include <stdlib.h>

bool Queen::canMove(const Board& board,
    int fromRow, int fromCol,
    int toRow, int toCol) const {
    int dRow = abs(toRow - fromRow);
    int dCol = abs(toCol - fromCol);

    // Straight like rook
    if (fromRow == toRow || fromCol == toCol) {
        int rowStep = (toRow > fromRow) ? 1 : (toRow < fromRow ? -1 : 0);
        int colStep = (toCol > fromCol) ? 1 : (toCol < fromCol ? -1 : 0);
        int r = fromRow + rowStep;
        int c = fromCol + colStep;
        while (r != toRow || c != toCol) {
            if (board.getPiece(r, c) != nullptr)
                return false;
            r += rowStep;
            c += colStep;
        }
    }
    // Diagonal like bishop
    else if (dRow == dCol && dRow != 0) {
        int rowStep = (toRow > fromRow) ? 1 : -1;
        int colStep = (toCol > fromCol) ? 1 : -1;
        int r = fromRow + rowStep;
        int c = fromCol + colStep;
        while (r != toRow && c != toCol) {
            if (board.getPiece(r, c) != nullptr)
                return false;
            r += rowStep;
            c += colStep;
        }
    }
    else {
        return false; // na rook move, na bishop move
    }

    Piece* target = board.getPiece(toRow, toCol);
    if (target && target->getColor() == color)
        return false;

    return true;
}
