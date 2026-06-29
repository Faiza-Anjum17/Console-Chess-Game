#pragma once

enum Color { WHITE, BLACK };
class Board;

class Piece {
protected:
    Color color;
    bool killed;

public:
    Piece(Color c);
    virtual ~Piece();

    Color getColor() const { return color; }
    bool isKilled() const { return killed; }
    void setKilled(bool val) { killed = val; }

    virtual bool canMove(const Board& b,
        int fromRow, int fromCol,
        int toRow, int toCol) const = 0;

    virtual char getSymbol() const = 0;
};
