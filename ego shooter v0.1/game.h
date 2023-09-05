#pragma once

#include "raylib.h"

class Game {
public:
    Game();
    ~Game();

    void Init();
    void Update();
    void Draw();
    void Shutdown();

private:
    Camera3D camera;
    // Weitere Spielkomponenten hier hinzufügen
};
