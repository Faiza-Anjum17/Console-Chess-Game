// Piece.h
#pragma once

enum Color { WHITE, BLACK };
class Board;
class Piece {
protected:
    Color color;
    bool killed;          // Track if piece is captured: true if captured
    int row, col;         // Position info (optional for base)
public:
    Piece(Color c) : color(c), killed(false) {}
    virtual ~Piece() {}

    // Encapsulation: get/set color and killed
    Color getColor() const { return color; }
    void setColor(Color c) { color = c; }

    bool isKilled() const { return killed; }
    void setKilled(bool val) { killed = val; }

    // Abstract: movement rule (pure virtual)
    virtual bool canMove(const Board& Board, int fromRow, int fromCol, int toRow, int toCol) const = 0;

    // For printing; each derived piece returns its own symbol
    virtual char getSymbol() const = 0;
};
