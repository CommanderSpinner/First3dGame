#pragma once

#include "raylib.h"

class Enemy {
private:
    Vector3 position;
    // Other properties like health, speed, etc.

public:
    Enemy(Vector3 startPos);
    Enemy();
    void Update();
    void Draw();
};
