#include "raylib.h"
#include "game.h"
#include <iostream>

int main(int argc, char* argv[]) {
    int screenWidth = 800; // Standardbreite
    int screenHeight = 600; // Standardh�he

    // �berpr�fen, ob gen�gend Argumente �bergeben wurden
    if (argc >= 3) {
        screenWidth = atoi(argv[1]);
        screenHeight = atoi(argv[2]);
    }
    else {
        std::cout << "Nicht gen�gend Argumente. Verwendung: ./DeinProgramm Breite H�he" << std::endl;
    }

    if (screenWidth <= 0 || screenHeight <= 0) {
        std::cout << "Ung�ltige Fenstergr��e. Verwendung: ./DeinProgramm Breite H�he" << std::endl;
        return 1; // Beende das Programm mit einem Fehlercode
    }

    InitWindow(screenWidth, screenHeight, "Ego Shooter");
    SetTargetFPS(60);

    Game game;
    game.Init();

    while (!WindowShouldClose()) {
        game.Update();
        game.Draw();
    }

    game.Shutdown();
    CloseWindow();

    return 0;
}
