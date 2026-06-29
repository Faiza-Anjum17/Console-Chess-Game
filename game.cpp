#include "Game.h"
#include <iostream>
#include <limits> // For numeric_limits
using namespace std;
Game::Game() {
    board.setupInitial();
}
void Game::run() {
    board.print();
    while (true) {
        int fr, fc, tr, tc;
        cout << "\nEnter move (fromRow fromCol toRow toCol, -1 to exit): ";

        // EXPLANATION: Input validation to prevent infinite loops on bad input.
        if (!(cin >> fr)) {
            cout << "Invalid input. Please enter numbers.\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            continue;
        }

        if (fr == -1) break;
        if (!(cin >> fc >> tr >> tc)) {
            cout << "Invalid input. Please enter all coordinates.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        bool ok = board.movePiece(fr, fc, tr, tc);
        cout << (ok ? "Move OK\n" : "Move FAILED\n");
        board.print();
    }
}
