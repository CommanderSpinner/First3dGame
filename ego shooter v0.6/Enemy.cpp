#include "Enemy.h"

Enemy::Enemy(Vector3 startPos) {
    position = startPos;
    // Initialize other properties
}

Enemy::Enemy() {}

void Enemy::Update() {
    // Update logic for the enemy (e.g., movement, AI, etc.)
}

void Enemy::Draw() {
    DrawCube(position, 1.0f, 1.0f, 1.0f, BLUE); // Draw the enemy (blue cube for example)
}
