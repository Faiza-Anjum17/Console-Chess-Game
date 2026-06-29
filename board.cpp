#include "board.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include <iostream>
#include <windows.h>   // console colors
using namespace std;

// helper: set console text attributes
static void setColor(WORD attr) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr);
}

Board::Board() {
    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c)
            grid[r][c] = nullptr;
}

Board::~Board() {
    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c) {
            delete grid[r][c];
            grid[r][c] = nullptr;
        }
}

void Board::setupInitial() {
    // Clear board
    for (int r = 0; r < 8; ++r)
        for (int c = 0; c < 8; ++c)
            grid[r][c] = nullptr;

    // Pawns
    for (int c = 0; c < 8; ++c) {
        grid[6][c] = new Pawn(WHITE); // white pawns
        grid[1][c] = new Pawn(BLACK); // black pawns
    }

    // Rooks
    grid[7][0] = new Rook(WHITE);
    grid[7][7] = new Rook(WHITE);
    grid[0][0] = new Rook(BLACK);
    grid[0][7] = new Rook(BLACK);

    // Knights
    grid[7][1] = new Knight(WHITE);
    grid[7][6] = new Knight(WHITE);
    grid[0][1] = new Knight(BLACK);
    grid[0][6] = new Knight(BLACK);

    // Bishops
    grid[7][2] = new Bishop(WHITE);
    grid[7][5] = new Bishop(WHITE);
    grid[0][2] = new Bishop(BLACK);
    grid[0][5] = new Bishop(BLACK);

    // Queens
    grid[7][3] = new Queen(WHITE);
    grid[0][3] = new Queen(BLACK);

    // Kings
    grid[7][4] = new King(WHITE);
    grid[0][4] = new King(BLACK);
}

void Board::print() const {
    setColor(7);
    cout << "      a  b  c  d  e  f  g  h\n";

    // color setup
    WORD bgLight = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;   // cream (light)
    WORD bgDark = BACKGROUND_RED | BACKGROUND_GREEN;                          // brown (dark)

    WORD fgWhitePieces = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY; // bright white
    WORD fgBlackPieces = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;                        // grey

    for (int r = 0; r < 8; ++r) {
        setColor(7);
        cout << "  " << (8 - r) << "  ";

        for (int c = 0; c < 8; ++c) {
            bool dark = ((r + c) % 2 == 1);
            WORD bg = dark ? bgDark : bgLight;

            if (grid[r][c]) {
                Color col = grid[r][c]->getColor();
                if (col == WHITE)
                    setColor(bg | fgWhitePieces);
                else
                    setColor(bg | fgBlackPieces);

                cout << ' ' << grid[r][c]->getSymbol() << ' ';
            }
            else {
                setColor(bg);
                cout << "   ";
            }
        }

        setColor(7);
        cout << "  " << (8 - r) << "\n";
    }

    setColor(7);
    cout << "      a  b  c  d  e  f  g  h\n";
}

bool Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    Piece* p = grid[fromRow][fromCol];
    if (!p) {
        cout << "No piece at source\n";
        return false;
    }

    if (!p->canMove(*this, fromRow, fromCol, toRow, toCol)) {
        cout << "Invalid move for that piece\n";
        return false;
    }

    Piece* target = grid[toRow][toCol];
    if (target && target->getColor() == p->getColor()) {
        cout << "Cannot capture own piece\n";
        return false;
    }

    bool capturedKing = false;
    if (target) {
        char sym = target->getSymbol();
        Color col = target->getColor();
        cout << "Captured piece: " << sym
            << " (" << (col == WHITE ? "White" : "Black") << ")\n";

        if (dynamic_cast<King*>(target) != nullptr) {
            capturedKing = true;
            cout << "King captured! Game over.\n";
        }

        delete target;
    }

    grid[toRow][toCol] = p;
    grid[fromRow][fromCol] = nullptr;

    return true;
}

bool Board::isKingInCheck(Color kingColor) const {
    int kRow = -1, kCol = -1;

    // Find king position
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece* p = grid[r][c];
            if (!p) continue;
            King* k = dynamic_cast<King*>(p);
            if (k && p->getColor() == kingColor) {
                kRow = r;
                kCol = c;
            }
        }
    }
    if (kRow == -1) return false;

    // See if any enemy piece can move to king square
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            Piece* p = grid[r][c];
            if (!p) continue;
            if (p->getColor() == kingColor) continue;

            if (p->canMove(*this, r, c, kRow, kCol)) {
                return true;
            }
        }
    }
    return false;
}
