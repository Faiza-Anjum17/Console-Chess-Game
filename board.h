//#pragma once // Ensures the header file is included only once during compilation
//
//#include "Piece.h" // Allows use of the Piece* type in this file
//
//// The Board class represents the 8x8 chess board and manages all pieces on it
//class Board {
//private:
//    Piece* grid[8][8];      // 2D array of pointers to Piece objects; holds the position of every piece on the board
//
//public:
//    Board();                // Constructor: Initializes the board (e.g., sets all positions to nullptr)
//    ~Board();               // Destructor: Cleans up memory, deletes any dynamically allocated pieces
//
//    void setupInitial();    // Places all chess pieces in their starting positions
//
//    void print() const;     // Outputs a textual representation of the board to the console
//
//    // Returns the Piece pointer at a given row and column (or nullptr if empty)
//    Piece* getPiece(int r, int c) const { return grid[r][c]; }
//    // Assigns a Piece pointer to a board position (used to place/move pieces)
//    void setPiece(int r, int c, Piece* p) { grid[r][c] = p; }
//};
//-------------------------------------default-board------------------------------------------------------------------------------
#pragma once

#include "piece.h"

class Board {
private:
    Piece* grid[8][8];   // 8x8 chess board of Piece pointers

public:
    Board();
    ~Board();

    void setupInitial(); // starting position set
    void print() const;  // console board display

    Piece* getPiece(int r, int c) const { return grid[r][c]; }
    void setPiece(int r, int c, Piece* p) { grid[r][c] = p; }

    bool movePiece(int fromRow, int fromCol, int toRow, int toCol);

    // optional, agar use karni ho:
    bool isKingInCheck(Color kingColor) const;
};

