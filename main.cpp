#include "board.h"
#include <iostream>
#include <string>
using namespace std;

enum Turn { TURN_WHITE, TURN_BLACK };

// helper: "e2" -> row, col
bool parseSquare(const string& sq, int& row, int& col) {
    if (sq.size() != 2) return false;

    char file = sq[0];  // 'a'..'h'
    char rank = sq[1];  // '1'..'8'

    if (file < 'a' || file > 'h') return false;
    if (rank < '1' || rank > '8') return false;

    col = file - 'a';           // a->0 ... h->7
    int rankNum = rank - '0';   // '1'->1 ... '8'->8
    row = 8 - rankNum;          // rank 8 -> row 0, rank 1 -> row 7

    return true;
}

int main() {
    Board board;
    board.setupInitial();
    board.print();

    Turn currentTurn = TURN_WHITE;

    while (true) {
        cout << (currentTurn == TURN_WHITE ? "White" : "Black")
            << " to move.\n";

        string fromSq, toSq;
        cout << "Enter move (e.g. e2 e4, or 'exit'): ";
        cin >> fromSq;
        if (!cin || fromSq == "exit") break;
        cin >> toSq;

        int fr, fc, tr, tc;
        if (!parseSquare(fromSq, fr, fc) || !parseSquare(toSq, tr, tc)) {
            cout << "Invalid square format. Use like e2 e4.\n";
            continue;
        }

        Piece* p = board.getPiece(fr, fc);
        if (!p) {
            cout << "No piece at " << fromSq << ".\n";
            continue;
        }

        Color c = p->getColor();
        if ((currentTurn == TURN_WHITE && c != WHITE) ||
            (currentTurn == TURN_BLACK && c != BLACK)) {
            cout << "Not your piece.\n";
            continue;
        }

        bool ok = board.movePiece(fr, fc, tr, tc);
        cout << (ok ? "Move OK\n" : "Move FAILED\n");
        board.print();

        if (!ok) continue;

        // Optional: check alert ( Board::isKingInCheck implemented)
        /*
        Color enemy = (currentTurn == TURN_WHITE ? BLACK : WHITE);
        if (board.isKingInCheck(enemy)) {
            cout << (enemy == WHITE ? "White" : "Black")
                 << " king is IN DANGER (check)!\n";
        }
        */

        currentTurn = (currentTurn == TURN_WHITE ? TURN_BLACK : TURN_WHITE);
    }

    return 0;
}
