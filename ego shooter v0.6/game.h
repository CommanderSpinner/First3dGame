#pragma once

#include "raylib.h"
#include "Enemy.h"
#include <iostream>

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
    Enemy enemy1;

    void drawTestCube(Vector3 cubePosition, float width, float height, float length);
};
