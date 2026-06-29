#pragma once
#include "Board.h"
// EXPLANATION: Game class encapsulates the game state and loop.
// This keeps main() clean and allows for easier expansion (e.g., adding a menu, saving game).
class Game {
private:
    Board board;
public:
    Game();
    void run();
};
