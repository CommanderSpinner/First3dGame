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

    int cameraMode = CAMERA_FIRST_PERSON;
    // Weitere Spielkomponenten hier hinzufügen
};
