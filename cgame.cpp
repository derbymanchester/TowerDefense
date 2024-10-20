#include "cgame.h"
#include <iostream>
#include <conio.h> 

cgame::cgame() {
    _ISEXIT1 = _ISEXIT2 = false;
    _isPaused = false;
}

void cgame::startGame() {
    system("cls");
    _map.drawMap();
    while (!_ISEXIT1 && !_ISEXIT2) {
        if (_kbhit()) {
            char input = _getch();
            processInput(input);
        }
        if (!_isPaused) {
            updateGame();
        }
    }
}

void cgame::updateGame() {
    // Update game state, e.g., move enemies, check for collisions, etc.
    // For now, we'll just redraw the map
    system("cls");
    _map.drawMap();
}

void cgame::processInput(char input) {
    switch (input) {
    case 'q':
        exitGame();
        break;
    case 'p':
        pauseGame();
        break;
        // Add more cases to handle different inputs
    default:
        break;
    }
}

void cgame::exitGame() {
    _ISEXIT1 = true;
}

void cgame::pauseGame() {
    _isPaused = !_isPaused;
    if (_isPaused) {
        std::cout << "Game Paused. Press 'p' to resume." << std::endl;
    }
}
